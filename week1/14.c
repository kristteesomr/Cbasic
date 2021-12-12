/*
a) khai báo số nguyên N. Viết hàm void getData(int *N) yêu cầu người dùng nhập giá trị từ bàn phím, lưu giá trị vào biến N. Trong hàm main gọi đến hàm getData đó và sau đó in ra giá trị của N (2 điểm)
b) Khai báo 2 mảng các số thực X, Y với số lượng các phần tử là N. Hãy viết vòng lặp for (biến đếm i lặp từ 0 đến N - 1) thực hiện việc gán giá trị tọa độ x, y cho điểm thứ i. 
Tọa độ x sẽ lưu vào X[i] còn toạ độ y sẽ lưu vào Y[i] (2 điểm)
c) Viết hàm void getVertices(float x, float y, float width, float length) thực hiện việc in ra tọa độ 4 đỉnh của một hình chữ nhật có tâm là điểm tọa độ (x, y). 
Cạnh theo chiều ngang của hình chữ nhật này là width, cạnh theo chiều dài của nó là length. Giả sử hình chữ nhật này luôn có cạnh song song với trục tọa độ (2 điểm)
d) Viết vòng lặp for thực hiện lặp N lần (biến i chạy từ 0 đến N - 1) sao cho nó gọi hàm getVertices và in ra tọa độ 4 đỉnh của hình chữ nhật có tâm là X[i], Y[i]. 
Biết width = 2 và length = 6 (2 điểm)
e) Sửa lại hàm main sao cho nó yêu cầu người dùng nhập vào hai giá trị pX, pY kiểu float. Đây sẽ là hai tọa độ theo trục Ox, Oy của một điểm. (1 điểm)
f) viết hàm void checkColliance(float pX, float pY, float x, float y, float width, float length). 
Hàm này sẽ in ra thông báo nếu điểm p(pX, pY) nằm trong lòng của hình chữ nhật có tọa độ tâm (x, y) (1 điểm)
Tư tưởng pX >= xMin (tọa độ x nhỏ nhất) và pX <= xMax (tọa độ x lớn nhất)
pY >= yMin (tọa độ y nhỏ nhất) và pY <= yMax (tọa độ y lớn nhất)
*/

#include <stdio.h>

void getData(int *N){
    printf("Nhap so N:"); scanf("%d",N);
}

void getVertices(float x, float y, float width, float length){
    float xA, yA, xB, yB, xC, yC, xD, yD;
    xD=(2*x-width)/2;
    yD=(2*y-length)/2;
    xA= xD;
    yA= yD+length;
    xB= xD+width;
    yB=yD+length;
    xC=xD+width;
    yC=yD;
    printf("\nToa do 4 dinh HCN co tam la diem I(%f,%f) la:\n",x,y);
    printf("\nA(%f,%f), B(%f,%f), C(%f,%f), D(%f,%f)",xA,yA,xB,yB,xC,yC,xD,yD);
}

void checkColliance(float xP, float yP, float x, float y, float width, float length){
    float xA, yA, xB, yB, xC, yC, xD, yD;
    xD=(2*x-width)/2;
    yD=(2*y-length)/2;
    xA= xD;
    yA= yD+length;
    xB= xD+width;
    yB=yD+length;
    xC=xD+width;
    yC=yD;
    printf("\nToa do 4 dinh HCN co tam la diem I(%f,%f) la:\n",x,y);
    printf("\nA(%f,%f), B(%f,%f), C(%f,%f), D(%f,%f)",xA,yA,xB,yB,xC,yC,xD,yD);

    if((xD<=xP<=xD+width)&&(yD<=yP<=yD+length))
        printf("\nDiem P nam trong HCN ABCD tren.");
    else 
        printf("\nDiem P khong nam trong HCN ABCD tren.");

}

int main(){
    int N;
    getData(&N);

    for(int i=0;i<N;i++){
        getVertices(i,i,2,6);
    }

    float xP, yP;
    printf("\nNhap toa do x cua diem P: xP="); scanf("%f",&xP);
    printf("\nNhap toa do y cua diem P: yP="); scanf("%f",&yP);

    checkColliance(xP,yP,4,6,2,6);
}

/*
Nhap so N:3

Toa do 4 dinh HCN co tam la diem I(0.000000,0.000000) la:

A(-1.000000,3.000000), B(1.000000,3.000000), C(1.000000,-3.000000), D(-1.000000,-3.000000)
Toa do 4 dinh HCN co tam la diem I(1.000000,1.000000) la:

A(0.000000,4.000000), B(2.000000,4.000000), C(2.000000,-2.000000), D(0.000000,-2.000000)
Toa do 4 dinh HCN co tam la diem I(2.000000,2.000000) la:

A(1.000000,5.000000), B(3.000000,5.000000), C(3.000000,-1.000000), D(1.000000,-1.000000)
Nhap toa do x cua diem P: xP=1

Nhap toa do y cua diem P: yP=2

Toa do 4 dinh HCN co tam la diem I(4.000000,6.000000) la:

A(3.000000,9.000000), B(5.000000,9.000000), C(5.000000,3.000000), D(3.000000,3.000000)
Diem P nam trong HCN ABCD tren.
*/