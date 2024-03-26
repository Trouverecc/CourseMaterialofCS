#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
	int x,y;
	cin>>x>>y;
	cout<<x<<" "<<y<<endl;
	int n;
	cin>>n;
	while(n>0){
		
		int a;
		cin>>a;
		if(a=2){
			int p,q;
			cin>>p>>q;
			double d=(p-x)*(p-x)+(y-q)*(y-q);
			double s=sqrt(d);
			cout<<fixed<<setprecision(5)<<s<<endl;
		}
		if(a=3){
			int b=0-x;
			int c=0-y;
			cout<<b<<" "<<c<<endl;
		}
		if(a=4){
			int e,f,r;
			cin>>e>>f>>r;
			if(e-r<x&&e+r>x&&f-r<0&&f+r>y){
				cout<<"Yes"<<endl;
			}else
			{cout<<"No"<<endl;
			}
		}
		n--;
	}
}