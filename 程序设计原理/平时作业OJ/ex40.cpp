#include <iostream>
using namespace std;
int main() 
{
	long long x=0,y=0,c,d;
	while(cin>>x>>y)
	{
		if(x==0&&y==0)
		break;
		long long a=max(x,y);
		long long b=min(x,y);
		for(int i=0;i<100;i++)
		{
			c=a%b;
			d=a/b;
			a=b;
			b=c;
			if(c==0)
			break;
		}cout<<a<<endl;
	}
	return 0;
}
/*#include <iostream>
using namespace std;
int main() 
{
   long long a,b,tmp;
   while(true)
   {
   	   cin>>a>>b;
   	   if(b!=0)
	   {
	   	   while(tmp=a%b)
   {
       if(a!=0||b!=0)
	   a=b;
       b=tmp;  
   }
   cout<<b<<endl;
	   }
	   while(a==0&&b==0)
	   break;
   }
   return 0;
}*/
