#include <iostream>
#include <iomanip>
using namespace std;
int main()
{int a,b;
cin>>a>>b;
int d=a/b;
int r=a%b;
double f=(double)a/(double)b;
cout <<d<<" "<<r<<" "<<fixed<<setprecision(5)<<f<<endl;
return 0;}





