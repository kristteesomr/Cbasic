/*
    đề trang 19: Viết một hàm sao cho nhận vào một string và hai ký tự. 
    Hàm đó duyệt toàn bộ phần tử của xâu string và thay thế những ký tự thứ nhất bằng ký tự thứ hai. Chẳng hạn xâu "abba" và 2 ký tự tham số là 'a' và 'c'
    thì xâu đầu vào sẽ có nội dung là "cbbc"
    viết một chương trình để kiểm tra hàm trên , CT sẽ yêu cầu người dùng nhập xâu, nhập hai ký tự và gọi hàm trên để thay thế các ký tự trong xâu
    vd: gõ "papa", 'p', 'm'; kết quả in ra của CT sẽ là "mama"
*/

#include <stdio.h>
#include <string.h>
#define SIZE 10

int main(){
    char str[SIZE];
    char a,b;
    
    gets(str);
    fflush(stdin);
    a = getchar();
    fflush(stdin);
    b = getchar();
    fflush(stdin);

    for(int i=0;i<SIZE;i++){
        if(str[i]==a){
           str[i] = b;
        }
    printf("%c",str[i]); // phai la %c chu khong phai la %s
    }



}