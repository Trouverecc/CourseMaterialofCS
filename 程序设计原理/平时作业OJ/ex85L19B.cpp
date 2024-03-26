#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int month[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},
	{0,31,29,31,30,31,30,31,31,30,31,30,31}};
	while(n--){
		int y,m,d;
		int sum=0;
		scanf("%d/%d/%d",&y,&m,&d);
		if((y%4==0&&y%100!=0)||(y%400==0)){
			for(int i=0;i<m;i++){
				sum+=month[1][i];
			}
		}else
		{
			for(int i=0;i<m;i++){
				sum+=month[0][i];
			}
		}
		sum+=d;
		cout<<sum<<endl;
	}
}