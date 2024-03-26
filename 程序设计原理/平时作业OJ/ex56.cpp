//10-A 账号信息
/*#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n;
	cin>>n;
	char x[1000];
	for(int i=0;i<n;i++)
	{
		cin.getline(x,1000);
		cout<<x[i]<<endl;
	}
}*/
#include <iostream>
#include <string>
using namespace std;
struct account{
	string min,mima;
};
int main()
{
	int n;
	cin>>n;
	while(n>0)
	{
		n--;
		account i;
		cin>>i.min>>i.mima;
		cout<<i.min<<" "<<i.mima<<endl;
	}
	return 0;
}	

