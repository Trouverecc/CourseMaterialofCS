//似乎解决了课堂练习10A账号信息
#include <iostream>
using namespace std;
struct a{
		string name,id;
	};
class student{
	public:
};
int main()
	{
		int n;
		cin>>n;
		while(n>0)
		{
			a i;
			cin>>i.name>>i.id;
			cout<<i.name<<" "<<i.id<<endl;
			n--;
		}return 0;
	}