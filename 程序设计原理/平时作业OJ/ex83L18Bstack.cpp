#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main(){
	int a,b;
	cin>>a>>b;
	vector<stack<int>>v1(a);
	while(b--){
		int m,n;
		cin>>m>>n;
		if(m==0){
			int x;
			cin>>x;
			v1[n].push(x);
		}
		if(m==1){
			if(!v1[n].empty())
			cout<<v1[n].top()<<endl;
		}
		if(m==2){
			if(!v1[n].empty())
			v1[n].pop();
		}
	}
}