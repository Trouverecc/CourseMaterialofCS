/*#include <iostream>
using namespace std;
long long hs(int n){
	if(n==1) return 1;
	else return 2*hs(n-1)+1;
}
int main(){
	int t;
	cin>>t;
	while(t>0){
		int n;
		cin>>n;
		cout<<hs(n)<<endl;
		t--;
	}return 0;
}*/
//mymethod2
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
	long long t;
	cin>>t;
	while(t>0){
		long long n;
		cin>>n;
		long long ans=pow(2,n)-1;
		printf("%lld\n",ans);
		t--;
	}
}