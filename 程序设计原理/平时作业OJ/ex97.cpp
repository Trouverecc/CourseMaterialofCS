#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <map>
#include <vector>
int n, a[7], vis[7];
int sti[7], stc[7], topi,topc;
std::vector<int> ex;
std::map<std::vector<int>, int> is;
inline void calc() {
    int b = sti[topi -- ], a = sti[topi -- ], opt = stc[topc -- ], res;
    if (opt == 14) res = a + b;
    if (opt == 15) res = a - b;
    if (opt == 16) res = a * b;
    if (opt == 17) res = a / b;
    sti[ ++ topi] = res;
}
inline bool check() {
    if (is[ex]) return false;
    is[ex] = true;
    topi = 0, topc = 0;
    for (int c: ex)
    if (c <= 13) {
    sti[ ++ topi] = c;
    } 
	else {
        while (topc && stc[topc] / 2 >= c / 2) calc();
        stc[ ++ topc] = c;
    }
    while (topc) calc();
    return sti[1] == 24;
}
inline void print() {
    for (int c: ex)
    if (c <= 13) printf("%d", c);
    else {
        if (c == 14) putchar('+');
        if (c == 15) putchar('-');
        if (c == 16) putchar('*');
        if (c == 17) putchar('/');
    }
    putchar('\n');
}
int dfs(int u) {
    if (u == n * 2) return check() && (print(), 1);
    int res = 0;
    if (u & 1) {
    for (int i = 1; i <= n; ++ i )
    if (!vis[i]) {
        vis[i] = true, ex.emplace_back(a[i]);
        res += dfs(u + 1);
        vis[i] = false, ex.pop_back();
    }
    } 
	else {
        int i=14;
		while ( i <= 17) {
        ex.emplace_back(i);
        res += dfs(u + 1);
        ex.pop_back();
        i++;
        }
    }
    return res;
}
int priority(char ope_){
    if(ope_=='+'||ope_=='-')
	    return 1;
    else if (ope_=='*'||ope_=='/')
	    return 2;
	else
	    return 0;
}
int main() {
    scanf("%d", &n);
    int i = 1;
    while(i <= n) {
 	    scanf("%d", a + i);
        ++ i ;
    }
    printf("%d\n", dfs(1));
}
/*#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <vector>
int n, a[7], vis[7];
int sti[7], stc[7], topi,topc;
std::vector<int> ex;
std::map<std::vector<int>, int> is;
inline void calc() {
    int b = sti[topi -- ], a = sti[topi -- ], opt = stc[topc -- ], res;
    if (opt == 14) res = a + b;
    if (opt == 15) res = a - b;
    if (opt == 16) res = a * b;
    if (opt == 17) res = a / b;
    sti[ ++ topi] = res;
}
inline bool check() {
    if (is[ex]) return false;
    is[ex] = true;
    topi = 0, topc = 0;
    for (int c: ex)
    if (c <= 13) {
    sti[ ++ topi] = c;
    } 
	else {
        while (topc && stc[topc] / 2 >= c / 2) calc();
        stc[ ++ topc] = c;
    }
    while (topc) calc();
    return sti[1] == 24;
}
inline void print() {
    for (int c: ex)
    if (c <= 13) printf("%d", c);
    else {
        if (c == 14) putchar('+');
        if (c == 15) putchar('-');
        if (c == 16) putchar('*');
        if (c == 17) putchar('/');
    }
    putchar('\n');
}
int dfs(int u) {
    if (u == n * 2) return check() && (print(), 1);
    int res = 0;
    if (u & 1) {
    for (int i = 1; i <= n; ++ i )
    if (!vis[i]) {
        vis[i] = true, ex.emplace_back(a[i]);
        res += dfs(u + 1);
        vis[i] = false, ex.pop_back();
    }
    } 
	else {
        for (int i = 14; i <= 17; ++ i ) {
        ex.emplace_back(i);
        res += dfs(u + 1);
        ex.pop_back();
        }
    }
    return res;
}

int main() {
 scanf("%d", &n);
 for (int i = 1; i <= n; ++ i ) scanf("%d", a + i);
 printf("%d\n", dfs(1));

 return 0;
}*/
/*xzc不完全版本
#include <bits/stdc++.h>
using namespace std;
#define ll long long
	int n0,a0[8],vis0[8],val0[8],b0[8],ans0;
	unsigned long long A;
	ll top,st1[10],st2[10];
	unordered_map<unsigned long long,bool> mp;
	void check(){
		st1[top=1]=val0[a[1]];
		for(int i=2;i<=n;i++){
			if(b0[i-1]<=2){
				st2[top]=b0[i-1];
				st1[++top]=val0[a[i]];
			}
			else{
				if(b0[i-1]==3){
					st1[top]*=val0[a[i]];
				}
				if(b0[i-1]==4){
					st1[top]/=val0[a[i]];
				}
			}
		}
		for(int i=2;i<=top;i++){
			if(st2[i-1]==1) st1[1]+=st1[i];
			if(st2[i-1]==2) st1[1]-=st1[i];
		}
		if(st1[1]!=24) return ;
		b[0]=0;
		A=0;
		for(int i=1;i<=n;i++){
			A=A*114+val0[a[i]]*514+(b0[i-1])*1919;
			
			
		}
		if(mp[A]) return;
		mp[A]=1;
		cout<<val0[a[i]];
	}
	ans0++;
	cout<<endl;
}
int AAA=0;
void dfs(int now){
	if(now==n){
		for(int i=1;i<=n;i++){
			if(vis[i]==0) a0[now]=i;
		}
		check();
		a0[now]=0;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis0[i]) continue;
		vis0[i]=1;
		a0[now]=i;
		for(int j=1;j<=4;j++){
			b0[now]=j;
			dfs(now+1);
			b0[now]=0;
		}
		a[now]=0;
		vis[i]=0;
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>val0[i];
	}
	dfs(1);
	cout<<ans0<<endl;
}*/
/*zch
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;
int count=0;
int priority(char ope_){
    if(ope_=='+'||ope_=='-')
	    return 1;
    else if (ope_=='*'||ope_=='/')
	    return 2;
	else
	    return 0;
}
int calculate(deque<int>Num,deque<char>Opt){
{
    int a,b;
    while (!Opt.empty()){
        a=Num.front();
        Num.pop_front();
        b=Num.front();
        Num.pop_front();
        if (Opt.front()=='+')
            Num.push_front(a+b);
		else if (Opt.front()=='-')
            Num.push_front(a-b);
		else if (Opt.front()=='*')
		    Num.push_front(b*a);
		else if (Opt.front()='/')
            Num.push_front(a/b);
        Opt.pop_front();       
    }
    return Num.front();
}
int calcu_base(deque<int>Num,deque<char>Opt){


    deque<char>opt_p;
    deque<char>opt_x;
    deque<int>num_p;
    deque<int>num_x;
	char opt_;
	int num_;
    int times Num.size();
	while (times--){
        num_=Num.front();
        Num.push_back(num_);
        Num.pop_front();
        opt_=Opt.front();
        Opt.push_back(opt_);
        Opt.pop_front();
        if (priority(opt_)=1){
            if (times!=Num.size()){
			    if (priority(Num.back())==1){
                    num_p.push_back(num_);
					opt_p.push_back(opt_);
				}
				else
				{
                    num_x.push_back(num_);
                    num_p.push_back(calculate(num_x,opt_x));
                    opt_p.push_back(opt_);
                    num_x.clear();
                    opt_x.clear();
                }
            }
            else{
			    num_p.push_back(num_);
                opt_p.push_back(opt_);
            }
        }
        else if (priority(opt_)==2){
        	num_x.push_back(num_);
            opt_x.push_back(opt_);
		}
        else{
        	if (priority(Num.back())==1)
            {
                num_p.push_back(num_);
            }
		    else
            {
                num_x.push_back(num_);
                num_p.push_back(calculate(num_x,opt_x));
                num_x.clear();
                opt_x.clear();
            }
        }
    }
    if (calculate(num_p,opt_p)==24)
        return 1;
    else
        return 0;
}
void perm_opt(int times,char opters[],vector<deque<char>>&opt,deque<char>opt_temp)
{
    if (times)
    {
	    for (int i=0;i<4;i++){
	    	opt_temp.push_back(opters[i]);
            perm_opt(times-1,opters,opt,opt_temp);
            opt_temp.pop_back();
	    }
    }
    else{
	    opt.push_back(opt_temp);
        while(!opt_temp.empty())
            opt_temp.pop_back();
        return;
    }
}
void output_nums(int end,vector<deque<int>>&num,vector<int>numbers)
{
    deque<int>numl;
    for(inti=0;i<=end;i++)
        num1.push_back(numbers[i]);
    num.push_back(num1);
}
void perm_num(int begin,int end,vector<deque<int>>&num,vector<int>numbers)
{
    if (begin =end)
    {
        output_nums(end,num,numbers);
        return;
    }
    for (int i=begin;i<=end;i++){
    	swap(numbers[begin],numbers[i]);
        perm_num(begin 1,end,num,numbers);
        swap(numbers[begin],numbers[i]);
    }
}
void print_opt(vector<deque<char>>opt){	
    for (int i=0;i opt.size();i++)
    {
        int m2=opt[i].size();
        for (int j=0;j<m2;j++)
        { 
            cout<<opt[i].back()<<" ";
            opt[i].pop_back();
        }
        cout <endl;
    }
}
void print_num(vector<deque<int>>num){
    for (int i=0;i<num.size();i++){
    	int m2=num[i].size();
        for (int j=0;j<m2;j++){
            cout<<num[i].back()<<" ";
            num[i].pop_back();
	    }
	    cout<<endl;
	}
}
void display_line(deque<int>num,deque<char>opt){
    int siz num.size();
    string str;
    deque<char>opt2 =opt;
    deque<int>num2=num;
    while(siz--)
    {
        str.append(to_string(num2.front()));
        num2.pop_front();
        if (siz>=1)
        {
            str.push_back(opt2.front());
            opt2.pop_front();
        }
    }
    cout<<str<<endl;
    count++;
}
void display(vector<deque<int>>num,vector<deque<char>>opt)
{
    for (int i=0;i<num.size();i++){
        for (int j=0;j<opt.size();j++){
            opt[j].push_back('=');
            if(calcu_base(num[i],opt[j])){
            	display_line(num[i],optj]);
			}
		}
	}
}
int main()
{
    int n;
    vector<int>numbers;
    deque<char>opt_temp;
    vector<deque<int>>num;
    vector<deque<char>>opt;
    char opters[4]={'+','-','*','/'}
    cin>>n;
    numbers.resize(n);
    for(int i=0;i<n;i++)
        cin>>numbers[i];
    perm_num(0,n-1,num,numbers);
    set<deque<int>>s1(num.begin(),num.end());
    num.assign(s1.begin(),s1.end());
    perm_opt(n-1,opters,opt,opt_temp);
    set<deque<char>>s2(opt.begin(),opt.end());
    opt.assign(s2.begin(),s2.end());
    display(num,opt);
    cout<<count;
}*/
