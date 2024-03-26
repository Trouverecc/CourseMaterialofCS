#include <iostream>
#include <deque>
using namespace std;
#define  endl '\n'
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    deque<int> A;
    int n;
    cin >> n;
    while (n--) {
        
		int t;
        cin >> t;
        if (t == 0) {
            int d, x;
            cin >> d >> x;
            if (d == 0)A.push_front(x);
            else if (d == 1)A.push_back(x);
        } else if (t == 1) {
            int p;
            cin >> p;
            if (A.empty())continue;
            cout << A[p] << endl;
        } else {
            int d;
            cin >> d;
            if (A.empty())continue;
            if (d == 0)A.pop_front();
            else if (d == 1)A.pop_back();
        }
    }

    return 0;
}
