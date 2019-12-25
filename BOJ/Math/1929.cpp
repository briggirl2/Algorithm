#include <iostream>
using namespace std;
bool notPrime[1000001] = {false, };
int main() {
    int m, n, i;
    cin >> m >> n;
    notPrime[1] = true;
    for (i=2; i*i<=1000000; i++) {
        if (notPrime[i]) continue;
        for (int j=i+i; j<=1000000; j+=i) {
            notPrime[j] = true;
        }
    }
    for (i=m; i<=n; i++) 
        if (!notPrime[i]) cout << i << "\n";
    return 0;
}