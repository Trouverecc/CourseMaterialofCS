#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;
int main(){
    int n,m;
    double arr[10000];
    double a=0;
    while(1){
    	cin>>n>>m;
		double a=0;//注意清空a的值
		arr[0]=n;
		if(n==0&&m==0){break;
	    }

        for(int i=0;i<m;i++){
        arr[i+1]=sqrt(arr[i]);
        a+=arr[i];
        }cout<<fixed<<setprecision(2)<<a<<endl;
		}
}


    
