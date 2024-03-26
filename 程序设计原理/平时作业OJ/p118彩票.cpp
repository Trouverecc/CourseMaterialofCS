#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{
	srand(time(0));
	string lottery;
	int a=rand()%10;
	lottery=static_cast<char>(a+'0');
	a=rand()%10;
	lottery=static_cast<char>(a+'0');
    string guess;
	cin>>guess;
	cout<<lottery<<endl;
	if(guess==lottery)
	{
	    cout<<"w"<<endl;}
	if(guess[1]==lottery[0]&&guess[0]==lottery[1])
	{
	    cout<<"a"<<endl;}
}