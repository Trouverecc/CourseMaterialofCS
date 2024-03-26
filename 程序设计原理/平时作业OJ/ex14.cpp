#include <iostream>
using namespace std;
int main()
{	int a,b,c,i;
	int count=0;
	cin>>a>>b>>c;
	while(a<=b)
	{
		if(c%i==0&&i!=0)
		{
			if(i>=a&&i<=b)
			{
				count++;
			}
			cout<<count<<endl;
		}
	while(a>=b)
	{
		if(c%i==0&&i!=0)
		{
			if(i>=b&&i<=a)
			{
				count++;
			}
			cout<<count<<endl;
		}	
		
	}
}return 0;

