#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	double a,b,C;
	cin>>a>>b>>C;
	const double pi=acos(-1);
	double S=a*b*sin(pi*C/180)/2;
	double h=2*S/a;
	double c= sqrt(a*a+b*b-2*a*b*cos(pi*C/180));
	double L=a+b+c;
	cout<<fixed<<setprecision(8)<<S<<endl;
	cout<<fixed<<setprecision(8)<<L<<endl;
	cout<<fixed<<setprecision(8)<<h<<endl;
}