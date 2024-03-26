#include<iostream>
//#include<cstdio>
using namespace std;
double num[200];
int main()
{
    double n;
    char s;
    while(cin>>num[0]&&num[0])
    {
        double ans=0.0;
        int i=0;
        s=getchar();
        if(num[0]==0&&s=='\n')
        {
            break;
        }
        while(cin>>s>>n&&s&&n)//scanf("%c %lf",&s,&n)==2
        {
            if(s=='*')
            {
                num[i]*=n;
            }
            else if(s=='/')
            {
                num[i]/=n;
            }
            else if(s=='+')
            {
                num[++i]=n;
            }
            else
            {
                num[++i]=-n;
            }
            if(s=getchar()=='\n')
            {
                break;
            }
        }
        while(i>=0)
        {
            ans+=num[i];
            i--;
        }
        printf("%.2f\n",ans);
    }
    return 0;
}



/*#include <iostream>
#include<cmath>
#include<iomanip>
#include <stack>
using namespace std;
int main(){
	double a,ans=0.0;
	char str;
	while(cin>>str>>a){
		if(a==0&&str=='\n')
		    break;
		stack<double>s;
		s.push(a);
		double ans=0;
		while(cin>>str>>a){
			if(str=='+'||str=='-'||str=='*'){
				switch(str){
				case '+':
					s.push(a);
					break;
				case '-':
					s.push(-a);
					break;
				case '*':
					double d=s.top()*a;
					s.pop();
					s.push(d);
					break;
			    }
			}
			else{
				    double b=s.top()*1.0/a;
					s.pop();
					s.push(b);
				    break;
			}
						
			
			char k=getchar();
			if(k=='\n'){
				break;
			}
		}
		while(!s.empty()){
			ans+=s.top();
			s.pop();
		}	   
	}
	cout<<fixed<<setprecision(2)<<ans<<endl;
}*/