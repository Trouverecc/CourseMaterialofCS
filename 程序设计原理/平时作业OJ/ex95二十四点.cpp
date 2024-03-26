#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int list[n-1];
			int idx=0;
			for(int k=0;k<n;k++){
				if(k!=i&&k!=j){
					list[idx++]=realNums[k];
				}
			}
			for(CalType cal=CAL_MIN;cal<CAL_MAX;cal++){
				list[idx]=Calculate(realNums[i],realNums[j],cal);
			}
		}
	}
}