/*#include <iostream>
#include <cstring>
using namespace std;
int main(){
    char x[1000],char y[1000];
	int a[1000]={},b[1000]={},c[1000]={};
	int len_a,len_b,len_c;
	cin>>x>>y;
	len_a=strlen(x);
	len_b=strlen(y);
	for(int i=0;i<len_a;i++){//1/0?
		a[len_a-i]=x[i]-'0';
	}
	for(int i=0;i<len_a;i++){//1/0?
		b[len_b-i]=y[i]-'0';
	}
	int x=0;
	while(len_c<=len_a||len_c<=len_b){
		c[len_c]=a[len_c]+b[len_c]+x;
		x=c[len_c]/10;
		c[len_c]%=10;
		len_c++;
	}
	c[len_c]=x;
	if(len_c==0){
		len_c--;
	}
	for(int j=len_c;j>=1;j--){
		cout<<c[j];
	}
	return 0;
}*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std; 
int main(){
    char a1[5001], b1[5001];
    int a[5001], b[5001], c[5001]; 
    int len_a, len_b, len_c = 1, x, i;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    cin>>a1>>b1;
    len_a = strlen(a1);
    len_b = strlen(b1);
    for(i=0; i<len_a; i++) a[len_a - i] = a1[i] - '0';
    for(i=0; i<len_b; i++) b[len_b - i] = b1[i] - '0'; 
    x = 0; // x为进位
    while(len_c <= len_a || len_c <= len_b) {
        c[len_c] = a[len_c] + b[len_c] + x; 
        x = c[len_c] / 10;
        c[len_c] %= 10; 
        len_c++; 
    }
    c[len_c] = x;
    if(c[len_c] == 0) { 
        len_c--; 
    }
    for(int i=len_c; i>=1; i--) {
        cout<<c[i];
    }
    return 0;
}