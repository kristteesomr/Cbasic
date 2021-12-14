// Đề bài: Có file dữ liệu Profile-5.txt, sắp xếp lại danh sách bằng thuật toán quickSort

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

int partition(Human A[],int L,int R,int indexPivot){
    Human pivot =A[indexPivot];
    swap(&A[indexPivot],&A[R]);
    int storeIndex=L,i;
    for(i=L;i< R ; i++){
        if(compare(A[i],pivot)){
            swap(&A[storeIndex],&A[i]);
            storeIndex++;
        }
    }
    swap(&A[storeIndex],&A[R]);
    return storeIndex;
}
void quickSort(Human A[],int L,int R){
    if(L<R){
        int index=(L+R)/2;
        index= partition(A,L,R,index);
        if(L < index){
            quickSort(A,L,index-1);
        }
        if(index < R){
            quickSort(A,index+1,R);
        }
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
    quickSort(H,0,99);
    saveFile();
    
}