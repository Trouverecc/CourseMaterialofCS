#include<iostream>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int A[n][m];
	int b[m];
	int c[n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>A[i][j];
		}c[i]=0;//差这了
	}
	for(int k=0;k<m;k++)
	{
		cin>>b[k];
	}
	for(int l=0;l<n;l++)
	{
		for(int i=0;i<m;i++)
		{
			c[l] +=A[l][i]*b[i];
		}cout<<c[l];
		cout<<endl;
	}
	return 0;	
	
	
}