#include <iostream>
using namespace std;
int main()
{
	int w,h;
	while((cin>>w>>h)&&(w!=0&&h!=0))
	{
		for(int i=0;i<w;i++)
		{
			for(int j=0;j<h;j++)
			{
				if((i+j)%2==0)
				cout<<"#";
				else
				cout<<".";
			}
			cout<<endl;
		}cout<<endl;
	}
}