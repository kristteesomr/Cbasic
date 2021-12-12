/*
    Đề trang 11: viết một hàm mà nhận 2 mảng số nguyên và trả về 1 nếu chúng bằng nhau và 0 nếu ngược lại. 
    Sau đso viết một chương trình C sao cho nhận hai mảng do người dùng nhập vào và kiểm tra sự bằng nhau.
    chú ý rằng 2 mảng bằng nhau tức là 2 mảng cùng kích thước và phần tử thứ i của mảng A cũng bằng phần tử thứ i của mảng B
    hàm mà ta phải làm ở trang 11 thì hàm đó có 3 tham số
    int compare(int X[ ], int Y[ ], int N)
    với N là kích thước của mảng
*/

/* Copy code tu ppt ra bi loi 
4.c:41:7: error: stray '\213' in program
Cach xu li: copy paste code sang DEV C++ roi xoa cac dau ? di
*/

/*
Trong 1 ham chi co 1 lan return ve gia tri
*/

#include <stdio.h>
#include <string.h>
#define SIZE 5

int compare_arrays(int arr1[], int arr2[], int size){
    int i = 0;
    for (i = 0; i < size; ++i){
        if (arr1[i] != arr2[i])
            return 0;
    }
    /* if we got here, both arrays are identical */
    return 1;
}

int main(){
    int input1[SIZE], input2[SIZE], i;

    printf("Please enter a list of %d integers:\n", SIZE);
    for (i = 0; i < SIZE; ++i) 
        scanf("%d", &input1[i]);
    
    printf("Please enter another list of %d integers:\n", SIZE);
    for (i = 0; i < SIZE; ++i) 
        scanf("%d", &input2[i]);

    if (compare_arrays(input1, input2, SIZE) == 1)
        printf("Both lists are identical!\n");
    else
        printf("The lists are not identical...\n");
    return 0;

}