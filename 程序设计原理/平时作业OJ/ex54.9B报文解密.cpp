//Nice!Come on!
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string x;
	cin>>x;
	for(int i=0;i<x.size();i++)
	{
		if(x[i]=='A'||x[i]=='B'||x[i]=='C'||x[i]=='D')
		{
			x[i]+=22;
		}
		else{
			x[i]-=4;
		}
	}cout<<x<<endl;
}