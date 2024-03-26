#include<iostream>
using namespace std;
int main()
{
    int n,m,i,j;
    while(cin>>n>>m,n!=0||m!=0)
    {
        int a[n];
        for(i=0; i<n; i++)
            cin>>a[i];
            a[n]=m;
        for(i=0; i<n; i++)
        {
            for(j=n; j>i; j--)
                if(a[j]<a[i])
                {
                    int b=a[j];
                    a[j]=a[i];
                    a[i]=b;
                }
        }
        for(i=0; i<=n; i++)
        {
            if(i==0)
                cout<<a[i];
            else
        cout<<" "<<a[i];
        }
        cout<<endl;
    }
   return 0;
}
