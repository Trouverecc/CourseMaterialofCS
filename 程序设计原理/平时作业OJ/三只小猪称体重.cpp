#include <iostream>
using namespace std;
int main()
{int num1=0;
 int num2=0;
 int num3=0;
 cout <<"������С��A������"<<num1<<endl;
 cin >>num1;
 cout <<"������С��B������"<<num2<<endl;
 cin >>num2;
 cout <<"������С��C������"<<num3<<endl;
 cin >>num3;
 cout << "С��A������Ϊ"<<num1<<endl;
 cout << "С��B������Ϊ"<<num2<<endl;
 cout << "С��C������Ϊ"<<num3<<endl;
 if(num1>num2){
 if(num3>num1){
 cout<<"С��C����"<<endl;}else
 {
 cout<<"С��A����"<<endl;}
 }else
 {
 if(num3>num2){
 cout<<"С��C����"<<endl;}else
 {cout<<"С��B����"<<endl;
 }
}
system("pause");
return 0;}
