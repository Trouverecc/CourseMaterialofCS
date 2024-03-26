#include <iostream>
#include <algorithm>
#include <map>
#include <hash_map>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i=n;n>0;n--)
    {
        int num = 0;
        int len;
		string s0;
        cin >> s0;        
		len = s0.size();                
        string str = s0;
        map<string, int> map0;
        str=s0+s0;
		//str.append(s0);
        for (int i = 0; i < len; i++)
        {
            for (int j = 1; j <= len; j++)
            {
                string str2 = str.substr(i, j);
                if (map0[str2] == 0)
                {
                    num++;
                    map0[str2]++;
                }
            }
        }
        cout << num << endl;
    }
}