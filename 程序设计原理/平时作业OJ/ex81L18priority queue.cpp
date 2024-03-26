#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main(){
	int m,n;
	cin>>m>>n;
	vector<priority_queue<int>> A(m);
	vector<int>::iterator It;
	while(n--){
		int a;
		cin>>a;
		if(a==0){
			int b,c;
			cin>>b>>c;
			A[b].push(c);
		}else
		if(a==1){
			int b;
			cin>>b;
			if(!A[b].empty())
				cout<<A[b].top()<<endl;
			}else
		if(a==2){
			int b;
			cin>>b;
			if(!A[b].empty())
				A[b].pop();	
						
		}
	}
}