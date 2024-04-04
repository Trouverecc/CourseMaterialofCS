#include <iostream>
using namespace std;
/*void init(int a[]) { // 传入数组
    string b;
    cin >> b; 
    int len = b.length(); // s.length --> 计算字符串位数
    for(int i=1; i<=len; i++)     
        a[i] = b[len -i] - '0'; //将字符串s转换为数组a, 倒序存储
}*/
int main(){
	int d[7]={1,2,5,10,20,50,100};
	int n;
	int c=0;
	int s[n];
	cin>>n;
	for(int i=0;i<n;i++){
		int N,a[7];
		int num=0;
		cin>>N;
		for(int j=0;j<7;j++){
			cin>>a[j];
		}
		for(int j=6;j>=0;j--){
			int x=N/d[j];
			if(N>=d[j]){
				N-=d[j]*min(a[j],x);
			    
			}num+=min(a[j],x);
			    
		}
		if(N==0){
			s[c]=num;
		}else
		{
			s[c]=-1;
		}
		c++;
	}
	for(int i=0;i<c;i++){
		cout<<s[i]<<endl;
	}
}