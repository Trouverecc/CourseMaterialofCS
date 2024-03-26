#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
	int n;
	double x[110], y[110];
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>x[i];
	for(int i=1; i<=n; i++)
		cin>>y[i];
	double a1 = 0;
	for(int i=1; i<=n; i++) 
		a1 += abs(x[i]-y[i]);
	cout<<fixed<<setprecision(6)<<a1<<endl;
	double a2 = 0;
	for(int i=1; i<=n; i++) 
		a2 += (x[i]-y[i])*(x[i]-y[i]);
	a2 = sqrt(a2);
	cout<<fixed<<setprecision(6)<<a2<<endl;
	double a3 = 0;
	for(int i=1; i<=n; i++) 
		a3 += abs((x[i]-y[i])*(x[i]-y[i])*(x[i]-y[i]));
	a3 = pow(a3, 1.0/3);
	cout<<fixed<<setprecision(6)<<a3<< endl;
	double a4 = 0;
	for(int i=1; i<=n; i++)
		a4 = max(a4, abs(x[i]-y[i]));
	cout <<fixed<<setprecision(6)<<a4<<endl;
	return 0;
}