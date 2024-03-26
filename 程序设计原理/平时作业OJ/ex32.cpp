//why
#include<iostream>
using namespace std;
int main()
{
	char a={
	{'A','B','C'},
	{'B','B','C'}
	};
	char keys[]={'B','B','C'};
	for(int i=0;i<2;i++)
	{
		int count=0;
		for(int j=0;j<3;j++)
		{
			if(arr[i][j]=keys[j])
			{
				count ++;
			}
		}cout<<i<<count;
	cout<<endl;
	}
	return 0;
}