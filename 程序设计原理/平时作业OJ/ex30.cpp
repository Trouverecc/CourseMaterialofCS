//噫好我中了
//1、+=
//2、int T;
//    cin >> T;
//   while (T > 0)
//   {
//    	T--;}
//3、long int
#include<iostream>
using namespace std;
int main() 
{
	int T;
    cin >> T;
    while (T > 0)
    {
    	T--;
    	int m,n;
    	while(true)
    	{
    		cin>>m>>n;
    		long int b=0;
    		long int c=0;
    		for(int i=m;i<=n;i++)
    		{
    			
				if(i%2==0)
    			{
    			    b+=i*i;
				}
				if(i%2==1)
				{
				    c+=i*i*i;
				}
			}cout<<b<<" "<<c<<endl;
		}
	}
}