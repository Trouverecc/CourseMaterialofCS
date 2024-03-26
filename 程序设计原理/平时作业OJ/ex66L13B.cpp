/*#include <iostream>
using namespace std;
int hs(int n){
	int a[100000];
	int i;
	int j=0;
	for(int i=0;n>0;i++){
		a[i]=n%2;
		n/=2;
		j++;
	}
	int b=0;
	for(int l=0,k=j-1;l<k;l++,k--){
		if(a[l]==a[k])b++;
	}
	if(b==j/2)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
int main(){
	int T;
	cin>>T;
	while(T>0){
		int n;
		cin>>n;
		hs(n);
		T--;
	}
}*/
//myerror->true
#include <iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
	while(t>0){
    	int n,i,j=0;
        int a[100000];
        cin>>n;
        i=n;
        int len=0;
        while(i)
        {   
            a[j]=i%2;
            i/=2;
            j++;
            len++;
        }
        //不用sizeof了
        int b=len-1,flag=0;
        for(int i=0;i<len;i++,b--){
        	if(a[i]!=a[b]){
        		flag =1;
        		break;
			}
		}
		if(!flag) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
        t--;
	}
}

/*int n,ans;//ans储存二进制位数，方便输出
vector<int> a;//因为n的范围是1e9，所以我定了一个动态数组
int main(){
cin>>n;
while(n>0){
ans++;//存位数
a.push_back(n%2);//如数组
n/=2;}
for(int i=ans-1;i>=0;i--) cout<<a[i];}//倒序输出*/
/*#include<iostream>
using namespace std;
void main()
{
   int n,i,j=0;
   int a[1000];
   cin>>n;
   i=n;
   while(i)
   {
    a[j]=i%2;
    i/=2;
    j++;
    
   }
   for(i=j-1;i>=0;i--)
    cout<<a[i];
   cout<<endl;
}*/
//cyz
/*#include <iostream>
using namespace std;
int main(){
	long long T,n;
	cin>>T;
	while(T>0){
		cin>>n;
		long long a[100000]={};
		long long i=0;
		while(n>0){
			a[i]=n%2;
			n/=2;
			i++;
		}
		long long low=0;
		while(low<=i-1){
			if(a[low]!=a[i-1]){
				cout<<"No"<<endl;
				break;
			}
			if(low==i-1||low+1==i-1){
				cout<<"Yes"<<endl;
				low++;
				i--;
			}
		}
		T--;
	}
	return 0;
}*/