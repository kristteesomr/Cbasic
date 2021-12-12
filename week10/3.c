/*
Viết chương trình nhập vào 1 dãy số nguyên dương a1, a2, …, an, sắp
xếp dãy đã cho theo thứ tự không giảm bằng thuật toán sắp xếp chèn
• Dữ liệu (stdin)
• Dòng 1: ghi số nguyên dương n (1 ≤ n ≤ 106)
• Dòng 2: ghi a1, a2, …, an, (1 ≤ ai ≤ 106)
• Kết quả (stdout)
• Ghi dãy đã được sắp xếp theo thứ tự không giảm, các phần tử cách
nhau bởi 1 dấu cách

HÀM CHÈN VS HÀM NỔI BỌT BỊ LỖI


hãy đo đạc thời gian bắt đầu sắp xếp (sau khi đọc được input) với n = 100 và m = 1, M = 256
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

void insertionSort(int A[], int N) { //HÀM SẮP XẾP CHÈN
    // index tu 1 -> N
    for(int i = 1; i <= N; i++){
    int last = A[i];
    int j = i-1;
    while(j >= 0 && A[j] >last){
    A[j+1] = A[j];
    j--;
    }
    A[j+1] = last;
    }
}

void bubleSort(int A[], int N) { //SẮP XẾP NỔI BỌT
    // index tu 1 den N
    int swapped;
    do{
        swapped = 0;
        for(int i = 1; i < N; i++){
            if(A[i] > A[i+1]){
                int tmp = A[i];
                A[i] = A[i+1];
                A[i+1] = tmp;
                swapped = 1;
            }
        }
    }while(swapped == 1);
}


void printFile(int *a, int n){
    FILE* fs=fopen("output.txt","w");
    for(int i=0;i<n;i++)
        fprintf(fs,"%d ",a[i]);
    fclose(fs);
}

int main(){
    int n, *p;
    clock_t start, end;   // Khai báo biến thời gian
    double time_use;      // Thời gian sử dụng
    
    p = loadFile(&n);
    if(p==NULL){
        printf("input.txt not found!\n");
        printf("So nguyen n:"); scanf("%d",&n);
        int m, M;
        printf("So nguyen m:"); scanf("%d",&m);
        printf("So nguyen M:"); scanf("%d",&M);
        p=sinhSo(n,m,M);
    }

    
    start = clock();     // Lấy thời gian trước khi thực hiện thuật toán
    insertionSort(p,n);
    //bubleSort(p,n);
    end = clock();  // lấy thời gian sau khi thực hiện 

    time_use = (double)(end - start) / CLOCKS_PER_SEC;    //Tính thời gian sử dụng
    printf("Thoi gian chay thuat toan sap xep: %f",time_use);

    printFile(p,n);
    free(p);

}