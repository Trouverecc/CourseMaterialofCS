#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		if(i%3==0)
		{
			cout<<" "<<i;continue;
		}
		do
		{
			if(i%10==3)
		{
			cout<<" "<<i;
		}
		i/=10;
		}while(i);
	}
}
