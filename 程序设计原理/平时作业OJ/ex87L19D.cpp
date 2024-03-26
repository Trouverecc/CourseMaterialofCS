#include <iostream>
#include <string>
using namespace std;
struct student {									 
	int c,m,e,total;
	char id[100],name[100];};	//string is error
struct student stu[300]; 
int main() {
	int n;
	cin >> n;
	for(int i=1; i<=n; i++) {
	    cin>>stu[i].id>>stu[i].name>>stu[i].c>>stu[i].m>>stu[i].e;
	    stu[i].total=stu[i].c+stu[i].m+stu[i].e;
	}
    
	for (int i=1; i<=n-1; i++) {					
		for (int j=i+1; j<=n; j++) {
			if (stu[i].total < stu[j].total) {		
				swap(stu[i], stu[j]);
			}else if ((stu[i].total==stu[j].total)&&(stu[i].c<stu[j].c)){		
				swap(stu[i], stu[j]);
			}else if ((stu[i].total==stu[j].total)&&(stu[i].c==stu[j].c)&&(stu[i].id>stu[j].id)){		 
				swap(stu[i], stu[j]);
			}
		}
	}
	for (int i=1; i<=5; i++) {
		cout<<stu[i].id<<" "<<stu[i].name<<" "<<stu[i].total<<endl;
	}
	return 0;
}
