#include <iostream>
#include <algorithm>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
   double m,n;
   double a[10001]; 
   a[0]=0;
   while((cin>>m>>n)&&(m!=0&&n!=0)){
       
           a[0]=m;
           for(int i=0;i<n-1;i++){
                a[i+1]=sqrt(a[i]);
                a[0]+=a[i+1];
           }
           cout<<fixed<<setprecision(2)<<a[0]<<endl;
       
       
   }
    
}