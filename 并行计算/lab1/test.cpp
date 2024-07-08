/*#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

int NUM_THREADS=4;

// 定义共享变量和互斥锁
double sum = 0.0;
double x=0.0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// 线程运行的函数
void *thread_func(void *arg) {
    int tid = *(int *)arg;
    double factor, my_sum = 0.0;
    int i,j,k;
	int a=1;
    
    for (i = tid; i < 1000000; i += NUM_THREADS) {
        factor = (i % 2 == 0) ? 1.0 : -1.0;
		for(j=1;j<=2*i-1;j++){
            a=a*j;
		}
        for(k=1;k<=i;k++){
            x*=x;
        }
        my_sum += (factor * x) / a;
    }

    // 加锁
    pthread_mutex_lock(&mutex);
    sum += my_sum;
    // 解锁
    pthread_mutex_unlock(&mutex);

    // 退出线程
    pthread_exit(NULL);
    return NULL;
}

int main(int argc, char* argv[]) {
    
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];
    int t;
    
    // 创建线程
    for (t = 0; t < NUM_THREADS; t++) {
        thread_args[t] = t;
        pthread_create(&threads[t], NULL, thread_func, (void *)&thread_args[t]);
    }

    // 等待线程结束
    for (t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }

    // 输出值
    //scanf("%lf", &x);
    printf("sin = %.16f\n", sum);

    // 销毁互斥锁
    pthread_mutex_destroy(&mutex);

    // 退出程序
    pthread_exit(NULL);
}*/
//g++ -pthread -o test.o test.cpp
//yhrun -p thcp1 -n 1 -c 8 ./test.o 1 8 2
//time yhrun -p thcp1 -n 1 -c 8 ./cal_sin.o 1 8 2



#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

double res;

typedef struct Args {
    float radian;
	long max_n;
	long begin;
	long step;
} Args;

void *cal(void *arg);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Parameters error: radian N threads!\n");
        exit(1);
    }

	long i;
    double radian = atof(argv[1]);
	//
    //max_n=100000000;//
    long max_n = atol(argv[2]);
	int threads = atoi(argv[3]);
	Args *arg;
	double* val;

	pthread_t *pid;
	pid = (pthread_t *)malloc(threads * sizeof(pthread_t));
	
	res = 0.0;
	for (i = 0; i < threads; i++) {
		arg = (Args *)malloc(sizeof(Args));
        arg->radian = radian;
		arg->max_n = max_n;
		arg->begin = i;
		arg->step = threads;
		pthread_create(&pid[i], NULL, cal, (void *)arg);
	}
	for (i = 0; i < threads; i++) {
		pthread_join(pid[i], NULL);
	}
	printf("sin = %lf\n", res);
	free(pid);
	return 0;
}

void *cal(void *_arg) {
	long i, j;
	double val, tmp;
	Args *arg = (Args *)_arg;
	
	val = 0.0;
	for (i = arg->begin; i <= arg->max_n; i += arg->step) {
        tmp = 1.0;
		for (j = 1; j <= 2*i+1; j++) {
            tmp *= arg->radian / j;
        }
        if (i % 2 > 0) {
            val -= tmp;
        } else {
            val += tmp;
        }
	}
	res += val;
	return NULL;
}

