/*#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	while(n--){
		char a[501];
		for(int i=0;i<)
		cin>>a;
		;
		long long b=c*c;
		cout<<b<<endl;
	}
}*/
#include<bits/stdc++.h>
using namespace std;
struct node{int len,fa,s[26];}a[200005];//SAM结构体
int n,lst=1,cnt=1;char s[100005];long long ans[200005];//ans就是dp数组
inline void ins(int c)
{//经典的后缀自动机的加点过程。
	int p=lst,np=lst=++cnt;a[np].len=a[p].len+1;
	for(;p&&!a[p].s[c];p=a[p].fa) a[p].s[c]=np;
	if(!p) return(void)(a[np].fa=1);
	int q=a[p].s[c];
	if(a[q].len==a[p].len+1) return(void)(a[np].fa=q);
	int nq=++cnt;a[nq]=a[q],a[nq].len=a[p].len+1,a[q].fa=a[np].fa=nq;
	for(;p&&a[p].s[c]==q;p=a[p].fa) a[p].s[c]=nq;
}
inline long long dfs(int x)
{//在SAM上跑dfs
	if(ans[x]) return ans[x];
	for(int i=0;i<26;i++) if(a[x].s[i]) ans[x]+=dfs(a[x].s[i])+1;
	return ans[x];
}
int main()
{
	int m;
	cin>>m;
	while(m--)
	cin>>n;
	scanf("%s",s+1),memset(ans,0,sizeof(ans));
	for(int i=1;i<=n;i++) ins(s[i]-'a');
	return printf("%lld\n",dfs(1)),0;
}