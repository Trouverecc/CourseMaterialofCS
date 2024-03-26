#include <iostream>
#include <algorithm>
#include <string> 
#include<iomanip>
using namespace std;
int main() 
{
	int n;
	string str,m;
	while(cin>>n)
	{
		n--;
		for(int i=0;i<n;i++)
		{
			cin>>str;
			int max='a';
			if (str[i]>'a')
			{
				max=str[i];
				m=str[i];
			}
		}cout<<m<<endl;
	}
}