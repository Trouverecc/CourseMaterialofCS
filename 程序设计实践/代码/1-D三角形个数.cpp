#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int c=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				if(a[i]+a[j]>a[k]&&a[k]+a[j]>a[i]&&a[i]+a[k]>a[j]){
					c++;
				}
			}
		}
	}
	cout<<c<<endl;
}