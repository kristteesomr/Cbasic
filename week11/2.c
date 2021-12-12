#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n,*year,*month,*date,*rank;
char **surname,**midname,**name;

int compareRank(int a,int b){
    if(strcmp(name[a],name[b])<0) return 1;
    if(strcmp(name[a],name[b])>0) return 0;
    if(strcmp(midname[a],midname[b])<0) return 1;
    if(strcmp(midname[a],midname[b])>0) return 0;
    if(strcmp(surname[a],surname[b])<0) return 1;
    if(strcmp(surname[a],surname[b])>0) return 0;
    if(year[a]>year[b]) return 1;
    if(year[a]<year[b]) return 0;
    if(month[a]>month[b]) return 1;
    if(month[a]<month[b]) return 0;
    if(date[a]>=date[b]) return 1;
    if(date[a]<date[b]) return 0;
    return 1;
}

void merge(int arr[], int l, int m, int r)
{
    int i,j,k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (compareRank(L[i],R[j])) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int getN(char filename[]){
    char* start=strchr(filename,'-')+1;
    int count=strchr(filename,'.')-start;
    char N[10];
    strncpy(N,start,count);
    N[count]='\0';
    return atoi(N);
}

void initArr(){
    surname=malloc(n*sizeof(char*));
    midname=malloc(n*sizeof(char*));
    name=malloc(n*sizeof(char*));
    year=(int*)malloc(n*sizeof(int));
    month=(int*)malloc(n*sizeof(int));
    date=(int*)malloc(n*sizeof(int));
    rank=(int*)malloc(n*sizeof(int));
    for (int i=0;i<n;i++) {
        surname[i]=(char*)malloc(sizeof(7));
        midname[i]=(char*)malloc(sizeof(6));
        name[i]=(char*)malloc(sizeof(6));
        rank[i]=i;
    }
}

void freeArr(){
    for (int i=0;i<n;i++) {
        free(surname[i]);
        free(midname[i]);
        free(name[i]);
    }
    free(surname);
    free(midname);
    free(name);
    free(year);
    free(month);
    free(date);
    free(rank);
}

int loadFile(char filename[]){
    FILE *f=fopen(filename,"r");
    if (f==NULL) return 1;
    for (int i=0;i<n;i++){
        fscanf(f,"%s %s %s",surname[i],midname[i],name[i]);
        fscanf(f,"%d-%d-%d",&year[i],&month[i],&date[i]);
    }
    fclose(f);
    return 0;
}

void printFile(char filename[]){
    char outfile[50]="sorted-";
    strcat(outfile,filename);
    FILE *f=fopen(outfile,"w");
    for (int i=0;i<n;i++){
        fprintf(f,"%s %s %s\n",surname[rank[i]],midname[rank[i]],name[rank[i]]);
        fprintf(f,"%d-%02d-%02d\n",year[rank[i]],month[rank[i]],date[rank[i]]);
    }
    fclose(f);
}

int main(int argc, char *argv[]){
    n=getN(argv[1]);
    initArr();
    if (loadFile(argv[1])){
        printf("FILE NOT FOUND.");
        return 1;
    }
    mergeSort(rank,0,n-1);
    printFile(argv[1]);
    freeArr();
    return 0;
}