#include <iostream>
#include <stack>
#include <vector>
using namespace std; 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, tmp;
    cin >> n;
    stack<int> st;
    vector<char> ans;
    int k = 1;
    for (int i=0; i<n; i++) {
        cin >> tmp;
        for (; k<=tmp; k++) {
            ans.push_back('+');
            st.push(k);
        }
        if (st.top() == tmp) {
            ans.push_back('-');
            st.pop();
        }
        else {
            cout << "NO\n";
            return 0;
        }
    }
    for (auto &a : ans) {
        cout << a << "\n";
    }
    return 0;
}