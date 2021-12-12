/*
Viết chương trình C in ra menu để người dùng thực hiện các chức năng sau đây:
====Program for management computers====
1) Number of Computers:
2) Update number of cores:
3) Update Ram info:
4) Search:
5) Quit
SV viết được chương trình sao cho in ra menu và nhận lựa chọn của người dùng là 1 giá trị từ 1 đến 5, nếu sai thì thông báo nhập lại (0.5 ĐIỂM). Nếu chương trình thoát khi người dùng nhập 5 thì sinh viên sẽ được thêm (0.5 ĐIỂM).
1) Khi người dùng chọn chức năng 1, chương trình sẽ in ra câu hỏi yêu cầu người dùng nhập giá trị N biểu thị số phần tử của các Computers. Giả sử N < 100. 
CT sau in ra số N vừa nhập (2 ĐIỂM)
2) Khi người dùng chọn chức năng 2.
Chương trình cho phép cập nhật số core của CPU có trong các máy. Đầu tiên chương trình yêu cầu người dùng nhập vào ID của máy muốn nhập, sau đó nhập số core của CPU mới. 
Khi nhập xong một máy thì sẽ tự động yêu cầu nhập cho máy có ID lớn hơn. // Quan trong nhat
Nếu người dùng nhập sai ID (< 1 hoặc > N), hoặc sai số core của CPU, sẽ được yêu cầu nhập lại (Chú ý: CPU chỉ có số core là 2, 4, 6, 8, 10) (0.5 ĐIỂM). 
Giả sử máy có ID thứ x thì sẽ nằm trong phần tử thứ (x - 1) của mảng.
Chức năng này sẽ dừng nếu người dùng đã nhập đến máy có ID lớn nhất (Nếu có N máy thì các ID có giá trị từ 1 đến N) (0.5 ĐIỂM). 
Sau khi kết thúc nhập thì in ra danh sách toàn bộ máy (mỗi máy trên 1 dòng: <ID> <số core>) (2 ĐIỂM).
Chẳng hạn in ra 
1  2
2  2
3  4
4  6
5  10
6  2

*/

#include <stdio.h>
#include <stdlib.h>

void getN(int *N){
    printf("Nhap vao so N bieu thi so phan tu cua cac Computers (N < 100) N="); scanf("%d",N);
    while(*N>=100){
        printf("Nhap lai: So N="); scanf("%d",N);
    }
    printf("N=%d",*N);
}

void UpdateCores(int *n,int *K){
	int i,j;

	printf("Hay nhap so ID "); scanf("%d",&j);
	while(j<1 || j>*n){
		printf("Ban da nhap sai yeu cau nhap lai ");
		scanf("%d",&j);
	}

	for(i=j;i<=*n;i++){
		printf("Update so core cua may tinh ID thu %d: ",i); scanf("%d",&K[i-1]);
        while(K[i-1]%2==1||K[i-1]>10){
		printf("CPU chi co so core 2, 4, 6, 8, 10 \nBan da nhap sai yeu cau nhap lai "); scanf("%d",&K[i-1]);
	    }
	}

	for(i=1;i<=*n;i++){
		printf("%3d %3d \n",i,K[i-1]);
		}
	}

int main(){
    int m=0,n;
    int A[100];
    while(m!=5)
        {
            printf("\nMenu\n1. Numbers of Computers\n2. Update number of cores\n3. Update RAM info\n4. Search\n5. Quit\n");
            scanf("%d",&m);
            switch(m){
                case 1 : 
                    getN(&n); break;
                case 2 : 
                    UpdateCores(&n,A);
                    break;
                case 3 : 
                    break;
                case 4 : 
                    break;
                case 5 : printf("\nThoat chuong trinh !");
                    exit(0);
                default: printf("Hay chon lai");
            }
        }
}
