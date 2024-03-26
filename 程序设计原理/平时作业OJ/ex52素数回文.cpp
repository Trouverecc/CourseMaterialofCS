#include <iostream>
#include <algorithm>
#include <string> 
#include <cmath>
#include<iomanip>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    while (a != 0 && b != 0) {
        for (int i = a; i <= b; i++) {
            int x = 0, s=i;
            while (s > 0){
                x = x * 10 + s % 10;
                s = s / 10;
            } 
            int r = 0;
            for (int j = 1; j <= i; j++) {
               if (i % j == 0)
                    r++;
            }
            if (x == i && r == 2) {
                cout << i << endl;
            }
        }
        cout << endl;
        cin >> a >> b;
    }
    return 0;
}