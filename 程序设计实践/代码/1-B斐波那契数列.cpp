#include <iostream>
using namespace std;
int main(){
	long long F[100];
	F[0]=1;
	F[1]=1;
	int n,a;
	cin>>n;
	for(int i=2;i<100;i++){
		F[i]=F[i-1]+F[i-2];
	}
	/*for(int j=0;j<n;j++){
		cin>>a;
		cout<<F[a-1]<<endl;
	}*/
	while(n--){
		cin>>a;
		cout<<F[a-1]<<endl;
	}
	return 0;
}