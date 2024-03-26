#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int b,f,r,v;
	int house[4][3][10]={0};
	for(int i=0;i<n;i++)
	{
		cin>>b>>f>>r>>v;
		house[b-1][f-1][r-1]+=v;
		
	}
	for(int j=0;j<4;j++)
		{
			for(int k=0;k<3;k++)
			{
				for(int l=0;l<10;l++)
				{
					cout<<" "<<house[j][k][l];
				}cout<<endl;
			}if(j  !=3)
			cout<<"####################"<<endl;
		}
	return 0;
	
}