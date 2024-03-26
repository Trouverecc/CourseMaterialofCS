#include<iostream>
using namespace std;
int main()
{
    char a,b,c;
    while(true)
    {
        cin>>a>>b>>c;
        if(a!='0'||b!= ' 0'||c!='0')
        {
        	if(a>b)
		 {
		    if(c<b){cout<<c<<" "<<b<<" "<<a<<endl;}else
		    if(c>a){cout<<b<<" "<<a<<" "<<c<<endl;}else
		    {cout<<b<<" "<<c<<" "<<a<<endl;}
		 }
            if(a<b)
         {
            if(c<a){cout<<c<<" "<<a<<" "<<b<<endl;}else
            if(c>b){cout<<a<<" "<<b<<" "<<c<<endl;}else
            {cout<<a<<" "<<c<<" "<<b<<endl;}
		 }
		}if(a== '0'&&b== '0'&&c== '0'){break;
		}
    }
    return 0;
}
//ASCII码0不等于0 得加单引号
