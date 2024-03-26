#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double a;
	cin>>a;
	double f=(double)a/12;
	double s=f*f*6;
	double v=f*f*f;
	cout<<fixed<<setprecision(2)<<s<<" "<<v;
}