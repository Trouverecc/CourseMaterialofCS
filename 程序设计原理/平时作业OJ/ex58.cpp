//11A二维点类
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
class stastics{
	public:
};
int a2(int p,int q,int e,int f){
	double r=(p-e)*(p-e)+(q-f)*(q-f);
	return sqrt(r);
}
int a3(int a,int b){
	return 0-a,0-b;
}
int main()
{
	int x,y;
	cin>>x>>y;
	cout<<x<<" "<<y;
	int n;
	cin>>n;
	while (n>0){
		n--;
		int c;
		cin>>c;
		
		if(c=2){
			int g,h,i,j;
			cin>>g>>h>>i>>j;
			cout<<a2(g,h,i,j)<<endl;
			return 0;
		}
		if(c=3){
			cout<<a3(x,y)<<endl;
			return 0;
		}
		if(c=4){
			int e,f,r;
			cin>>e>>f>>r;
			if(e-r<x&&e+r>x&&f-r<0&&f+r>y){
				cout<<"Yes"<<endl;
			}else
			{cout<<"No"<<endl;
			}
		}
	}
}