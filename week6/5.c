/*
Vd5 (ngày 2/11)
Viết chương trình C thực hiện các chức năng sau đây:
a) Yêu cầu người dùng nhập vào tên của một file văn bản
b) Giả sử file đó có cấu trúc như sau: dòng đầu tiên là mô tả N, nó chính là số lượng các dòng tiếp theo của file. 
N dòng tiếp theo là các số nguyên. Hãy đọc từng dòng, chuyển các dòng đó sang kiểu int rồi tính tổng. 
Cuối cùng là in ra tổng đó.
Chẳng hạn file đó có nội dung:
3
1
8
3
=> in ra tổng là 12
Gợi ý: có thể dùng hàm atoi để chuyển đổi dữ liệu từ mảng các ký tự sang số nguyên
c) Giả sử file có dạng bố trí tất cả các con số trên cùng một dòng. Hãy tính tổng các con số đó. Gợi ý ta có thể THỬ dùng hàm fscanf

*/


#include <stdio.h>
#include <stdlib.h>

int sumB(int n,FILE *fp){
    int sum=0,i,a;
    char X[256];
    for(i=0;i<n;i++){
        fscanf(fp,"%s",X);
        sum+=atoi(X);
    }
    return sum;
}


int main(){
    char name[256];
    int n;
    printf("nhap ten File:\n");
    scanf("%s", name);
    FILE *fp = fopen(name,"r");
    if(fp==NULL){
        printf("Can not open %s", name);
        return 0;
    }
    else{
        fscanf(fp,"%d",&n);
        printf("\nTong la:%d",sumB(n,fp));
        return 0;
    }
}