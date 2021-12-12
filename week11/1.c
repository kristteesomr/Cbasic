

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct nhanvien{
	char ho[10], dem[10], ten[10];
	int ngay, thang, nam;
}NV;
void merge(NV ds[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    NV L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = ds[l + i];
    for (j = 0; j < n2; j++)
        R[j] = ds[m + 1+ j];
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2){
        if (strcmp(L[i].ten, R[j].ten) == -1){
            ds[k] = L[i];
            i++;
        }else if(strcmp(L[i].ten, R[j].ten) == 1){
            ds[k] = R[j];
            j++;
        }else{
	        if (strcmp(L[i].dem, R[j].dem) == -1){
	            ds[k] = L[i];
	            i++;
	        }else if(strcmp(L[i].dem, R[j].dem) == 1){
	            ds[k] = R[j];
	            j++;
	        }else{
	        	if (strcmp(L[i].ho, R[j].ho) == -1){
		            ds[k] = L[i];
		            i++;
		        }else{
		            ds[k] = R[j];
		            j++;
		        }
			}
		}
        k++;
    }
    while (i < n1){
        ds[k] = L[i];
        i++;
        k++;
    }
    while (j < n2){
        ds[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(NV ds[], int l, int r){
    if (l < r){
        int m = l+(r-l)/2;
        mergeSort(ds, l, m);
        mergeSort(ds, m+1, r);
        merge(ds, l, m, r);
    }
}
void inTTDS(NV ds[]){
	printf("\nThong tin danh sach la: \n");
	int i;
	for(i = 0; i < 5; i++){
		printf("%s %s %s\n%d-", ds[i].ho, ds[i].dem, ds[i].ten, 
		ds[i].nam);
		if(ds[i].ngay < 10){
			printf("0%d-", ds[i].ngay);
		}else{
			printf("%d-", ds[i].ngay);
		}
		if(ds[i].thang < 10){
			printf("0%d\n", ds[i].thang);
		}else{
			printf("%d\n", ds[i].thang);
		}
	}
	printf("\n");
}
void docFile(NV *ds){
	int i;
	FILE *f = fopen("profile-n.txt", "r");
	for(i = 0; i < 6; i++){
		fscanf(f, "%s %s %s\n%d-%d-%d\n", &ds[i].ho, &ds[i].dem, &ds[i].ten, 
		&ds[i].nam, &ds[i].ngay, &ds[i].thang);
	}
	fclose(f);
}
void ghiFile(NV *ds){
	int i;
	FILE *f = fopen("Merge-sorted-profile-n.txt", "w");
	for(i = 0; i < 6; i++){
		fprintf(f, "%s %s %s\n%d-%d-%d\n", ds[i].ho, ds[i].dem, ds[i].ten, 
		ds[i].nam, ds[i].thang, ds[i].ngay);
	}
	fprintf(f, "#");
	fclose(f);
}
int main(){
	NV ds[6];
	docFile(ds);
	mergeSort(ds, 0, 5);
	ghiFile(ds);
}