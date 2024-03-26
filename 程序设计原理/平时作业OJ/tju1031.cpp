#include<iostream>
using namespace std;
int hs(int a,int b){
	int count=0;
	for(int i=a*a+a+41;i<=b*b+b+41;i++){
		if((i%6==5||i%6==1)&&i!=1681) count++;
	}
	return count; 
}
int main(){
	int x,y;
	int a=0;
	while(cin>>x>>y){
		if(x==0&&y==0){
			break;
		}
	if(hs(x,y)==y-x+1)
	    cout<<"OK"<<endl;
	else cout<<"Sorry"<<endl;
	    
	}
}