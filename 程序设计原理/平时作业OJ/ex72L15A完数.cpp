//come on!
#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	while(n>0){
		n--;
		int a,b;
		cin>>a>>b;
		int count=0;//错在这
		for(int i=a;i<=b;i++){
			int sum=0;
			for(int j=1;j<i;j++){
				if(i%j==0){
					sum+=j;
				}	
			}//cout<<sum<<endl;
			if(sum==i){
				count++;
			}
			
		}cout<<count<<endl;
	}
}