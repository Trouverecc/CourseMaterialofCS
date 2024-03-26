#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    int count[26] = {0};
    string str;
    getline(cin,str);

    for (int i=0; i<str.size(); i++) 
	{
        transform(str.begin(),str.end(),str.begin(),::tolower);

        for (int j = 0; j < 26; j++) 
		{
            if (str[i] == (char)('a' + j))
                count[j]++;
        }
    }
    for (int i = 0; i < 26; ++i) 
	{
        cout << (char)('a'+i) <<" : "<< count[i] <<endl;
    }
    return 0;
}
