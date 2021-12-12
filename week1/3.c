#include<stdio.h>
void getData(int *M, int *N){
	printf("Nhap so to cua lop ");
	scanf("%d",M);
	printf("Nhap so thanh vien cua to ");
	scanf("%d",N); 
}

int main(){
    int N,M,i,j,max=0,min=10,k=0;
	getData(&M,&N);
	int D[M][N];
	for (i=0;i<M;i++){
		for (j=0;j<N;j++){
			printf("Nhap so diem cua thanh vien %d to %d ",j,i);
			scanf("%d",&D[i][j]);
		}
	}
    
	for (i=0;i<M;i++)
		if(max < D[i][0])  max=D[i][0];
	printf("Diem cao nhat la %d\n",max); 
	for (i=0;i<M;i++)
		if(min > D[i][1])  min=D[i][1];
	printf("Diem cao nhat la %d\n",min); 
	for (i=0;i<M;i++){
		for (j=0;j<N;j++){
			if(D[0][2]<D[i][j]) k++; 
		}
	}
	printf("So ban cao hon lop truong la %d\n",k); 
}
