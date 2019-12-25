#include <iostream>
#include <climits>
using namespace std;
int main() {
    int cnt, tmp;
    cin >> cnt;
    int ma = 0, mi = INT_MAX;
    for (int i=0; i<cnt; i++) {
        cin >> tmp;
        if (tmp > ma) ma = tmp;
        if (tmp < mi) mi = tmp;
    } 
    cout << ma * mi << "\n";
    return 0;
}