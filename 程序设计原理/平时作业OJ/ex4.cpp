#include <iostream>
using namespace std;
int main()
{int S,h,m,s;
cin>>S;
h=S/3600;
m=S/60%60;
s=S%60;
cout <<h<<":"<<m<<":"<<s<<endl;
}