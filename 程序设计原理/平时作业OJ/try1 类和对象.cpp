#include <iostream>
using namespace std;
const double pi=3.14;
class circle
{
	public:
	int r;
	double calculateC()
	{
		return 2*pi*r;
	}
};
int main()
{
	circle a1;
	a1.r=10;
	cout <<"C= "<<a1.calculateC()<<endl;
	return 0;
}