#include <iostream>
using namespace std;

int main(){
	long long a[60];
	a[0]=1;
	a[1]=1;
	int m,n;
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>n;
		if(n>2){
			for(int j=2;j<n;j++){
				a[j]=a[j-1]+a[j-2];
			}
		}
		cout<<a[n-1]<<endl;
	}
	return 0;
}