/*#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main()
{
	string line;
	while(getline(cin,line))
	{
	stringstream ss(line);
	int sum=0,x;
    	while(ss>>x)
	     sum+=x;
	cout<<sum<<"\n";
    } 
	return 0;
}*/
#include <iostream>
using namespace std;
void swap01(int num1,int num2)
{
	int temp=num1;
	num1=num2;
	num2=temp;
	cout<<"/a= "<<num1<<endl;
	cout<<"/b= "<<num2<<endl;
}
int main()
{
	int a=1;
	int b=2;
	swap01(a,b);
	cout<<"a= "<<a<<endl;
	cout<<"b= "<<b<<endl;
}