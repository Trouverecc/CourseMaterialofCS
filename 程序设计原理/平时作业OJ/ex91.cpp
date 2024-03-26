/*#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
struct student{
	char name[100];
	int a,b,c,d,e;
	double p;
};
struct student stu[10001];
int main(){
	int xf[5];
	int z=0;
	for(int i=0;i<5;i++){
		cin>>xf[i];
		z+=xf[i];
	}
	int n;
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>stu[i].name>>stu[i].a>>stu[i].b>>stu[i].c>>stu[i].d>>stu[i].e;
			stu[i].p=(xf[0]*stu[i].a+xf[1]*stu[i].b+xf[2]*stu[i].c+xf[3]*stu[i].d+xf[4]*stu[i].e)/z;
		
	}
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5-i;j++)
		{
			if(xf[j]>xf[j+1])
			{
				int temp=xf[j];
			    xf[j]=xf[j+1];
			    xf[j+1]=temp;
			    swap(stu[j], stu[j+1]);
			}	
		}
	}
	for (int i=1; i<=n-1; i++){					
		for (int j=i+1; j<=n; j++){
			if (stu[i].p < stu[j].p) {		
				swap(stu[i], stu[j]);
			}else if ((stu[i].p==stu[j].p)&&(stu[i].a<stu[j].a)){		
				swap(stu[i], stu[j]);
			}else if ((stu[i].p==stu[j].p)&&(stu[i].a=stu[j].a)&&(stu[i].b=stu[j].b)){		
				swap(stu[i], stu[j]);
			}else if ((stu[i].p==stu[j].p)&&(stu[i].a<stu[j].a)){		
				swap(stu[i], stu[j]);
			}else if ((stu[i].p==stu[j].p)&&(stu[i].a<stu[j].a)){		
				swap(stu[i], stu[j]);
			}
			else if ((stu[i].total==stu[j].total)&&(stu[i].c==stu[j].c)&&(stu[i].id>stu[j].id)){		 
				swap(stu[i], stu[j]);
			}
		}
	}
	for (int i=1; i<=n; i++) {
		cout<<stu[i].name<<" "<<fixed<<setprecision(2)<<stu[i].p<<endl;
	}
}*/
/*#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
struct student{
	char name[100];
	double a,b,c,d,e;
	double A,B,C,D,E;
	double p;
};
struct student stu[10001];
bool contrast(const ranking x,const y){
	//p加权,abcde学分
	if(x.p==y.p){
		if(x.a==y.a){
			if(x.b==y.b){
				if(x.c==y.c){
					if(x.d==y.d){
						return x.e>y.e;
					}
					return x.d>y.d;
				}
				return x.c>y.c;
			}
			return x.b>y.b;
		}
		return x.a>y.a;
	}
	return x.p>y.p;
}
int main(){
	int xf[5];
	int z=0;
	for(int i=0;i<5;i++){
		cin>>xf[i];
		z+=xf[i];
	}
	int n;
	cin>>n;
	aa=xf[0],bb=xf[1],cc=xf[2],dd=xf[3],ee=xf[4];
	for(int i=1; i<=n; i++){
		cin>>stu[i].name>>stu[i].a>>stu[i].b>>stu[i].c>>stu[i].d>>stu[i].e;
		stu[i].p=(xf[0]*stu[i].a+xf[1]*stu[i].b+xf[2]*stu[i].c+xf[3]*stu[i].d+xf[4]*stu[i].e)/z;
		//cout<<fixed<<setprecision(2)<<stu[i].p<<endl;
	}
	
	for (int i=1; i<=n-1; i++){					
		for (int j=i+1; j<=n; j++){
			if (stu[i].p < stu[j].p) {		
				swap(stu[i], stu[j]);
			}else if ((stu[i].p==stu[j].p)&&(stu[i].a<stu[j].a)){		
				swap(stu[i], stu[j]);
			}else if ((stu[i].p==stu[j].p)&&(stu[i].a=stu[j].a)&&(stu[i].b=stu[j].b)){		
				swap(stu[i], stu[j]);
			}else if ((stu[i].p==stu[j].p)&&(stu[i].a<stu[j].a)){		
				swap(stu[i], stu[j]);
			}else if ((stu[i].p==stu[j].p)&&(stu[i].a<stu[j].a)){		
				swap(stu[i], stu[j]);
			}
			else if ((stu[i].total==stu[j].total)&&(stu[i].c==stu[j].c)&&(stu[i].id>stu[j].id)){		 
				swap(stu[i], stu[j]);
			}
		}
	}
	for (int i=1; i<=n; i++) {
		cout<<stu[i].name<<" "<<fixed<<setprecision(2)<<stu[i].p<<endl;
	}
}*/
#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std; 
struct ranking
{
 char name[100];
 double A,B,C,D,E;
 double a,b,c,d,e;
 double p;
};
 
