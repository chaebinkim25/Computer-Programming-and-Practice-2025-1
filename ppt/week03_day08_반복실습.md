## 컴프실 3주차 8일차: 반복 실습

---

### 복습: 최대값 구하기 - 좋은 코드

```c
int a = 10, b = 25, c = 15;
int max = a;
if (max < b) { max = b; }
if (max < c) { max = c; }
```

---

### 복습: 최대값 구하기 - 복잡한 코드

```c
if (a > b && a > c) { max = a; }
else if (b > a && b > c) { max = b; }
else { max = c; }
```

- 변수의 개수가 더 많아지면 적용할 수 없다

---

### 복습: 최대값 구하기 - 잘못된 비교 수식

```c
int max = x;
if (max < y) { max = y; }
else if (y < max < z) { max = z; }
```

- 옳은 표현: `y < max && max < z` 로 수정됨

---

### 복습: 최대값 구하기 - 잘못된 로직

```c
int max = x;
if (max < y) { max = y; }
else if (max < z) { max = z; }
else { max = x; }
```

- `x < y < z`인 경우, `max`에 `y`가 저장되는 문제 발생. 
- 비교를 두번은 해야 최대값 결정 가능

---

### 복습: 정렬하기 - 좋은 코드

```c
int a = 3, b = 4, c = 1;
int tmp;
if (a > b) { tmp = a; a = b; b = tmp; }
if (a > c) { tmp = a; a = c; c = tmp; }
if (b > c) { tmp = b; b = c; c = tmp; }
```

---

### 복습: 정렬하기 - 중괄호 누락

```c
if (a > b)  tmp = a; a = b; b = tmp; 
```

- 중괄호가 없으면 if에 관계없이 실행됨

---

### 복습: 정렬하기 - 변수 이름 변경 누락

```c
if (d > e) { tmp = a; a = b; b = tmp; }
```

- 변수 이름 변경이 조건식까지만 되고, 실행 문장에서는 누락됨

---

### 복습: 정렬하기 - 콤마 연산자 사용

```c
if (a > b)  tmp = a, a = b, b = tmp; 
```

- 중괄호를 생략할 때는 한가지 일만 하기

---

### 복습: 정렬하기 - 최소, 중간, 최대값 탐색

- 최소, 중간, 최대값을 구한 후 다시 대입
- 변수 개수가 많아지면 적용하기 어려움

---

### 복습: 구간 분류 - 좋은 코드

```c
int x = 50;
int interval;
if (x < 0) { interval = 1; }
else if (x < 100) { interval = 2; }
else { interval = 3; }
```

---

### 복습: 구간 분류 - 잘못된 비교 수식

```c
else if (0<=x<100) interval=2;
```

- 옳은 방법: `0<=x && x <100`

---

### 복습: 구간 분류 - 잘못된 콤마 사용

```c
else if ( x >= 0, x < 100) interval=2;
```

- 옳은 방법: `x>=0 && x <100`

---

### 복습: 구간 분류 - 중복된 조건 확인

```c
if(x < 0) { interval = 1; }
else if((x >= 0) && (x < 100)){interval=2;}
```

- `x < 0`이 아닐 때 `else if`가 실행되므로, `x >= 0` 없어도 됨

---

### 복습: 가위바위보 - 좋은 코드

```c
int p1 = 0, p2 = 1, result;
if (p1==p2) { result = 0; }
else if (p1-p2 == 1) { result = 1; }
else if (p1-p2 == -1) { result = 2; }
else if (p1-p2 == 2) { result = 2; }
else { result = 1; }
```

---

### 복습: 가위바위보 - 논리 오류

```c
if (p1==p2) { result = 0; }
else if (p1 > p2) { result = 1; }
```

- p1이 보 `2`, p2가 가위 `0`인 경우 잘못된 결과

---

### 복습: 가위바위보 - 대입연산자 오류

