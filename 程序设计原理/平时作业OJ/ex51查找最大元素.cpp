#include <iostream>
#include <algorithm>
#include <string> 
#include<iomanip>
using namespace std;
int main() 
{
    int n;
    cin >> n;
    string a;
    for (int i = 0; i < n; i++) 
	{
        cin >> a;
        char cmax = a[0];
        for (int j = 0; j < a.size(); j++) 
		{
            if (cmax <a[j]) 
			{
                cmax=a[j];
            }
        }
        for (int j = 0; j < a.size(); j++) 
		{
            cout << a[j];
            if (a[j] == cmax) 
			{
                cout << "(max)";
            }
        }
        cout << endl;
    }
    return 0;
}