bool contrast(const ranking x,const ranking y)
{
 if(x.p==y.p)
 {
  if(x.a==y.a)
  {
   if(x.b==y.b)
   {
    if(x.c==y.c)
    {
     if(x.d==y.d)
     {
      return x.e>y.e;
     }
     return x.d>y.d;
    }
    return x.c>y.c;
   }
   return x.b>y.b;
  }
  return x.a>y.a;
 }
 return x.p>y.p;
}
int main()
{
  
 int A,B,C,D,E;
 int a,b,c,d,e;
 int aa,bb,cc,dd,ee;
 int m;
 char name[100]; 
 struct ranking stu[10001];
 int xf[5];
 for(int i=0;i<5;i++){
 	cin>>xf[i];
 }
 A=xf[0];B=xf[1];C=xf[2];D=xf[3];E=xf[4];
 int sum=A+B+C+D+E;
 aa=A,bb=B,cc=C,dd=D,ee=E;
 int n;
 cin>>n;
 for(int i=0;i<n;i++)
 {
  cin>>stu[i].name>>stu[i].A>>stu[i].B>>stu[i].C>>stu[i].D>>stu[i].E;
  stu[i].p=(A*stu[i].A+B*stu[i].B+C*stu[i].C+D*stu[i].D+E*stu[i].E)/sum;
 }
 
 a=max(A,max(B,max(C,max(D,E)))); 
 if(B==a)swap(A,B); 
 else if(C==a)swap(A,C);
 else if(D==a)swap(A,D);
 else if(E==a)swap(A,E);
 b=max(B,max(C,max(D,E)));
 if(D==b)swap(B,D);
 else if(C==b)swap(B,C);
 else if(E==b)swap(B,E);
 c=max(C,max(D,E));
 if(D==c)swap(D,C);
 else if(E==c)swap(E,C);
 d=max(D,E);
 e=min(D,E);
 
 for(int i=0;i<n;i++)
 {
  if(aa==a)stu[i].a=stu[i].A;
  else if(bb==a)stu[i].a=stu[i].B;
  else if(cc==a)stu[i].a=stu[i].C;
  else if(dd==a)stu[i].a=stu[i].D;
  else if(ee==a)stu[i].a=stu[i].E;
  if(aa==b)stu[i].b=stu[i].A;
  else if(bb==b)stu[i].b=stu[i].B;
  else if(cc==b)stu[i].b=stu[i].C;
  else if(dd==b)stu[i].b=stu[i].D;
  else if(ee==b)stu[i].b=stu[i].E;
    if(aa==c)stu[i].c=stu[i].A;
  else if(bb==c)stu[i].c=stu[i].B;
  else if(cc==c)stu[i].c=stu[i].C;
  else if(dd==c)stu[i].c=stu[i].D;
  else if(ee==c)stu[i].c=stu[i].E;
  if(aa==d)stu[i].d=stu[i].A;
  else if(bb==d)stu[i].d=stu[i].B;
  else if(cc==d)stu[i].d=stu[i].C;
  else if(dd==d)stu[i].d=stu[i].D;
  else if(ee==d)stu[i].d=stu[i].E;
  if(aa==e)stu[i].e=stu[i].A;
  else if(bb==e)stu[i].e=stu[i].B;
  else if(cc==e)stu[i].e=stu[i].C;
  else if(dd==e)stu[i].e=stu[i].D;
  else if(ee==e)stu[i].e=stu[i].E;
 }
  
 sort(stu,stu+n,contrast);
  
 for(int i=0;i<n;i++)
 {
  cout<<stu[i].name<<" "<<fixed<<setprecision(2)<<stu[i].p<<endl;
 }
 return 0;
}