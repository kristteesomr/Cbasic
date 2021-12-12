/*

SẮP XẾP 
Viết chương trình nhập vào 1 dãy số nguyên dương a1, a2, …, an, sắp
xếp dãy đã cho theo thứ tự không giảm bằng thuật toán sắp xếp lựa
chọn
• Dữ liệu (stdin)
• Dòng 1: ghi số nguyên dương n (1 ≤ n ≤ 106)
• Dòng 2: ghi a1, a2, …, an, (1 ≤ ai ≤ 106)
• Kết quả (stdout)
• Ghi dãy đã được sắp xếp theo thứ tự không giảm, các phần tử cách
nhau bởi 1 dấu cách
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int* loadFile(int *n){
    FILE *fs;    
    fs=fopen("input.txt","r");

    if(fs==NULL) 
        return NULL;
    fscanf(fs,"%d",n);

    int *a = (int*)malloc((*n)*sizeof(int));

    for(int i = 0; i < (*n); i++){
        fscanf(fs,"%d",&a[i]);
    }

    fclose(fs);
    return a;
}

int* sinhSo(int n,int m,int M){
    int *a = (int*)malloc(n*sizeof(int));
    srand((int)time(0)); //set random number 

    for(int i = 0; i < n; i++){
        a[i] = m + rand() % (M + 1 - m); // Tìm rand số trong min max
    }
    return a;
}

void selectionSort(int A[], int N) {
    // index tu 1 -> N
    for(int k = 1; k <= N; k++){
        int min = k;
        for(int j = k+1; j <= N; j++){
            if(A[min] > A[j]) min = j;
        }
        int tmp = A[min];
        A[min] = A[k];
        A[k] = tmp;
    }
}

void printFile(int *a, int n){
    FILE* fs=fopen("output.txt","w");
    for(int i=0;i<n;i++)
        fprintf(fs,"%d ",a[i]);
    fclose(fs);
}




int main(){
    int n, *p;
    
    p = loadFile(&n);
    if(p==NULL){
        printf("input.txt not found!\n");
        printf("So nguyen n:"); scanf("%d",&n);
        int m, M;
        printf("So nguyen m:"); scanf("%d",&m);
        printf("So nguyen M:"); scanf("%d",&M);
        p=sinhSo(n,m,M);
    }

    selectionSort(p,n);
    printFile(p,n);
    free(p);

}