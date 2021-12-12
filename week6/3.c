/*
Viết chương trình sao chép tập tin (từ lab1.txt sang lab1a.txt) tương tự 
các bài tập trước nhưng sử dụng các thao tác đọc ghi tập tin theo khối 
dữ liệu.
• Sử dụng các hàm: fread, fwrite, feof
*/

#include <stdio.h>

enum {SUCCESS, FAIL, MAX_LEN = 80}; //giống define

void BlockReadWrite(FILE *fin, FILE *fout) {
    int num;
    char buff[MAX_LEN + 1];
    while (!feof(fin)){
        num = fread(buff, sizeof(char), MAX_LEN, fin);
        buff[num * sizeof(char)] = '\0'; //Phần tử cuối cùng cho bằng kết thúc //num*sizeof(char)
        printf("%s", buff);
        fwrite(buff, sizeof(char), num, fout);
    }
}

void BlockReadWrite(FILE *fin, FILE *fout);
int main() {
    FILE *fptr1, *fptr2;
    char filename1[]= "lab1a.txt";
    char filename2[]= "lab1.txt"; //tạo ra file này thì mới chạy được
    int reval = SUCCESS;
    if ((fptr1 = fopen(filename1, "w")) == NULL){
        printf("Cannot open %s.\n", filename1);
        reval = FAIL;
    } 
    else if ((fptr2 = fopen(filename2, "r")) == NULL){
        printf("Cannot open %s.\n", filename2); reval = FAIL;
    } 
    else {
        BlockReadWrite(fptr2, fptr1);
        fclose(fptr1); fclose(fptr2);
    }
    return reval;
}