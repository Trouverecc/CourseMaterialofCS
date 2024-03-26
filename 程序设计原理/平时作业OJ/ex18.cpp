#include <iostream>
using namespace std;
int main()
{
	long int n,sum=0,min,max,a;
	cin>>n>>a;
	min=a;max=a;
	for(int i=1;i<n;i++)
	{
		sum=sum+a;
		if(a>max) max=a;
		if(a<min) min=a;
		cin>>a;
	}
	sum=sum+a;
    if(a>max) max=a;
    if(a<min) min=a;
    cout<<min<<" "<<max<<" "<<sum;
    return 0;
	
}