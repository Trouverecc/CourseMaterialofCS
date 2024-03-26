#include <iostream>
using namespace std;
int main()
{
    int w,h;
    while ((cin >> w >> h)&&(w!=0&&h!=0))
	{
        for (int i = 0; i < w; ++i)
		{
            for (int j = 0; j < h; ++j)
			{
                if (i == 0 || i == w - 1 || j == 0 || j == h - 1)
                    cout << "#";
                else
                    cout << ".";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
