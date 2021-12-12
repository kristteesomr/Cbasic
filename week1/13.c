/*a) khai báo 2 số nguyên M, N biết rằng M đại diện cho số tổ của một lớp và N đại diện cho số thành viên của tổ đó.
Viết hàm void getData(int *M, int *N) yêu cầu người dùng nhập giá trị từ bàn phím, lưu giá trị vào biến M, N.
Trong hàm main gọi đến hàm getData đó và sau đó in ra giá trị của M, N (2 điểm)
b) Khai báo mảng D là mảng số thực hai chiều kích thước M, N.
Viết 2 vòng lặp for để gán giá trị điểm số của học sinh thuộc tổ i và là thành viên có chỉ số trong tổ là j (i và j bắt đầu từ 0).
Giả sử người dùng luôn nhập đúng giá trị này (điểm luôn >= 0 và <= 10) (2 điểm)
c) Giả sử rằng thành viên có chỉ số (trong tổ) 0 của mọi tổ đều là tổ trưởng (tức mà D[0][0] là điểm của tổ trưởng tổ 0).
Thành viên có chỉ số (trong tổ) 1 của mọi tổ là tổ phó (tức nói đến D[0][1]).
Thành viên ở tổ 0 và là thành viên có chỉ số 2 là lớp trưởng, thành viên cũng tổ đó và là thành viên có chỉ số 3 là lớp phó.
Hãy kiểm tra xem trong số các tổ trưởng, điểm cao nhất là điểm mấy? (2 điểm)
Chẳng hạn ta có danh sách điểm như sau:
D[3][5] = {
{7, 6, 8, 9, 4},
{8, 6, 7, 5, 7},
{9, 8, 6, 7, 5}
};
Thì điểm cao nhất của các tổ trưởng là điểm 9.(2 điểm)
d) Hãy xác định trong các tổ phó, điểm thấp nhất là điểm mấy. Với ví dụ trên thì điểm đó là 6 (2 điểm)
e) Hãy kiểm tra xem trong lớp có bao nhiêu bạn cao điểm hơn bạn lớp trưởng (2 điểm)
Với ví dụ trên thì có 2 bạn cao điểm hơn bạn lớp trưởng*/

#include <stdio.h>
void getData(int *M, int *N){
	printf("Nhap so to cua lop ");
	scanf("%d",M);
	printf("Nhap so thanh vien cua to ");
	scanf("%d",N); 
}

int main(){
    int N,M;
    int max=0,min=10,k=0;
	getData(&M,&N);
	int D[M][N];
	for (i=0;i<M;i++){
		for (j=0;j<N;j++){
			printf("Nhap diem cua thanh vien %d to %d ",j,i);
			scanf("%d",&D[i][j]);
		}
	}

	for (i=0;i<M;i++){
		if(max < D[i][0])  
            max=D[i][0];
    }
	printf("Diem cao nhat trong cac to truong la %d\n",max); 

	for (i=0;i<M;i++){
		if(min > D[i][1])  
            min=D[i][1];
    }
	printf("Diem thap nhat trong cac to pho la %d\n",min); 

	for (i=0;i<M;i++){
		for (j=0;j<N;j++){
			if(D[0][2]<D[i][j]) k++; 
		}
	}
	printf("So ban cao hon lop truong la %d\n",k); 
}

