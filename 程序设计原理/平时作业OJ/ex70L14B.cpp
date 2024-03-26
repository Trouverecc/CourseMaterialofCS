#include <iostream>
#include <string>
using namespace std;
char*str_reverse(char*str){
	char *begin;
	char *end;
	begin=end=str;
	while(*end!='\0'){
		end++;
	}
	end--;
	char temp;
	while(begin<end){
		temp=*begin;
		*begin=*end;
		*end=temp;
		begin++;
		end--;
	}return str;
}
int main(){
	char str[100];
	cin>>str;
	cout<<str_reverse(str)<<endl;
	return 0;
}
/*#include <iostream>
#include <string>
using namespace std;
int main(){
	string s;
	getline(cin,s);
	for(int i=s.size()-1;i>=-1;i--){
		cout<<s[i];
	}
}*/