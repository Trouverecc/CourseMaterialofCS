//12A求最大公约数1
#include <iostream>
#include <cmath>
using namespace std;
long long factorial(long long m,long long n){
	long long z=n;
	while (m%n!=0){
		z=m%n;
		m=n;
		n=z;
	}return z;
}
int main(){
	long long m,n;
	
	while(1){
		cin>>m>>n;
		if(m==0&&n==0){
			break;
		}
		if(m!=0||n!=0){
		cout<<factorial(m,n)<<endl;
	    }
	}
	
	
}
/*int temp=(m>n)?n:m;
	if(m!=0||n!=0){
		for(int i=1;i<=temp;i++){
			if(temp%i!=0){
				cout<<i-1<<endl;
			}
		}
	}*/