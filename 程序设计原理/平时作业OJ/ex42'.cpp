#include <iostream>
#include<string>
using namespace std;
int main()
{
	for(int i=11;i<=1000;i++)
	{
	long a=i*i;
	long b=i*i*i;
	if(i<100)
	{
		string i=static_cast<string>(i);
		
		if((i[0]=i[1])&&(a[0]==a[3]&&a[1]==a[2])&&(b[0]==b[6]&&b[1]==b[5]&&b[2]==b[4]))
		cout<<i<<endl;
	}
	else{
		i=static_cast<string>(i);
	}
	}
}