```c
if(p1=1){ 
	if(p2=1){r=4;}
```

- `p1`과 `p2`에 값이 대입됨

---

### 복습: 가위바위보 - `else` 문법 오류

```c
else(player2 == 1);
	result =2;
```

- `else`에는 조건이 없고, `else if`를 해서 조건을 씀

- 세미콜론 `;`에 의해 `result =2;`가 항상 실행됨

---

### 복습: 가위바위보 - 중첩과 {} 생략

```c
if(player1==0)
	if(player2==0) result=0;
	else if(player2==1) result=2;
	else result=1;
else if (player==1)
```

- 중괄호 `{}`를 꼭 써주기

---

### 복습: 중단점 만들기

```c
	1	int main(void)
	2	{
●	3		return 0;
	4	}
	5
```

---

### 복습: 디버그 콘솔

```c
	1	int main(void)
	2	{
●	3		return 0;
	4	}
	5
	DEBUG CONSOLE		TERMINAL
	> 1 + 1
```

- 주의: vscode 창의 너비가 충분해야 보인다. 

- 보이지 않을 경우 TERMINAL 오른쪽 ... 클릭

---

### 디버그 기능 - Locals와 Continue 실습

```c
VARIABLES		1	int main(void)
> Locals		2	{
		●	3		int x = 1;
		●	4		int y = 2;
		●	5		int z = 3;
		●	6		return 0;
			7	}
			8
```

---

### 디버그 기능 - WATCH 실습

```c
VARIABLES		1	int main(void)
  Locals		2	{
		●	3		int x = 1;
		●	4		int y = 2;
		●	5		int z = 3;
		●	6		return 0;
WATCH		        7	}
			8
```

---

### 실습1: `for` 문법

```c
VARIABLES		1	int main(void)
  Locals		2	{
			3		int i, count = 0;
			4		for (i=0;i<3;i+=1)
		●	5			count += 1;
		●	6		return 0;
WATCH		        7	}
i < 3		        8
```

---

### 실습1: `for` 문법, `1`부터 `5`까지

```c
VARIABLES		1	int main(void)
  Locals		2	{
			3		int i, count = 0;
			4		for (i=1;i<=5;i+=1)
		●	5			count += 1;
		●	6		return 0;
WATCH		        7	}
i <= 5		        8
```

---

### 실습1: `for` 문법, `5`부터 `1`까지

```c
VARIABLES		1	int main(void)
  Locals		2	{
			3		int i, count = 0;
			4		for (i=5;i>=1;i-=1)
		●	5			count += 1;
		●	6		return 0;
WATCH		        7	}
i >= 1		        8
```

---

### 실습2: 십진수를 이진수로 변환

```c
VARIABLES		1	int main(void)
  Locals		2	{
			3		int dec, i;
			4		int b8, b4, b2, b1;
			5		for (...) {
		●	6			...
WATCH		        7		}
		●	8		return 0;
			9	}
```

---

### 실습3: 피보나치 수열

```c
VARIABLES		1	int main(void)
  Locals		2	{
			3		int n, i;
			4		int x, prev, prev2;
			5		for (...) {
		●	6			...
WATCH		        7		}
		●	8		return 0;
			9	}
```

---

### 실습4: 비밀번호 알아내기

```c
VARIABLES		1	int main(void)
  Locals		2	{
			3		int pw = 1234;
			4		int i, found = -1;
			5		for (...) {
			6			...
WATCH		        7		}
found	●	        8		return 0;
			9	}
```

---

### 실습5: 3-6-9 게임

1부터 50까지 숫자를 숫서대로 반복하면서, 숫자 중 3, 6, 9가 있을 경우, result에 3, 6, 9의 개수를 음수로 저장하고, 없을 경우 숫자를 그대로 저장하는 코드는?
i가 1일 때, result는 1
i가 2일 때, result는 2
i가 3일 때, result는 -1
i가 33일 때, result는 -2

---
