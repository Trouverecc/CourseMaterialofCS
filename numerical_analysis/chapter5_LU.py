import random
import time


# 生成随机矩阵（值位于0～100的整数）
def generate_matrix(n):
    return [[random.randint(0, 100) for _ in range(n)] for _ in range(n)]


# 生成随机向量（值位于0～100）
def generate_vector(n):
    return [[random.randint(0, 100)] for _ in range(n)]


# LU分解法
def solve(A, b):
    n = len(A)
    # 初始化L和U矩阵
    L = [[0] * n for _ in range(n)]
    U = [[0] * n for _ in range(n)]

    # LU分解
    for i in range(n):
        # 计算U的第i行
        for j in range(i, n):
            U[i][j] = A[i][j] - sum(L[i][k] * U[k][j] for k in range(i))

        # 计算L的第i列
        for j in range(i, n):
            if U[i][i] == 0:
                raise ValueError("零主元，无法继续分解")
            L[j][i] = (A[j][i] - sum(L[j][k] * U[k][i] for k in range(i))) / U[i][i]

    # 前向替代求解Ly=b
    y = [0] * n
    for i in range(n):
        y[i] = (b[i][0] - sum(L[i][j] * y[j] for j in range(i))) / L[i][i]

    # 后向替代求解Ux=y
    x = [0] * n
    for i in range(n - 1, -1, -1):
        x[i] = (y[i] - sum(U[i][j] * x[j] for j in range(i + 1, n))) / U[i][i]

    return L, U, x


if __name__ == "__main__":
    # 使用给定的特定矩阵和向量
    A = [
        [30, 33, -43, -11, -38, -29, 37, 28, 23],
        [-480, -523, 644, 128, 621, 480, -618, -489, -329],
        [60, 266, -1862, -1991, 464, 546, -968, -1567, 1652],
        [540, 624, -782, 299, 493, 123, 567, 5, -122],
        [-450, -675, 2245, 2326, -1512, 1230, -822, 129, -189],
        [-300, -120, -1114, -1295, -1946, -302, -376, -1540, -609],
        [1080, 998, 508, 2460, 1628, 1358, 2896, 2828, 2002],
        [-1080, -1408, 3340, 2267, 21, -1202, 866, -2690, -1351],
        [-300, -435, 1594, 1685, 340, 2279, -27, 2917, -2336],
    ]
    b = [[188], [-3145], [-4994], [680], [7845], [1876], [9712], [-11599], [10127]]

    # 使用特定矩阵执行LU分解
    L, U, x = solve(A, b)

    print("\n特定矩阵的LU分解结果")
    print("L 矩阵：")
    for row in L:
        print(["{:.2f}".format(val) for val in row])

    print("\nU 矩阵：")
    for row in U:
        print(["{:.2f}".format(val) for val in row])

    print("\n方程Ax=b的解向量x*：")
    print(["{:.2f}".format(val) for val in x])

    # 设置矩阵维数
    n = 20

    # 生成随机矩阵和向量
    A = generate_matrix(n)
    b = generate_vector(n)

    # 计时
    start = time.time()

    # 计算LU分解
    L, U, x = solve(A, b)

    end = time.time()

    # 输出结果，保留两位小数
    print("随机生成n阶方阵的结果")
    print("L 矩阵：")
    for row in L:
        print(["{:.2f}".format(val) for val in row])

    print("\nU 矩阵：")
    for row in U:
        print(["{:.2f}".format(val) for val in row])

    print("\n方程Ax=b的解向量x*：")
    print(["{:.2f}".format(val) for val in x])
    print("\n程序运行时间：", end - start)

