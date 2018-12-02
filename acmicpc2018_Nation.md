## ACM ICPC 2018 _ Nationwide Internet Competition
**A. Black Chain**<br>

1g의 체인 k개로 1~k그램을 만들 수 있다. (k+1)g을 만들기 위해서 (k+1)g의 체인이 필요하다. (k+1)g체인과 1g체인 k개로는 (k+1)+k=2k+1 까지 만들 수 있다.<br><br>
*(k+1) - **1** - (2k+2) - **1** - (4k+4) - **1** -- ... -- **1** - (k+1)*(2^k)*<br><br>

*k2<sup>k</sup>-1 < n <= (k+1)(2<sup>k+1</sup>)-1<br>
k2<sup>k</sup> <= n < (k+1)(2<sup>k+1</sup>)<br>*

```cpp
#include <iostream>
using namespace std;
int main(){
    long long n,k;
    cin>>n;
    for(k=1;(1LL<<k)*k<=n;k++);
    cout<<k-1<<'\n';
    return 0;
}
```

**B. Farm**<br>

```cpp
#include <iostream>
using namespace std;
int main(){
    int a,b,n,w,ans,k=0;
    cin>>a>>b>>n>>w;
    for(int i=1;i<n&&k<2;i++){
        if(a*i+b*(n-i)==w){
            ans=i;
            k++;
        }
    }
    if(k==1)
        cout<<ans<<" "<<n-ans<<'\n';
    else
        cout<<"-1\n";
    return 0;
}
```

**G. Passport Control**<br>

```cpp
#include <iostream>
#include <cstring>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int *out=new int[n];
    for(int i=0;i<n;i++)
        cin>>out[i];
    int *q=new int[k];
    bool ans=true;
    memset(q,0,sizeof(int)*k);
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            if(out[i]>q[j]){
                q[j]=out[i];
                break;
            }
            if(j==k-1){
                ans=false;
                cout<<"NO\n";
                return 0;
            }
        }
    }
    cout<<"YES\n";
    return 0;
}
```