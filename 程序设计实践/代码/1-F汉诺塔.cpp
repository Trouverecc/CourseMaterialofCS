#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	
	while(n--){
		long long a; 
		cin>>a;
		long long m=1;
		for(int i=0;i<a;i++){
			m=m*2;
			
		}
		m-=1;
		cout<<m<<endl;
	}
}