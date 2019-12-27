### 유클리드 호제법

* 2개의 자연수의  최대공약수를 구하는 알고리즘<br>
* 호제법: 두 수가 서로 상대방 수를 나누어서 결국 원하는 수를 얻는 알고리즘
* 예시 : 78696과 19332의 최대공약수는 36이다. 

```
 78696 ＝ 19332×4 ＋ 1368
 19332 ＝ 1368×14 ＋ 180
  1368 ＝ 180×7 ＋ 108
   180 ＝ 108×1 + 72
   108 ＝ 72×1 ＋ 36
    72 ＝ 36×2
```
* 최대공약수 코드


``` c++
// 재귀
int gcd(int a, int b) {
	return b? gcd(b, a%b) : a;
}
```
``` c++
// 반복
int gcd(int a, int b) {
	while (b > 0) {
		int tmp = a;
		a = b;
		b = tmp % b;
	}
	return a;
}
```
* 최소공배수 코드

```c++
int lcm(int a, int b) {
	reuturn a * b / gcd(a, b);
}
```

### 에라토스테네스의 체
* 소수구하기 알고리즘

``` c++
for (int i = 2; i * i <= SIZE; i++) {
	if (arr[i] == 0) continue; // arr[i] == 0 이면 이미 합성수로 체크됨. 
	for (int j = i * i; j <= SIZE; j += i) {
		arr[j] = 0;
	}
}
```








