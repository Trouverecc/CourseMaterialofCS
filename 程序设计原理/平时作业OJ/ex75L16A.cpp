#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> A;
#define endl '\n'//whitespace
int main(){
	ios::sync_with_stdio(false);//accelerate
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin>>n;
	while(n--){
		int m;
		cin>>m;
		if(m==0){
			int x;
			cin>>x;
			A.push_back(x);
		}else if(m==1){
			int p;
			cin>>p;
			if(A.empty())continue;
			cout<<A[p]<<endl;
		}else{
			if(A.empty())continue;
			A.pop_back();//delete the last element
		}
		
	}
}