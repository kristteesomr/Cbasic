/*
    bài ở trang 25 (tuần 1): viết một hàm nhận vào biến double, trả về giá trị nguyên của nó và phần thập phân.
    Viết chương trình mà nhận con số do người dùng nhập vào, in ra giá trị nguyên và phần thập phân bằng cách sử dụng hàm trên
    ví dụ người dùng nhập: 3.45 thì phải in ra phần nguyên là 3 và thập phân là 0.45
*/

#include <stdio.h>

void split(double num, int *int_part, double *frac_part){

    *int_part = (int)num;

    *frac_part = num - *int_part;

}

int main(void){

    double num, fraction;
    int integer;

    printf("Please enter a real number: "); scanf("%lf", &num);

    split(num, &integer, &fraction);

    printf("The integer part is %d\n", integer);

    printf("The remaining fraction is %lf\n", fraction);

    return 0;

}