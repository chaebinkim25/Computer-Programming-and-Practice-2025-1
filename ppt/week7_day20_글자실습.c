#include <stdio.h>

/* getchar 함수 실행해보기 */
int main_part0(void)
{
        int key = getchar();
        return 0;
}

/* 엔터 키 입력 확인하기 */
int main_part1(void)
{
        int key1 = getchar();
        int key2 = getchar();
        return 0;
}

/* 화면에 글자 출력하기 */
int main_part2(void)
{
        putchar(97);
        return 0;
}

/* 화면에 abc를 출력하기 */
int main_part3(void)
{
        putchar('a');
        putchar('b');
        putchar('c');
        return 0;
}

/* 입력받은 키를 그대로 출력하기. 'q'를 누르면 종료하기 */
int main_part4(void)
{
        for (;;) {
                int key = getchar();
                putchar(key);
                if (key == 'q') {
                        break;
                }
        }
        return 0;
}

/* 특수 기호를 화면에 출력하기 */
int main_part5(void)
{
        putchar('\'');
        putchar('a');
        putchar('\'');
        putchar('\n');
        putchar('\'');
        putchar('\\');
        putchar('t');
        putchar('\'');
        return 0;
}

/* 화면에 *로 직각삼각형 출력하기 */
int main_part6(void)
{
        for (int row = 0; row < 10; row++) {
                for (int col = 0; col <= row; col++) {
                        putchar('*');
                }
                putchar('\n');
        }
        return 0;
}

/* 화면에 *로 직각삼각형 거꾸로 출력하기 */
int main_part7(void)
{
        for (int row = 0; row < 10; row++) {
                for (int col = 0; col < 10 - row; col++) {
                        putchar('*');
                }
                putchar('\n');
        }
        return 0;
}

/* 화면에 *로 이등변삼각형 출력하기 */
int main_part8(void)
{
        for (int row = 0; row < 10; row++) {
                for (int col = 0; col < 10 - row; col++) {
                        putchar(' ');
                }
                for (int col = 0; col <= 2 * row; col++) {
                        putchar('*');
                }
                putchar('\n');
        }
        return 0;
}

/* 화면에 Hello, world를 출력하기 */
int main_part9(void)
{
        char str[] = "Hello, world";
        for (int i = 0; str[i] != '\0'; i++) {
                putchar(str[i]);
        }
        return 0;
}
