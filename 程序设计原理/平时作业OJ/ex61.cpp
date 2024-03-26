//11C 自己做的
#include <iostream>
#include <string>
using namespace std;
int main(){
	string str;
	cin>>str;
	const char *MyString ="str";
	int case0;
	cin>>case0;
	while(case0>0){
		case0--;
		int w;
		cin>>w;
		if(w==1){
			cout<<str.length()<<endl;
		}
		if(w==2){
			string strr;
			cin>>strr;
		    if(str.find(strr)<=sizeof(str))
			cout<<str.find(strr,0)<<endl;
			else
			cout<<"-1"<<endl;
			
		}
	} 
}