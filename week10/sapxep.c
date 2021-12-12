#include <stdio.h>
#include <stdlib.h>

int ngaunhien(int minN, int maxN){
    return minN + rand() % (maxN + 1 - minN);
}

void sxluachon(int a[], int N){
    for(int k=0; k<N; k++){
        int min = k;
        for(int j=k+1; j<N; j++){
            if (a[min]>a[j]) min=j;
        }
        int tam=a[min];
        a[min] = a[k];
        a[k]= tam;
    }
}

void sxchen(int a[], int N){
    for(int k=1; k<N; k++){
        int last=a[k];
        int j=k;
        while(j>0 && a[j-1] > last){
            a[j]=a[j-1];
            j--;
        }
        a[j]=last;
    }
}

void sxnoibot(int a[], int n){
    int swapped;
    do{
        swapped=0;
        for(int i=0; i<n; i++){
            if(a[i]>a[i+1]){
                int tam=a[i];
                a[i]=a[i+1];
                a[i+1]=tam;
                swapped=1;
            }
        }
    } while(swapped==1);
}

int main(){
    FILE* f=fopen("sapxep.txt", "w");
    int n, m, M, a[1000];
    printf("Nhap n = ");
    scanf("%d",&n);
    printf("m = "); scanf("%d",&m);
    printf("M = "); scanf("%d",&M);
    for(int i=0; i<n; i++){
        a[i]=ngaunhien(m, M);
        printf("%d ", a[i]);
        fprintf(f, "%d ", a[i]);
    }
    fclose(f);
    sxluachon(a, n);
    //sxchen(a, n);
    //sxnoibot(a, n);
    printf("\n");
    for (int i=0; i<n; i++) printf("%d ", a[i]);
    return 0;
}