#include <iostream>
#include <algorithm>
#include <string> 
#include <cmath>
using namespace std;
int main()
{
	int m,n;
	cin>>m>>n;
	int a[100][100];
	int b[100][100];
	int i,j,h=0,l=0;
	int max=0;
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			cin>>a[i][j];
			b[i][j]=fabs(a[i][j]);
			if (max < (b[i][j]) )
            {
             max =b[i][j];
             h = i;
             l = j;
            }
		}
	}cout<<h<<" "<<l<<" "<<a[h][l]<<endl;
	return 0;
} 