#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int m,n=0;
	cin>>m;
	vector<int> A;
	vector<int>::iterator It;
	for(int i=0;i<m;i++){
		cin>>n;
		A.push_back(n);
	}
	auto p=unique(A.begin(),A.end());	
	for(int i=0;i<p-A.begin();i++){
		cout<<A[i]<<" ";
	}cout<<endl;	
}