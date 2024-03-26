#include <iostream>
using namespace std;
long power(long x, int n) 
{
    long val = 1.0;
    while (n--) val *= x;
    return val;
}
int main() 
{
long long a,b;
while(cin>>a>>b)
{
	if(a!=-1&&b!=-1)
	cout << power(a, b) << endl;
	else break;//咋都得有break,只条件不行
}
return 0;
}