#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
	string name;
    int hp;
    int x;
    int y;
	int t;
	int x0=0,y0=0,nl=30,time=0;
	cin>>t;
	int n=t;
	while(t>0){
		cin>>name>>hp>>x>>y;
	    time+=floor(sqrt((x-x0)*(x-x0)+(y-y0)*(y-y0)));
	    x0=x;
	    y0=y;
	    if(n==t+3) nl=40;
	    if(n==t+8) nl=55;
	    while(hp>0){
	    	hp-=nl;
	    	time++;
		}
		t--;
	}cout<<time<<endl;
}