#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
	double a,b,c;
	cin>>a>>b>>c;
	
	a=fabs(a);
	b=fabs(b);
	c=fabs(c);
	cout<<fixed<<setprecision(2)<<a+b+c;
	
}