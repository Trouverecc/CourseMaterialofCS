#include <iostream>
#include <cmath>
#include <mpi.h>
#include <omp.h> // 确保包含了OpenMP头文件

using namespace std;
int num_thread; // 每个进程的线程数
// 矩阵乘法
void matrixMultiply(const int* A, const int* B, int* result, int m, int n, int p) {
    for (int i = 0; i < m; ++i) {
        #pragma omp parallel for num_threads(num_thread)
        for (int j = 0; j < n; ++j) {
            result[i * n + j] = 0;
            for (int k = 0; k < p; ++k) {
                result[i * n + j] += A[i * p + k] * B[k * n + j];
            }
        }
    }
}

// 矩阵幂运算
void matrixPower(const int start_row, const int end_row, const int* matrix, const int N, const int power, int* local_result) {
    // 开始进行矩阵幂运算
    for(int i = 0; i < (end_row - start_row); i++){
        for (int j = 0; j < N; j++) {
            local_result[i * N + j] = matrix[(start_row + i) * N + j];
        }
    }
    int* temp_result = new int[(end_row - start_row) * N];

    for(int i = 1; i < power; i++){
        matrixMultiply(local_result, matrix, temp_result, (end_row - start_row), N, N);
        // 将临时结果复制到 local_result 中
        for (int j = 0; j < (end_row - start_row) * N; j++) {
            local_result[j] = temp_result[j];
        }
    }

    delete[] temp_result;
}

int main(int argc, char *argv[]) {
    // 初始化MPI环境
    MPI_Init(&argc, &argv);

    // 获取当前的进程编号与进程总数
    int rank, size;
    // int num_thread; // 每个进程的线程数

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // 本实验设定测试数据，设定矩阵规模为16*16
    const int N = 16;
    // 定义计算矩阵幂的次数为5
    const int power = 5;
    // 定义本程序的全局矩阵，且仅能在根进程中被初始化
    int matrix[N][N];
    
    // 在根进程中初始化全局矩阵，生成随机矩阵
    if (rank == 0) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                matrix[i][j] = rand() % 10 + 1;
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    // 将全局矩阵广播到所有进程
    MPI_Bcast(&matrix[0][0], N * N, MPI_INT, 0, MPI_COMM_WORLD);

    // 设置每个进程的线程数，这里以OpenMP的最大线程数为准
    num_thread = omp_get_max_threads();

    // 将矩阵按行分配给各个进程，实现分块计算以提高运行效率
    // 首先定义好每个进程分得的矩阵的起始与终点行数
    int rows_per_process = N / size;
    int start_row = rank * rows_per_process;
    int end_row = (rank + 1) * rows_per_process;
    if (rank == size - 1)  end_row = N; // 最后一个进程需要单独定义

    
    // 在本地计算分块后矩阵的矩阵幂
    int local_result[(end_row - start_row) * N];
    matrixPower(start_row, end_row, &matrix[0][0], N, power, local_result);


    // 发送每个进程的局部矩阵幂计算结果到根进程
    if (rank != 0) {
        MPI_Send(&local_result[0], (end_row - start_row) * N, MPI_INT, 0, 0, MPI_COMM_WORLD);
    } 
    else {
        // 根进程接收每个进程的局部结果，并存储在结果矩阵中
        int result[N][N];
        for (int i = 0; i < (end_row - start_row); i++) {
            for (int j = 0; j < N; ++j) {
                result[start_row + i][j] = local_result[i * N + j];
            }
        }

        // 接收其他进程的局部结果
        for (int source = 1; source < size; ++source) {
            int start_row1 = source * rows_per_process;
            int end_row1 = (source + 1) * rows_per_process;
            if (source == size - 1)  end_row1 = N;

            int recv_buffer[(end_row1 - start_row1) * N];
            MPI_Recv(&recv_buffer[0], (end_row1 - start_row1) * N, MPI_INT, source, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            for (int i = 0; i < (end_row1 - start_row1); ++i) {
                for (int j = 0; j < N; ++j) {
                    result[start_row1 + i][j] = recv_buffer[i * N + j];
                }
            }
        }

        // 打印结果矩阵
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    // 注意要结束MPI环境
    MPI_Finalize();
    return 0;
}

// module load openmpi/4.1.4-mpi-x-gcc9.3.0
// mpic++ -fopenmp -o test4.o test4.cpp
// time yhrun -p thcp1 -N 2 -n 2 -c 4 test4.o &> run.log