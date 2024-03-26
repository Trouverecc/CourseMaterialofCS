#include <iostream>
using namespace std;
int main()
{
	int R,Y;
	double M;
	cin>>R>>M>>Y;
	for(int i=0;i<=Y;i++)
	{
		M*=(1+R/100);
	}
	cout<<(int)M;
}