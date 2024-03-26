#include <iostream>
using namespace std;
int main()
{
	int arr[9]={};
	for(int i=0;i<9;i++)
	{
		cin>>arr[i];
		cout<<arr[i];
	}cout<<endl;
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp=arr[j];
			    arr[j]=arr[j+1];
			    arr[j+1]=temp;
			}
			
		}
	}
	for(int i=1;i<=9;i++)
	{
		cout<<arr[i];
	}cout<<endl;
}