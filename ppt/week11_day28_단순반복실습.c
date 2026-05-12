#include <stdio.h>
#include <stdlib.h>

/* 문장 출력 */
void print_str(const char *str)
{
        for (int i = 0; str[i] != '\0'; i++) {
                putchar(str[i]);
        }
}

/* 숫자 출력 */
void print_digit(int digit)
{
        putchar('0' + digit);
}

/* 숫자 두개 출력 00 ~ 99 */
void print_two_digit_leading_zero(int n)
{
        int left_digit = n / 10;
        int right_digit = n % 10;

        print_digit(left_digit);
        print_digit(right_digit);
}

/* 두자리 수 출력 0 ~ 9, 10 ~ 99 */
void print_two_digit_no_leading_zero(int n)
{
        int left_digit = n / 10;
        int right_digit = n % 10;

        if (left_digit > 0) {
                print_digit(left_digit);
        }
        print_digit(right_digit);
}

/* 숫자 세개 출력 000 ~ 999 */
void print_three_digit_leading_zero(int n)
{
        int left_digit = n / 100;
        int right_two_digits = n % 100;

        print_digit(left_digit);
        print_two_digit_leading_zero(right_two_digits);
}

/* 세자리 수 출력 0 ~ 9, 10 ~ 99, 100 ~ 999 */
void print_three_digit_no_leading_zero(int n)
{
        int left_digit = n / 100;
        int right_two_digits = n % 100;

        if (left_digit > 0) {
                print_digit(left_digit);
                print_two_digit_leading_zero(right_two_digits);
        }
        else {
                print_two_digit_no_leading_zero(right_two_digits);
        }
}

/* 숫자 열개 출력 0000000000 ~ 2000000000 */
void print_ten_digit_leading_zero(int n)
{
        int digits[10] = {0};

        /* 배열에 숫자 저장 */
        int base = 1000000000;
        for (int i = 0; i < 10; i++) {
                digits[i] = n / base;
                n = n % base;
                base = base / 10;
        }

        /* 배열에 저장된 숫자 출력 */
        for (int i = 0; i < 10; i++) {
                print_digit(digits[i]);
        }
}

/* 열자리 수 출력 1 ~ 2000000000 */
void print_ten_digit_no_leading_zero(int n)
{
        int digits[10] = {0};

        /* 배열에 숫자 저장 */
        int base = 1000000000;
        for (int i = 0; i < 10; i++) {
                digits[i] = n / base;
                n = n % base;
                base = base / 10;
        }

        /* 출력을 시작할 자리 선정 */
        int i = 0;
        while (digits[i] == 0) {
                i++;
        }

        /* 배열에 저장된 숫자 출력 */
        for (; i < 10; i++) {
                print_digit(digits[i]);
        }
}

/* 음수 출력 -1 ~ -2000000000 */
void print_negatives(int n)
{
        putchar('-');
        print_ten_digit_no_leading_zero(-n);
}

/* int 출력 -2000000000 ~ 2000000000 */
void print_int(int n)
{
        if (n > 0) {
                print_ten_digit_no_leading_zero(n);
        } else if (n < 0) {
                print_negatives(n);
        } else {
                print_digit(0);
        }
}

/* 배열 내용 출력 - 배열 최소 크기 1 */
void print_int_array(int *arr, int arr_size)
{
        putchar('[');
        print_int(arr[0]);

        for (int i = 1; i < arr_size; i++) {
                print_str(", ");
                print_int(arr[i]);
        }

        putchar(']');
}

/* 합계가 target인 두 숫자 구하기 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
        int result_index[2] = {-1, -1};

        for (int i = 0; i < numsSize; i++) {
                for (int j = i + 1; j < numsSize; j++) {
                        if (nums[i] + nums[j] == target) {
                                result_index[0] = i;
                                result_index[1] = j;
                        }
                }
        }

        int *ret = malloc(sizeof(int) * 2);
        ret[0] = result_index[0];
        ret[1] = result_index[1];
        *returnSize = 2;

        return ret;
}

/* 비트 여덟개 출력 00000000 ~ 11111111 */
void print_binary(unsigned char n)
{
        int bits[8] = {0};

        /* 배열에 비트 저장 */
        int base = 128;
        for (int i = 0; i < 8; i++) {
                bits[i] = n / base;
                n = n % base;
                base = base / 2;
        }

        /* 배열에 저장된 비트 출력 */
        print_str("0b");

        for (int i = 0; i < 8; i++) {
                print_digit(bits[i]);
        }
}

/* 비트 여덟개를 양수로 변환 */
unsigned char decode_bit(const char* str)
{
        int bits[8] = {0};

        /* 배열에 비트 저장 */
        for (int i = 0; i < 8; i++) {
                if (str[i] == '\0') {
                        print_str("bit_str_error\n");
                        exit(-1);
                }
                bits[i] = str[i] - '0';
        }

        /* 비트의 정수값 계산 */
        int n = 0;
        int base = 128;

        for (int i = 0; i < 8; i++) {
                n += bits[i] * base;
                base /= 2;
        }

        return n;
}

int main(void)
{
        int nums[5] = {1, 2, 3, 4, 5};
        int numsSize = 5;
        int target = 3;
        int returnSize = 2;

        print_str("nums: ");
        print_int_array(nums, 5);
        print_str("\n");
        
        print_str("target: ");
        print_int(target);
        print_str("\n");

        int *result = twoSum(nums, numsSize, target, &returnSize);

        print_str("result: ");
        print_int_array(result, 2);
        print_str("\n");

        free(result);

        const char encrypted_msg[] = "dzcfs tfdvsjuz";

        char decrypted_msg[30] = {0};

        for (int i = 0; i < 30; i++) {
                if (encrypted_msg[i] == '\0') {
                        decrypted_msg[i] = '\0';
                        break;
                }
                if (encrypted_msg[i] == ' ') {
                        decrypted_msg[i] = ' ';
                        continue;
                }
                decrypted_msg[i] = encrypted_msg[i] - 1;
        }

        print_str(decrypted_msg);
        print_str("\n");

        unsigned char x = decode_bit("00001010");
        unsigned char y = decode_bit("11010011");
        
        print_str("x: ");
        print_binary(x);
        print_str("\n");

        print_str("y: ");
        print_binary(y);
        print_str("\n");

        print_str("x & y: ");
        print_binary(x & y);
        print_str("\n");

        print_str("x | y: ");
        print_binary(x | y);
        print_str("\n");

        print_str("x ^ y: ");
        print_binary(x ^ y);
        print_str("\n");

        print_str("(x ^ y) ^ y: ");
        print_binary((x ^ y) ^ y);
        print_str("\n");

        return 0;
}
