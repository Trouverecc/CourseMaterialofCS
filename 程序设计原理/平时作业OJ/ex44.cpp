???/*#include <iostream>
#include <algorithm>
#include <string> 
int a[100];
using namespace std;
int main() 
{
	int n;
	cin>>n;
	while(n!=0)
	{
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		int min=a[0],b;
		for(int i=0;i<n;i++)
		{
			if(min>=a[i])
			{
				min=a[i];
				b=i;
			}
		}
		a[b]=a[0];
		a[0]=min;
		for(int i=0;i<n;i++)
		{
			cout<<a[i]<<" ";
			cin>>n;
		}
	}return 0;
}*/
/*#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		if(n==0)
		break;
		int a[n+5];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			int j=0;
            int k=a[0];
            for(int i=0;i<n;i++)
            {
                if(a[j]<k)
                {
                    k=a[j];
                    j=i; 
                }
            }
                swap(a[j],a[0]);
                for(int i=0;i<n;i++)
                cout<<a[i]<<" ";
				}cout<<endl;
			
	}
}*/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
 int n;
 cin>>n;
 while(n!=0)
 {
  for(int i=0;i<n;i++)
  {
   int arr[i];
   cin>>arr[i];
   int min=arr[0];
            int k=0;
            for(int j=0;j<n;j++)
            {
                if(arr[j]<min)
                {
                    min=arr[j];
                    k=j; 
                }
            }
                arr[k]=arr[0];
                arr[0]=min;
                for(int i=0;i<n;i++)
                cout<<arr[i]<<" ";
    }cout<<endl;
   
 }
}
	
