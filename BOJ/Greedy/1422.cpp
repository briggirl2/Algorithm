#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<string> v;
bool cmp(string a, string b);
int main() {
    int k, n;
    string a, m = "1";
    cin >> k >> n;
    for (int i = 0; i < k; i++) {
        cin >> a;
        v.push_back(a);
        if (m.size() < a.size()) {
            m = a;
        }
        else if (m.size() == a.size() && m < a) {
            m = a;
        }
    }
    sort(v.begin(), v.end(), cmp);
    int t = n - k;
    for (int i = 0; i < k; i++) {
        cout << v[i];
        if (v[i] == m) {
            while (t != 0) {
                cout << v[i];
                t--;
            }
        }
    }
    cout << "\n";
    return 0;
}

bool cmp(string a, string b) {
    return a+b > b+a;
}