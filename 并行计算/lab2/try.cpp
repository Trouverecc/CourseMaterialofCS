#include<stdio.h>   
#include<time.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<memory.h>
#include<iostream>

using namespace std;

int Power;
int N;
int **matrixA,**matrixB,**result;


void *func(void *arg);
 
int NUM_THREADS; //线程数
pthread_t *tids;  //线程
int L;                       //每个线程计算的块大小

void makeRandomMatrix_A()  //生成矩阵
{
	srand(time(NULL));
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			matrixA[i][j] = matrixB[i][j] = rand() % 10 + 1;
            cout<<matrixA[i][j]<<" ";
		}
        cout<<endl;
	}
}



//子线程函数 
void *func(void *arg)                                  
{
	int s=*(int *)arg;      //接收传入的参数（此线程从哪一行开始计算）
	int t=s+L;              //线程算到哪一行为止
	for(int i=s;i<t;i++)                                 
		for(int j=0;j<N;j++)
			for(int k=0;k<N;k++)
				result[i][j]+=matrixA[i][k]*matrixB[k][j];                               
}

//串多线程函数
void fp(){                              
	int i;
	int j = 0;    
	int t[NUM_THREADS];   //传参索引
	L = N / NUM_THREADS;  //按设置的线程数分配工作块（单个线程所要计算的行数L）

	for(i=0;i<N;i+=L)
	{
		t[j] = i;
		if (pthread_create(&tids[j], NULL, func, (void *)&(t[j]))) //产生线程，去完成矩阵相乘的部分工作量
		{
			perror("pthread_create");
			exit(1);
		}
		j++;
	} 

	for(i=0;i<NUM_THREADS;i++)
		pthread_join(tids[i],NULL); //等所有的子线程计算结束

    
}


int main(int argc,char *argv[])
{
	Power=atoi(argv[1]);//第一个参数传幂次
	N=atoi(argv[2]);//第二个参数传矩阵行数和列数
	NUM_THREADS=atoi(argv[3]);//第三个参数传线程数
	cout<<"Power="<<Power<<endl;
	printf("MN(%d*%d)...\n",N,N);
	//动态分配
	matrixA=new int* [N];
	matrixB=new int* [N];
	result=new int* [N];	
	for(int i=0;i<N;i++)
	{
		matrixA[i]=new int[N];
		matrixB[i]=new int[N];
		result[i]=new int[N];
	}
	tids=new pthread_t [NUM_THREADS];
	makeRandomMatrix_A();       //用随机数产生待相乘的矩阵，并存入文件中
	//从文件中读出数据赋给matrixA
	printf("Makeing matrix(%d*%d)...\n",N,N);



	//多线程计算
	clock_t start1=clock();     //开始计时

	for(int i=1;i<=Power-2;i++)
	{
		fp();    //多线程
		for(int j=0;j<N;j++)
		{
			for(int k=0;k<N;k++)
			{
				matrixA[j][k]=result[j][k];
				result[j][k]=0;
			}

		}
		//makeRandomMatrix_B();

	}
	fp();	
	clock_t finish1=clock();    //结束计算
	printf("%d threads --- Running time=%f s\n", NUM_THREADS,(double)(finish1 - start1) / CLOCKS_PER_SEC);    

	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
    pthread_exit(NULL);
	return 0;
}
