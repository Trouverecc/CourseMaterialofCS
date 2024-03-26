//同ex42回文数
#include <iostream>
using namespace std;
int hws(int n){
	int m=0;
	int i=n;
	while(i>0){
		m=i%10+m*10;
		i/=10;
	}return m; 
}
int main(){
	for(int j=11;j<=999;j++){
		if(j==hws(j)&&j*j==hws(j*j)&&j*j*j==hws(j*j*j)){
			cout<<j<<endl;
			j++;
		}
	}
}
/*extra
#include<bits/stdc++.h>
using namespace std;
string st1;
int main(){
	cin>>st1;
	int len  = st1.length();
	int j=len-1,flag=0;
	for(int i = 0;i < len;i++,j--){
		if(st1[i]!=st1[j]) {
			flag=1;
			break;
		}
	}
	if(!flag) cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	return 0;
}*/
