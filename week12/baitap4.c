// Đề bài: Có file dữ liệu Profile-5.txt, sắp xếp lại danh sách bằng thuật toán heapSort

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256

typedef struct Human{
    int year,month,day;
    char surname[MAX];
    char midname[MAX];
    char name[MAX];
}Human;
Human H[100];

void swap(Human *a, Human *b){
    Human c;
    c= *a;
    *a= *b;
    *b=c;
}


void loadFile(){
    FILE *fp = fopen("Profile-5.txt","r");
    if(fp == NULL){
        printf("Can not open file 'Profile-5.txt'");
        return;
    }
    int i;
    for(i=0 ; i< 100; i++){
        fscanf(fp,"%s %s %s\n",H[i].surname,H[i].midname,H[i].name);
        fscanf(fp,"%d %d %d\n",&H[i].day,&H[i].month,&H[i].year);
    }
    fclose(fp);
}
int compare(Human A,Human B){
    if(strcmp(A.name,B.name)<0) return 1;
    if(strcmp(A.name,B.name)>0) return 0;
    if(strcmp(A.midname,B.midname)<0) return 1;
    if(strcmp(A.midname,B.midname)>0) return 0;
    if(strcmp(A.surname,B.surname)<0) return 1;
    if(strcmp(A.surname,B.surname)>0) return 0;
    if(A.year>B.year) return 1;
    if(A.year<B.year) return 0;
    if(A.month > B.month) return 1;
    if(A.month < B.month) return 0;
    if(A.day >B.day) return 1;
    if(A.day < B.day) return 0;
    return 1;
}

void heapify(Human arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && compare(arr[largest], arr[l]))
        largest = l;

    // If right child is larger than largest so far
    if (r < n && compare(arr[largest], arr[r]))
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
void heapSort(Human arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(&arr[0], &arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

void saveFile(){
    FILE *fp=fopen("Profile-5-output.txt","w");
    int i;
    for(i=0 ;i <100 ;i++){
        fprintf(fp,"%s %s %s\n",H[i].surname,H[i].midname,H[i].name);
        fprintf(fp,"%02d-%02d-%02d\n",H[i].day,H[i].month,H[i].year);
    }
    fprintf(fp,"#");
}
int main(){
    loadFile();
    heapSort(H,99);
    saveFile();
    
}