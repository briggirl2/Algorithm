#include <iostream>
using namespace std;
int gcd(int n, int m);
int main() {
    int n, m;
    cin >> n >> m;
    int g = gcd(n, m);
    int l = n * m / g;
    cout << g << "\n" << l << "\n";
    return 0;
}
int gcd(int n, int m) {
    while (m != 0) {
        int tmp = n % m;
        n = m;
        m = tmp;
    }
    return n;
}