//9012
#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    while(n--) {
        string s;
        cin >> s;
        stack<char> st;
        int slen = s.length();
        for (int i=0; i<slen; i++) {
            if (s[i] == '(')    st.push('(');
            else if (st.empty()) {
                st.push(')');
                break;
            } 
            else    st.pop();
        }
        if (st.empty()) cout << "YES\n";
        else    cout<< "NO\n";
    }
    return 0;
}