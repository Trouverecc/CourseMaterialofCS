#include <iostream>
using namespace std;
int add(int num1,int num2)
{   //函数定义时，num1,num2没真实数据，只是形式上的参数（形参）
	int sum=num1+num2;
	return sum;
}
int main()
{
	//main函数调用add函数
	int a=10;
	int b=20;//a,b实际参数
	int c=add(a,b);//算出结果赋给c
	cout<<"c="<<c<<endl;
	//调用函数时，实参值赋给形参
}