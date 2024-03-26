#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int s[1000];
char str[10];
int main(){
	int m,n,d,x,flag;
	cin>>m;
	getchar();
	for(int i=1;i<=m;i++){
		queue<int>a;
	    stack<int>b; 
	    d=0;
	    flag=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>str;
			switch(str[1]){
				case 'u':
				cin>>x;
				a.push(x);
				b.push(x);
			    break;
			case 'o':
				if(a.empty()||b.empty())
				    flag=1;
				else{
					a.pop();
					b.pop();				
				} 
			    break;
			}
			
		}
		if(!flag){
			while(!a.empty()){
				cout<<a.front();
				a.pop();
				if(!a.empty())
				cout<<" ";
			}
			cout<<endl;
			while(!b.empty()){
				s[d]=b.top();
				b.pop();
				d++;
			}
			for(int i=d-1;i>=0;i--){
				cout<<s[i];
				if(i>0)
				    cout<<" ";
			}cout<<endl;
		}
		else{
			cout<<"error"<<endl;
			cout<<"error"<<endl;
		}
	}
	return 0;
}