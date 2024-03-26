#include <iostream>
#define endl '\n'
#define LL long long
#define L unsigned long long
#define l unsigned int
using namespace std;
int prime[10000010];
int visit[10000010];
LL work(int n){
	visit[1]=1;
	for(int i=2;i<=n;i++){
		if(!visit[i])
		    prime[++prime[0]]=i;
	    for(int j=1;j<=prime[0]&&i*prime[j]<=n;j++){
	    	visit[i*prime[j]]=1;
	    	if(i%prime[j]==0)
	    	    break;
		}
		continue;
	}
	LL sum=0;
	for(int i=1;i<=n;i++){
		if(!visit[i])
		    sum+=i;  
	}return sum;
}
int main(){
	LL n;
	cin>>n;
	cout<<work(n)<<endl;
}
