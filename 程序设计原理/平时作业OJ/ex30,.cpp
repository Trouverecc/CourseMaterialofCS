#include<iostream>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T>0)
	{
		T--;
		int n, m, temp;
	    while (cin >> m >> n)
	  {
		long int temp_Even = 0;
		long int temp_Odd = 0;
		if (m > n)
		{
			temp = m;
			m = n;
			n = temp;
		}
 
		for (int i = m; i <= n; i++)
		{
			if (i % 2 == 0)
			{
				temp_Even += i * i;
			}
			else
			{
				temp_Odd += i * i * i;
			}
		}
		cout << temp_Even << " " << temp_Odd << endl;
	  }
	}
	
	return 0;
}