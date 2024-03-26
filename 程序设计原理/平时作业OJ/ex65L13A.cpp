#include <iostream>
using namespace std;
bool hs(int num){
	int a;
	int b;
	int c;
	a=num%10;
	b=num/10%10;
	c=num/100;
	return a*a*a+b*b*b+c*c*c==num;
}
int main(){
	int m,n;
    
    while(cin>>m>>n){
    	
    	int d=0;
    	for(int i=m;i<=n;i++){
    		if(hs(i)){
		    cout<<i<<" ";
    	    d++;
    	    }
		}
		
		if(d==0){
			cout<<"no"<<endl;
		}
		
	}return 0;
}
/*#include <iostream>
using namespace std;
int main()
{int num=100;
int m,n;
cin>>m>>n;
do
 {
	int a;
	int b;
	int c;
	a=num%10;
	b=num/10%10;
	c=num/100;
	int d=0;
	if(a*a*a+b*b*b+c*c*c==num)
	{
		cout<<num<<" ";
		d++;
	}
	if(d=0){
		cout<<"no"<<endl;
	}
	
	num++;
    
    	
	}while(num<=n);
	
	
}*/


