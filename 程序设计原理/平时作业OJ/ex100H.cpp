#include<bits/stdc++.h>
#include <iostream>
#include<cmath>
#include<iomanip>
using namespace std; 
const int N=10010;
int read(){
	int x=0,f=0;
	char ch=getchar();
	while(!isdigit(ch)) {if(ch=='-')f=1;ch=getchar();}
	while(isdigit(ch)) {x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int s[N][N],x[N],y[N],b[N]; 
int x11, y11, x22, y22,c1,c2; 
int n,m,nn;
void enter();
int sum_ans(int, int, int,int); 
int find(int t); 
/*void get_cofind();
void count_all();
void display();*/ 
void enter(){
    int i= 1;
	while(i<= n){
	    cin>>x[i]>>y[i];
	    b[++nn] =x[i]; 
		b[++nn] =y[i];
		i++;
    }
}
int sum_ans(int x01, int y01, int x02, int y02){
    return s[x02][y02]-s[x02][y01-1]-s[x01-1][y02]+s[x01-1][y01-1];
}
int find(int t)
{
    return lower_bound(b+1,b +nn +1,t) - b;
    
}
void count_all(){
    int i= 1;
	while(i<=nn+1){
        int j= 1;
		while( j<= nn + 1){
            s[i][j] += (s[i-1][j]+s[i][j-1]-s[i-1][j-1]);
            j++; 
        }
        i++;
    }
}
void get_cofind(){
    int i= 1;
	while(i <= n){
        x11=lower_bound(b+1,b+nn+1,x[i]) - b; 
         
		y11 = lower_bound(b+1,b+nn+1,y[i]) - b;
	
		s[x11][y11]++;
		i++;
	}
}

void display()
{
    while (m--){
	    cin>>c1>>c2; 
		c1++,c2++;
        x11=find(x[c1]); 
        y11 =find(y[c1]); 
        x22=find(x[c2]); 
        y22 =find(y[c2]); 
        if(x11>x22)
            swap(x11,x22); 
		if(y11>y22)
            swap(y11,y22);
        cout<<sum_ans(x11,y11,x22,y22)<<'\n';
    }
}
int main(){
    cin.tie(0)->ios::sync_with_stdio(0); 
    cin>>n>>m; 
	enter();
    sort(b+1,b+nn+1);
    nn=unique(b+1,b+nn+1)-(b+1); 
	get_cofind(); 
	count_all(); 
	display(); 
	return 0;
}