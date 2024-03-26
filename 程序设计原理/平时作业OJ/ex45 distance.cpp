#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
	double x1,x2,y1,y2,r;
	cin>>x1>>y1>>x2>>y2;
	double a=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
	r=sqrt(a);
	cout<<fixed<<setprecision(4)<<r<<endl;
}