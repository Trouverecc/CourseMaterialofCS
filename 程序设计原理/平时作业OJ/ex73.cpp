//L15C骰子
#include <iostream>
using namespace std;
void setarr(int *arr,int b,int c,int d,int e,int f,int g){
    arr[0] = b;
    arr[1] = c;
    arr[2] = d;
    arr[3] = e;
    arr[4] = f;
    arr[5] = g;
}
int main(){
	int n[6];
	int arr[6];
	char a;
	for(int i=0;i<6;i++){
		cin>>n[i];
		arr[i]=n[i];
	}
	string s;
	cin>>s;
	for(int j=0;j<s.size();j++){
		for(int k=0;k<6;k++)
	        arr[k]=n[k];
		a=s[j];
		switch(a){
			case 'N':
                setarr(n,arr[1],arr[5],arr[2],arr[3],arr[0],arr[4]);			
			    break;
			case 'W':
			    setarr(n,arr[2],arr[1],arr[5],arr[0],arr[4],arr[3]);
				break;
			case 'S':
			    setarr(n,arr[4],arr[0],arr[2],arr[3],arr[5],arr[1]);
				break;
			case 'E':
			    setarr(n,arr[3],arr[1],arr[0],arr[5],arr[4],arr[2]);
				break;
		}
	}
	cout<<n[0];
	cout<<endl;
}