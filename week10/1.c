/*
Viết chương trình nhập vào 3 số nguyên n, m, M
In ra dãy n số nguyên bất kì trong khoảng từ m đến M
Lưu vào file input.txt
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){
    int n, m, M, r;
    printf("So nguyen n:"); scanf("%d",&n);
    printf("So nguyen m:"); scanf("%d",&m);
    printf("So nguyen N:"); scanf("%d",&M);

    FILE *fs;
    fs=fopen("input.txt","w");
    fprintf(fs,"%d\n",n);

    srand((int)time(0)); //set random number 

    for(int i = 0; i < n; i++){
        r = m + rand() % (M + 1 - m); // Tìm rand số trong min max
        fprintf(fs,"%d ",r);
    }
}