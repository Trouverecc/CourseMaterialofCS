/*#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	int a;
	while(cin>>a)
	{
		a--;
		if(a!=0)
		{
			double sum=0,ans=0,arr[1010];
			
			for(int i=1;i<=a;i++)
			{
				int arr[i];
				cin>>arr[i];
				sum+=arr[i];
			}int m=1.0*sum/a;
			for(int i=1; i<=a; i++)
			{
				ans += 1.0*(m-arr[i])*(m-arr[i]);
		        ans = sqrt(ans/a);
		        cout << fixed << setprecision(8) << ans << endl;
			}
		}
		if(a=0)
		break;
	}
}*/
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
	int n;
	double a[1010], avg, ans;
	while(cin >> n){
		if(n==0)
			break;
		avg = ans = 0;
		for(int i=1; i<=n; i++){
			cin >> a[i];
			avg += a[i];
		}
		avg = 1.0*avg/n;
		for(int i=1; i<=n; i++)
			ans += 1.0*(avg-a[i])*(avg-a[i]);
		ans = sqrt(ans/n);
		cout << fixed << setprecision(8) << ans << endl;
	} 
	return 0;
}