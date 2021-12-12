/*
Viết chương trình mycat có chức năng tương tự lệnh cat trong Unix sử 
dụng kỹ thuật vào ra theo khối dữ liệu.
❖ Gợi ý: 
▪ Nhận đối số dòng lệnh
▪ Dùng hàm fread
*/
#include <stdio.h>
enum {SUCCESS, FAIL, MAX_LEN = 80};
void BlockCat(FILE *fin) {
    int num;
    char buff[MAX_LEN + 1];
    while (!feof(fin)){ //Nếu chưa đến EOF
    num = fread(buff, sizeof(char), MAX_LEN, fin); // TRUYỀN FILE IN VÀO MẢNG BUFF CÓ DẠNG CHAR KÍCH THƯỚC MAX_LEN 
    buff[num * sizeof(char)] = '\0'; //mảng các ký tự trong C bắt buộc phải có phần tử cuối cùng là '\0' 
    printf("%s", buff);
    }
}

int main(int argc, char* argv[]) {
    FILE *fptr1, *fptr2;
    int reval = SUCCESS;
    if (argc !=2){
        printf("The correct syntax should be: cat1 filename \n");
        reval = FAIL;
    }
    if ((fptr1 = fopen(argv[1], "r")) == NULL){
        printf("Cannot open %s.\n", argv[1]);
        reval = FAIL;
    } 
    else {
        BlockCat(fptr1);
        fclose(fptr1);
    }
    return reval;
}