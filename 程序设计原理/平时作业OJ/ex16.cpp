#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
const double pi=acos(-1);
int main() 
{
	double r,s,c;
	cin>>r;
	double a=3.141592;
	s=pi*r*r;
	c=2*pi*r;
	cout<<fixed<<setprecision(6)<<s<<" "<<fixed<<setprecision(6)<<r;
}