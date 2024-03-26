#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
double x1,x2,y1,y2;
double r;
while(true)
{cin>>x1>>y1>>x2>>y2;//在循环里就可以连续输入了
if(x1!=0||x2!=0||y1!=0||y2!=0)
{
	double a=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
	r=sqrt(a);//计算在循环里
	cout<<fixed<<setprecision(2)<<r<<endl;	
}
else{break;}    

}
return 0;
}
