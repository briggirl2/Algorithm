## ACM ICPC 2018 _ Nationwide Internet Competition
https://codejam.withgoogle.com/codejam/contest/3324486/dashboard#s=p0&a=0<br>
제출방법: cmd창에서 "a < A-large.in > aout.txt" 입력<br><hr><br>
**A. Big Buttons**<br>
```cpp
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
long long math_pow(long long a,long long b);
int main(){
    int T;
    cin>>T;
    for(int tc=1;tc<=T;tc++){
        vector<string> prefixes;
        long long n,p;
        int prefixLen;
        cin>>n>>p;
        for(int i=0;i<p;i++){
            string s;
            cin>>s;
            prefixes.push_back(s);
            prefixLen=prefixes.size();
            for(int j=prefixLen-2;j>=0;j--){
                int smallLen=min(prefixes[prefixLen-1].length(),prefixes[j].length());
                bool check=true;
                for(int k=0;k<smallLen;k++){
                    if(prefixes[prefixLen-1][k]!=prefixes[j][k]){
                        check=false;
                        break;
                    }
                }
                if(check){
                    if(prefixes[prefixLen-1].length()>=prefixes[j].length()){
                        prefixes.erase(prefixes.begin()+prefixLen-1);
                    }
                    else{
                        prefixes.erase(prefixes.begin()+j);
                    }
                    prefixLen--;
                }
            }
        }
        long long ans=pow((long long)2,n);
        for(int i=0;i<prefixLen;i++){
            long long strlen=prefixes[i].length();
            ans-=pow((long long)2,n-strlen);
        }
        cout<<"Case #"<<tc<<": "<<ans<<'\n';
    }
    return 0;
}
```

**B. Mural**<br>
```cpp
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int sum[5000005];
int main(){
    int T;
    cin>>T;
    for(int tc=1;tc<=T;tc++){
        float n;
        cin>>n;
        string str;
        cin>>str;
        char c;
        sum[0]=0;
        for(int i=0;i<n;i++){
            c=str[i];
            sum[i+1]=sum[i]+(c-'0');
        }
        int ans=0;
        int k=ceil(n/2);
        for(int i=0;i<=n-k;i++){
            ans=max(ans,sum[i+k]-sum[i]);
        }
        cout<<"Case #"<<tc<<": "<<ans <<'\n';
    }
    return 0;
}
```