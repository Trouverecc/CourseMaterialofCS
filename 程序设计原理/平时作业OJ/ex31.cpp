/*题目描述
统计给定的n个数中，负数、零和正数的个数。
输入
输入数据有多组，每组占一行，每行的第一个数是整数n（n<100），表示需要统计的数值的个数，
然后是n个实数；如果n=0，则表示输入结束，该行不做处理。
输出
对于每组输入数据，输出一行a,b和c，分别表示给定的数据中负数、零和正数的个数。*/
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
 int n;
 cin >> n;
 while (n != 0) {
  double a=0, b=0, c=0;
  int i = n;
  while (i > 0)
  {
   i--;
   double e;
   cin >> e;
   if (e < 0)
    a++;
   if (e == 0)
    b++;
   if (e > 0)
    c++;
  }
  cout << a << " " << b << " " << c << endl;
  cin >> n;
 }
 return 0;
}