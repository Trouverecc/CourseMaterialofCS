#include <iostream>
#include <vector>
#include <string>
#include <deque>
using namespace std;
int main(){
	int n;
    cin>>n;
    vector<vector<int>> a(n);//定义嵌套数组
	int b;
	cin>>b;
	while(b--){
		int m;
		cin>>m;
		if(m==0){
			int x,y;
			cin>>x>>y;
			a[x].push_back(y);
		}else if(m==1){
			int p;
			cin>>p;
			while(auto e : a[p]){
				cout<<e<<" ";
			}
			
			cout<<endl;
		}else{
			int q;
			cin>>q;
			a[q].clear();
		}	
	}
}