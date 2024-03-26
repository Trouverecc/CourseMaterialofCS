#include <iostream>
using namespace std;
int main()
{
    string str;
    while (cin >> str && (str[0] != '0'))
	{
        int sum = 0;
        for (int i = 0; i < str.size(); ++i)
            sum += str[i] - '0';//字符 '0' 和数字 0 在计算机内不同的ascii值，
			                    //str[i]-'0'就是将相应的数字字符转换为数字。
        cout << (int)sum << endl;
    }
    return 0;
}

