#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n>0)
	{
		n--;
		double a;
		cin>>a;
		a=fabs(a);
		cout<<fixed<<setprecision(2)<<a<<endl;
	}
}