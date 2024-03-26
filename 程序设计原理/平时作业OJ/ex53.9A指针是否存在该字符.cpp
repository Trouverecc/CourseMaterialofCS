/*不太对 我 指针#include <iostream>
#include <string>
using namespace std;
int main()
{
	char c;
    char str[10000]={};
    cin>>c;
    cin>>str[10000];
    int a=0;
    for(int i=1;i<=100;i++)
    {
	    cin>>*(str+i);
	    if(*(str+i)==c)
	    cout<<"yes"<<endl;
	    a=1;
	    break;
	}
    if(a!=1)
    cout<<"no"<<endl;
}*/
/*#include <iostream>
using namespace std;
char* search(char*str,char c)
{
	for(int i=0;i<100;i++)
	{
		if(*str==c){cout<<"yes";return str;	}
		*++str;
	}cout<<"no";
}
int main()
{
	char a[101],x;
	cin>>a;
	char*pa=a;
	cin>>x;
	search(pa,x);
	return 0;
}*/
/*#include <iostream>
#include <string>
using namespace std;
int main()
{
    string x;
	char b;
	cin>>x>>b;
	int a=0;
	for(int i=0;i<x.size();i++)
	{
		if(x[i]==b) 
		{
		cout<<"yes"<<endl;
		a=1;
		break;
		}
	}
	if(a!=1)
	cout<<"no"<<endl;
	
}*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string x;
	char b;
	cin>>x>>b;
	for(int i=0;i<x.size();i++)
	{
		if(x[i]==b) 
		{
		cout<<"yes"<<endl;
		return x;	
		break;
		}
		else cout<<"no"<<endl;
	}
}