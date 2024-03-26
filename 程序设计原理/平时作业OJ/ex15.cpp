/*不知道错在哪
#include <iostream>
using namespace std;
int main() 
{
	int a,b,c,i;
    int count = 0;
    cin>>a>>b>>c;
    while(1)
    {
	
        if (c%i==0)
		{
            if (i >= a && i <= b)
                {
				count++;
				}
            if ((c % i >= a) && (c % i <= b))
                {
				count++;
				}
        }
           if(a=0||b=0||c=0)
        {break;
	    }
    } cout << count << endl;
	
    }
    return 0;

  }  
*/
#include <iostream>
using namespace std;
int a,b,c,k=0;
int main() {
 cin >>a>>b>>c;
  while (a!= 0 ||b!=0||c!=0 ) {
   while (a<=b) {
    while (c % a== 0 && a <= b) { k = k + 1; a= a+1; }
    a= a+1;
   }
   cout << k << endl;
   cin >> a >> b >> c;
   k = 0;
  }
 return 0;
}