#include <iostream>
#include <vector>
using namespace std;
int main(){
    /*vector<int>v1,v2;
    int A[]={1949,10,1};
    vector<int>::iterator It;
    v1.assign(A,A+3);
    v2.assign(3,10);
    for(int i=1;i<=5;i++){
    	v1.push_back(i);
	}
	v1.pop_back();
	v1.front()-=v1.back();
	for(It=v1.begin();It<v1.end();It++)
	v2.push_back(*It);
	v2.insert(v2.begin(),2,300);
	v2.erase(v2.begin()+5);
	for(int i=0;i<v2.size();i++)
	cout<<v2[i]<<" ";*/
	char str[]="c language",*p=str;
	cout<<*p;//输出c
	while(*p!=0){
		cout<<*p++;
    }//输出c language
	return 0;
}