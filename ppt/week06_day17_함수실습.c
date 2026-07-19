/* 일반 덧셈 */
int add(int a, int b)
{
        return a + b;
}

/* 덧셈 확인 함수 */
void test_add(void)
{
        int result = add(3, 5);
}

/* 양수 오버플로우 안전 덧셈 */
int positive_add_overflow_safe(int a, int b, int int_max)
{
        if (a < 0 || b < 0) return -1;                  /* 에러 코드: 음수 매개변수 */

        if (a > int_max || b > int_max) return -2;      /* 에러 코드: 범위 초과 */

        int max_add_safe_a = int_max - a;               /* a에 오버플로우 없이 더할 수 있는 최대*/

        if (b > max_add_safe_a) return -3;              /* 에러 코드: 덧셈 오버플로우 */

        return a + b;
}

/* 양수 오버플로우 안전 덧셈 확인 함수 */
void test_positive_add_overflow_safe(void)
{
        int int_max = 32767;                            /* int 최대값: 16비트 기준 */
        
        int result_neg = positive_add_overflow_safe(0, -1, int_max);
        int result_big = positive_add_overflow_safe(0, 32768, int_max);
        int result_overflow = positive_add_overflow_safe(1, int_max, int_max);
}

/* 일반 곱셈 */
int multiply(int a, int b)
{
        return a * b;
}

/* 곱셈 확인 함수 */
void test_multiply(int a, int b)
{
        int result = multiply(3, 5);
}

/* 안전 곱셈 (mod의 절대값은 sqrt(INT_MAX) + 1까지 가능) */
int safe_multiply(int a, int b, int mod)
{
        a %= mod;
        b %= mod;
        return (a * b) % mod;
}

/* 안전 곱셈 확인 함수 */
void test_safe_multiply(int a, int b)
{
        int mod = 128;
        int result = safe_multiply(127, 100, mod);
}

/* 덧셈으로 구현한 안전 곱셈 (mod의 절대값은 (INT_MAX / 2) + 1까지 가능) */
int safe_multiply_by_add(int a, int b, int mod)
{
        a %= mod;
        b %= mod;
        a = (a + mod) % mod;
        b = (b + mod) % mod;

        int result = 0;
        for (int i = 0; i < b; i++) {
                result += a;
                result %= mod;
        }

        return result;
}

/* 덧셈으로 구현한 안전 곱셈 확인 함수 */
void test_safe_multiply_by_add()
{
        int mod = 16384;
        int result = safe_multiply_by_add(16383, 84, mod);
}

/* 안전 거듭제곱 (mod의 절대값은 sqrt(INT_MAX) + 1까지 가능) */
int safe_power(int a, int b, int mod)
{
        a %= mod;
        b %= mod;
        a = (a + mod) % mod;
        b = (b + mod) % mod;

        int result = 1;
        for (int i = 0; i < b; i++) {
                result = safe_multiply(result, a, mod);
        }

        return result;
}

/* 안전 거듭제곱 확인 함수 */
void test_safe_power()
{
        int mod = 128;
        int result = safe_power(127, 100, mod);
}

/* 안전 거듭제곱을 안전 덧셈으로 구현 (mod의 절대값은 (INT_MAX / 2) + 1까지 가능) */
int safe_power_by_add(int a, int b, int mod)
{
        a %= mod;
        b %= mod;
        a = (a + mod) % mod;
        b = (b + mod) % mod;

        int result = 1;
        for (int i = 0; i < b; i++) {
                result = safe_multiply_by_add(result, a, mod);
        }

        return result;
}

/* 덧셈으로 구현한 안전 거듭제곱 확인 함수 */
void test_safe_power()
{
        int mod = 16384;
        int result = safe_power(16383, 100, mod);
}
