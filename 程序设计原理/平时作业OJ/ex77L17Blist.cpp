//mine 
#include <iostream>
#include <hash_map>
#include <list>
using namespace std;
using namespace __gnu_cxx;
int main(){
	int m,n,id1,id2;
	cin>>n;
	char str[10];
	list<int>::iterator i;
	hash_map<int,list<int>>a;
	while(n>0){
		n--;
		cin>>str;
		switch(str[0])
		{
			case 'n':
				cin>>id1;
				a[id1]=list<int>();
				break;
		    case 'a':
		    	cin>>id1>>m;
		    	a[id1].push_back(m);
		    	break;
		    case 'm':
			    cin>>id1>>id2;
			    a[id1].merge(a[id2]);
			    break;
			case 'u': 
			    cin>>id1;
			    a[id1].sort();
			    a[id1].unique();
			    break;
			case 'o':
			    cin>>id1;
			    a[id1].sort();
				for(i=a[id1].begin();i!=a[id1].end();i++){
					cout<<*i<<" ";
				}
				cout<<endl;
				break;
		}
	}
}
