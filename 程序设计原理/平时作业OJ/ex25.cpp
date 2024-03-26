#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
	int n;
	double r;
    const double PI=acos(-1);
    cin >> n;
    while(n>0)
    {
        n--;
		cin>>r;
		double v;
		v=4.0/3*PI*r*r*r;
		cout<<fixed<<setprecision(3)<<v<<endl;
	}
}