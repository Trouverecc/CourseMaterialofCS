/*题目描述
给你n个整数，求他们中所有奇数的乘积。
输入
输入数据包含多个测试实例，第一行输入一个T代表测试数据组数。
每个测试实例占一行，每行的第一个数为n，表示本组数据一共有n个，接着是n个整数，你可以假设每组数据必定至少存在一个奇数。
输出
输出每组数中的所有奇数的乘积，对于测试实例，输出一行*/
//Mine
#include <iostream>
using namespace std;
int main()
{
	int T;
	while(cin>>T)
	{
	    T--;
		int n;
	while(cin>>n)
	{
		int a;
		int number = 1;
		while (n--)
		{
			cin >> a;
			if (a % 2 != 0)    
				number *= a;
		}
		cout << number << endl;
	}
	
	return 0;
	}
}
//key2
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
 int T;
 cin >> T;
 while (T > 0) {
  T--;
  int n;
  long s = 1;
  cin >> n;
  while (n > 0) {
   n--;
   int a;
   cin >> a;
   if (a % 2 == 1)
    s = s * a;
  }
  cout << s << endl;
 }
 return 0;
}