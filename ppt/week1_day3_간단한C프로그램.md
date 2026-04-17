# Presentation: 컴프실_1주차_3회차_조건선택문법_030526.pptx

### 컴프실 1주차 3일차  간단한 C 프로그램


---

### 지난 시간 내용 복습

함수는 명령어 묶음에 이름을 붙인 것으로, 실행 
결과가 있다.
타입은 0과 1의 패턴을 어떻게 해석할지를 정해 
놓은 것이다.
변수는 저장 공간에 이름을 붙인 것이다.


---

### 지난 시간 내용 복습

함수를 만드는 문법
```c
타입    이름     (    입력정보    )
{
        변수선언_또는_문장들
} 
```


---

### 지난 시간 내용 복습

main 함수를 만드는 C 프로그램 코드
```c
int    main     (    void    )
{
        return 0;
} 
```


---

### 지난 시간 내용 복습

수식: 계산 결과가 있는 코드

기본 수식: 가장 간단한 수식

- 숫자
  ```c
  숫자
  ```

- 괄호 안에 다른 수식을 적기
  ```c
  (    수식    )
  ```


---

### 지난 시간 내용 복습

단항 수식: 피연산자가 하나인 수식

- `+` 단항 수식: 값을 그대로 유지
  ```c
  +    단항 수식
  ```

- `-` 단항 수식: 값을 반전
  ```c
  -     단항 수식
  ```


---

### 지난 시간 내용 복습

곱셈 수식: 곱하기, 나누기, 나머지 연산을 하는 수식

- `*` : 곱하기, `/` : 나누기, `%` : 나머지
  ```c
  단항 수식
  곱셈 수식    *    단항 수식
  곱셈 수식    /    단항 수식
  곱셈 수식    %    단항 수식
  ```


---

### 지난 시간 내용 복습

덧셈 수식: 더하기, 빼기 연산을 하는 수식

- `+` : 더하기, `-`: 빼기
  ```c
  곱셈 수식
  덧셈 수식    +    곱셈 수식
  덧셈 수식    -    곱셈 수식
  ```


---

### 지난 시간 내용 복습

변수를 만드는 문법

```c
타입    이름     =    수식    ;
```


---

### 지난 시간 내용 복습

변수를 만드는 코드

```c
int    x     =    0    ;
```


---

### 지난 시간 내용 복습

변수를 만드는 C 프로그램 코드

```c
int main(void) 
{
	int x = 0;
	return 0;
}
```


---

### 지난 시간 내용 복습

변수는 기본 수식에 포함된다.

기본 수식: 

- 변수, 숫자, 괄호

  ```c
  변수
  숫자
  (    수식    )
  ```


---

### 지난 시간 내용 복습

대입 수식: 값을 저장하는 연산을 하는 수식

- `=` : 단순 대입
  ```c
  덧셈 수식
  변수    =    대입 수식
  ```


---

### 문장 또는 선언: 실행되는 단위

```c
return 0;		/* 함수를 종료하고 결과값을 0으로 냄 */
int x = 0;		/* x의 초기값을 0으로 저장 */
```


---

### 수식 문장: 수식을 실행하는 문장

문법은 수식 뒤에 세미콜론 `;`를 붙이는 것이다.

```c
수식    ;
```

수식으로 대입 수식이 주로 쓰인다. 
수식 문장에서 수식의 결과값은 무시된다. 


---

### 조건 문장: 조건에 따라 실행되는 문장

if라는 단어 뒤에 조건과 실행할 내용을 쓴다

```c
if    (    수식    )    {    선언 또는 문장들    }
```

수식의 결과가 **0**이 아니면 문장들이 실행된다.


---

### 예제 1: 변수에 계산 결과 저장하기

```c
int main(void) 
{
        int old_permission = 6;
        int to_remove = 2;
        int new_permission;
        new_permission = old_permission - to_remove;
                new_permission = 7;         
        return 0;
}
```


---

### 예제 2: 나눗셈의 나머지 주의하기

```c
int main(void) 
{
        int total_data = 10;
        int divider = 3;
        int packet_size;
        packet_size = total_data / divider;
        return 0;
}
```


---

### 예제 3: 초기값 주의하기

```c
int main(void) 
{
        int default_value = 100;
        int extra_value;		/* 초기값 없음 */
        int final_value;
        final_value = default_value + extra_value;
        return 0;
}
```


---

### 예제 4: 넘침 현상 주의하기

```c
int main(void) 
{
        int balance = 2000000000;	/* 한계에 근접 */
        balance = balance + balance;
        return 0;
}
```


---

### 예제 5: 변수에 저장된 값 업데이트

```c
int main(void) 
{
        int counter = 10;
        counter = counter + 1;
        counter = counter + 1;
        return 0;
}
```


---

### 예제 6: 연산자 우선순위

```c
int main(void) 
{
        int counter = 12;
	int result;
	result = counter + 2 * 5;
        return 0;
}
```


---

### 예제 7: 음수 나머지 연산 주의

```c
int main(void) 
{
        int position = -10;
	int buffer_size = 3;        
	/* index는 0 ~ 2여야 됨 */	
	int index = position % buffer_size; 	
        return 0;
}
```


---
