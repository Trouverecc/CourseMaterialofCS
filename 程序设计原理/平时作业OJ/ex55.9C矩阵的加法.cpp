#include<iostream>
#include <cmath>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[1000];
	int b[1000];
	int c[1000];
	for(int i=0;i<n*n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n*n;i++)
	{
	    cin>>b[i];
	}
    for(int j=0;j<n*n;j++)
	{
		c[j]=a[j]+b[j];
		cout<<c[j]<<" ";
		if((j+1)%n==0)
		cout<<endl;
	}
}