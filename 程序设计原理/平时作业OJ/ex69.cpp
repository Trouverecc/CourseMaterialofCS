/*#include <iostream>
using namespace std;
char* cat_fun(const char*stra,const char*strb){
	string s;
	return s.append(stra,strb);
}
int main(){
	char stra[20],strb[20];
	cin>>stra>>strb;
	cout<<cat_fun(stra,strb)<<endl;
}*/
#include <iostream>
#include <string>
using namespace std;
int main(){
	string s1,s2;
	cin>>s1>>s2;
	s1+=s2;
	cout<<s1<<endl;
}