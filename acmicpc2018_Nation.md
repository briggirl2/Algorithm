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