#include <bits/stdc++.h>
using namespace std;
int main(){
	int m;
	cin>>m;
	int a[5001];
	while(m--){
		int n=0;
		cin>>n;
		memset(a,0,sizeof(a));
		int num=n;
		int k=2;
		while(num>3){
			int c=0;
			for(int i=1;i<=n;i++){
				if(!a[i]){
					c++;
					if(c==k){
						c=0;
						a[i]=1;
						num--;
					}
				}
			}
			k=(k==2?3:2);
		}
		for(int i=1;i<=n;i++){
			if(!a[i]&&i==1){
				cout<<"1"<<" ";
				continue;
			}
			if(!a[i])
			    cout<<i<<" ";
		}
		cout<<endl;
	}
	return 0;
}