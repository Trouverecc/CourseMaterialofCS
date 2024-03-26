#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
int main(){
	int m,n;
	cin>>m>>n;
	vector<list<int>> A(m);
	list<int>::iterator It;
	while(n--){
		int a;
		cin>>a;
		if(a==0){
			int b,c;
			cin>>b>>c;
			A[b].insert(A[b].end(),c);
		}else
		if(a==1){
			int b;
			cin>>b;
			for(auto e:A[b])
			cout<<e<<" ";
			cout<<endl;
			}else
		if(a==2){
			int c,d;
			cin>>c>>d;
			A[d].splice(A[d].end(),A[c]);
						
		}
	}
}