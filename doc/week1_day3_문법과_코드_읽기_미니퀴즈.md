## 문법과 코드 읽기

- 함수를 만드는 문법은?

- 타입에 해당하는 C 언어 단어는?

- 변수를 만드는 문법은?

- 문장이란?

- 수식 문장이란?

- 조건 문장이란?

- 다음 C 프로그램의 `main` 함수에서 `return`하기 전, `new_permission`에
저장된 값은?

```c
int main(void)
{
        int old_permission = 6;
        int drop = 2;
        int new_permission;
        new_permission = old_permission - drop;
        new_permission = 7;
        return 0;
}
```

- 다음 C 프로그램의 `main` 함수에서 `return`하기 전, `packet_size`에 저장된
값은?

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

- 다음 C 프로그램의 `main` 함수에서 `return`하기 전, `final_value`에 저장된
값은?

```c
int main(void)
{
        int default_value = 100;
        int extra_value; /* 초기값 없음 */
        int final_value;
        final_value = default_value + extra_value;
        return 0;
}
```

- 다음 C 프로그램의 `main` 함수에서 `return`하기 전, `balance`에 저장된 값은?

```c
int main(void)
{
        int balance = 2000000000; /*거의 한계*/
        balance = balance + balance;
        return 0;
}
```

- 다음 C 프로그램의 `main` 함수에서 `return`하기 전, `counter`에 저장된 값은?

```c
int main(void)
{
        int counter = 10;
        counter = counter + 1;
        counter = counter + 1;
        return 0;
}
```

- 다음 C 프로그램의 `main` 함수에서 `return`하기 전, `result`에 저장된 값은?

```c
int main(void)
{
        int counter = 12;
        int result;
        result = counter + 2 * 5;
        return 0;
}
```

- 다음 C 프로그램의 `main` 함수에서 `return`하기 전, `index`에 저장된 값은?

```c
int main(void)
{
        int position = -10;
        int buffer_size = 3;
        /* index는 0 \~ 2여야 됨 */
        int index = position % buffer_size;
        return 0;
}
```

