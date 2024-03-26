class MyInteger {
private:
    int n[10000], len;
public:
    MyInteger() {
        memset(n, 0, sizeof(n));
        len = 0;
    }
    MyInteger(int num) {
        memset(n, 0, sizeof(n));
        len = 0;
        int i = 0; 
        while(num != 0) {
            n[i] = num % 10;
            num /= 10;
            len++;
            i++; 
        }
    }
    MyInteger(string num) {
    memset(n, 0, sizeof(n));
        len = 0;
        string a; int count = 0;
        while (num[count] == '0')
            count++;
        while (num[count] != '\0')
            a.push_back(num[count++]);
        reverse(a.begin(), a.end());
        int i = 0; 
        while(i < strlen(a.c_str())){
        int temp; string temp1;
        temp1.push_back(a[i]);
        sscanf(temp1.c_str(), "%d", &temp);
            n[i] = temp;
            len++;
             i++;
        }
    }
    ~MyInteger() {}
    string getnum() {
        if (len == 0)return "0";
        string a;
        for (int i = 0; i < len; i++)
            a.push_back(n[i] + 48);
        reverse(a.begin(), a.end());
        return a;
    }
MyInteger operator+(const MyInteger& b) {
    MyInteger c;
int carry = 0;
int i = 0; 
while(i < len || i < b.len){
int temp = n[i] + b.n[i] + carry;
carry = temp / 10;
c.n[c.len++] = temp % 10;
     ++i; 
}
if (carry != 0)
c.n[c.len++] = carry;
return c;
     
}
MyInteger operator-(const MyInteger& b) {
MyInteger c;
int i = 0; 
while(i < len || i < b.len){
if (n[i] < b.n[i]) {
n[i + 1]--;
n[i] += 10;
}
c.n[c.len++] = n[i] - b.n[i];
 ++i;
}
while (c.len - 1 >= 1 && c.n[c.len - 1] == 0)
c.len--;
return c;
}
MyInteger operator*(const MyInteger& b) {
if (b.len == 0)return b;
MyInteger c, temp;
MyInteger tb = b;
for (int i = 0; i < len; i++) {
for (int j = 0; j < tb.len; j++) {
c.n[i + j] += n[i] * tb.n[j];
}
}int l = len + tb.len;
int i = 0;
for (; i < l; i++){
c.n[i + 1] += c.n[i] / 10;
c.n[i] %= 10;
     
}
if (c.n[l] > 0)
            l++;
        while (c.n[l - 1] >= 10){
            c.n[l] = c.n[l - 1] / 10;
            c.n[l - 1] %= 10;
            l++;
        }
        while (c.n[l - 1] == 0 && l > 1) l--;
        for (int i = 0; i < l; i++)
            temp.n[i] = c.n[i];
            temp.len = l;
        return temp;
    }
};

/*#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,f=0;
	char ch=getchar();
	while(!isdigit(ch)) {if(ch=='-')f=1;ch=getchar();}
	while(isdigit(ch)) {x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
class MyInteger{
private:
    vector<unsigned int> dzs; 
public: 
    MyInteger(){
    }
    MyInteger(int num){ 
        dzs.resize(200);
        int a;
        int i=0;
        while(num>0){
            a=num%10;
            num=num/10;
            dzs[i]=a;
            i++;
        }
        dzs.resize(i);
    }
    MyInteger(string num){    
        dzs.resize(num.length());       
        int i;
        for(i=0; i<dzs.size(); i++) {
            dzs[i] = num[num.length()-i-1]-'0';
        }
        i--;
        while(i>0 && dzs[i]==0) i--;                              
        if(i < dzs.size()) dzs.resize(i+1);
    }
    ~MyInteger(){}
    string getnum() const{
        string str;    
        str.resize(dzs.size());
        int w=dzs.size();
        for(long long  i=0; i<w; i++) str[w-i-1] = dzs[i]+'0';
        return str; 
    }
    MyInteger www(int i){
        MyInteger a1;
        a1.dzs.resize(dzs.size()+i);
        for(size_t k=0; k<i; k++) a1.dzs[k] = 0;
        for(size_t k=0; k<dzs.size(); k++) a1.dzs[k+i] =dzs[k];
        return a1;
    }
    MyInteger operator+(const MyInteger& b){
        MyInteger sum;
        int sdiginum;
        if(dzs.size() >= b.dzs.size()) sdiginum=dzs.size() ;
        else sdiginum=b.dzs.size();
        sum.dzs.resize(sdiginum+1);
        int carry = 0;
        for(int i=0; i<sdiginum; i++) {
            int digi = (i < dzs.size()   ? dzs[i]   : 0) + 
                       (i < b.dzs.size() ? b.dzs[i] : 0) +
                       carry;
            if(digi >= 10) {
                digi -= 10;
                carry = 1;
            }
            else {
                carry = 0;
            }
            sum.dzs[i] = digi;
        }      
        if(carry) {
            sum.dzs[sdiginum] = 1; 
        } else {
            sum.dzs.resize(sdiginum); 
        }
        return sum;
    }
    MyInteger operator-(const MyInteger& b){
        MyInteger sub;
        if(b.dzs.size()>dzs.size()) return 0;
        int sdiginum = dzs.size();
        MyInteger operator-(const MyInteger& b){
            MyInteger sub;
            if(b.dzs.size()>dzs.size()) return 0;
            int sdiginum = dzs.size();
            sub.dzs.resize(sdiginum);
            int carry = 0;
            for(int i=0; i<=sdiginum-1; i++) {
                int digi = dzs[i] - (i < b.dzs.size() ? b.dzs[i] : 0)
                -carry;
            if(digi < 0) {
                digi += 10;
                carry = 1;
            } 
            else {
                carry = 0;
            }
            sub.dzs[i] = digi;
            }
            if(carry) {
                sub = 0; 
            } 
            else {
                size_t i = sub.dzs.size() - 1;
                while(i>0 && sub.dzs[i]==0) i--;
                if(i==0)
                    sub = 0;
                else {
                    if(i<sub.dzs.size()-1) sub.dzs.resize(i+1);
                }
            }      
        return sub;
        }
        MyInteger operator*(const MyInteger& b){
        MyInteger result = 0;
        for(int i=0; i<b.dzs.size(); i++) {
            MyInteger b1 = 0;
            int carry = 0;
            int j = 0;
          b1.dzs.resize(dzs.size()+1);
            while(j<dzs.size()) {
                int mdigi = dzs[j] * b.dzs[i] + carry;
                carry = mdigi / 10;
                b1.dzs[j] = mdigi % 10;
                j++; 
            }
            if(carry) {
                b1.dzs[j] = carry;
            } else {
                b1.dzs.resize(j);
            }            
            result = result + b1.www(i);            
        }
        return result;
        }  
	}
};*/