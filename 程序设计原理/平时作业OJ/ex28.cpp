#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n>0)
	{
		n--;
		int s;
		cin>>s;
		if(s>=90&&s<=100)
		{
			cout<<"A"<<endl;
		}
		if(s>=80&&s<90)
		{
			cout<<"B"<<endl;
		}
		if(s>=70&&s<80)
		{
			cout<<"C"<<endl;
		}
		if(s>=60&&s<70)
		{
			cout<<"D"<<endl;
		}
		if(s>=0&&s<=59)
		{
			cout<<"E"<<endl;
		}
		if(s<0||s>100)
		{
			cout<<"Score is error!"<<endl;
		}
		
	}
}