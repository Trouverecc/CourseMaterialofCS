#include <iostream>
#include<cmath>
using namespace std;
int  hws(int n) //int f(int n)是个自定义的函数，返回值为整数型，形参是n，整数型
{
	int i = n;
	int m = 0;
	while (i > 0) 
	{
		m = i % 10 + m * 10;
		i=i / 10;
	}
	return m;
}
int main() {
	int x = 11;
	do {
		if (x == hws(x) && pow(x, 2) == hws(x * x) && pow(x, 3) == hws(x * x * x))
			cout << x <<  endl;
		x++;
	} while (x <= 999);
	return 0;
}//判断一个数是否为回文数，有多种方法，常见的有三种：
//1.将输入数字转化为字符串。回文数关于中心对称，只需比较对称的数是否相等即可。
//2.采用除10取余的方法，从最低位开始，依次取出该数的各位数字，然后用最低为充当最高位，按反序构成新的数，再与原数比较。
//3.采用栈的方式。判断出栈的元素与栈内字符是否相等。

	
