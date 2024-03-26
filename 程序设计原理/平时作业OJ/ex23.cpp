#include<iostream>
using namespace std;
int main() 
{
 int n;
 cin >> n;
 int arr[n];
 for (int i = 1; i < n; ++i) 
 {
  cin >> arr[n];
 }
 for (int j = n - 1; j >= 0; --j) 
 {
  if (j == n - 1)
   cout << arr[j];
  else
   cout << " " << arr[j];
 }
 cout << endl;
 return 0;
}
/*#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    int start=0;
    int end=sizeof(arr)/sizeof(arr[0])-1;
    while(start<end)
    {
    	int temp=arr[start];
    	arr[start]=arr[end];
    	arr[end]=temp;
    	start ++;
    	end--;
	}
	for(int i=0;i<n;i++)
	{
		cout<<arr[i];
	}
    return 0;
}*/