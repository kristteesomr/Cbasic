/*
Viết một chương trình C như sau:
a) Hiện ra một menu trong đó có các dòng sau:
1. Nhap vao so N (4 <= N <= 10)
2. Nhap vao mang N phan tu la cac diem co toa do (x, y)
3. Kiem tra hai diem lien tiep co tao thanh canh song song truc toa do khong?
4. Thoat
(2 điểm)
b) Viết hàm cài đặt chức năng (1) sao cho người dùng nhập được đúng giá trị của N thì thôi. Nếu nhập sai thì yêu cầu nhập lại. 
Hàm này nên có tên là void getN(int *N);
(1 điểm)
c) Viết hàm cài đặt chức năng (2) với prototype của hàm như sau:
void getArray(float X[], float Y[], int N); 
(1 điểm)
d) Viết vòng lặp while cho phép người dùng nhập vào các tùy chọn để thực hiện các chức năng của menu trên. 
Nếu người dùng nhấn 2 thì cần kiểm tra điều kiện sau:
Chức năng 2 chỉ thực hiện được nếu chức năng 1 đã được thực hiện. Vậy trong trường hợp chưa bao giờ thực hiện chức năng 1 mà đã thực thi chức năng 2 thì CT phải in ra câu “Hay thuc hien chuc nang 1” và yêu cầu người dùng nhập lại
Nếu chức năng 1 đã được thực thi (tức N đã được gán) thì gọi hàm đã làm ở câu (c) (2 điểm)
e) Cũng tương tự như trên nhưng kiểm tra xem:
nếu người dùng nhấn 3 thì chức năng (2) và chức năng (1) cần được thực hiện từ trước. Nếu hai chức năng đó chưa đươc thực hiện bao giờ thì phải in ra câu “Hay thuc hien chuc nang 1 va 2” rồi yêu cầu người dùng nhập lại
Còn nếu chức năng (2) và (1) đã được thực hiện rồi thì chức năng (3) hiện tại chỉ cần in ra “3 is done” (2 điểm)
f) Cài đặt hàm int checkArray(float X[ ], float Y[ ], int N);
Kiểm tra xem hai điểm liên tiếp có tọa độ (X[i], Y[i]) và (X[i+1], Y[i+1]) có tạo ra cạnh song song với trục tọa độ hay không? Nếu tất cả các điểm đều thỏa mãn điều kiện trên thì trả về 1, ngược lại trả về 0 (1 điểm)
g) Cài đặt chức năng thoát (1 điểm)
Gợi ý chức năng 1 được coi là chưa được thực hiện nếu như N vẫn bằng một giá trị lúc khai báo (nói cách khác, lúc ta khai báo N thì ta nên gán N bằng một giá trị âm)
Gợi ý chức năng 2 được coi là chưa được thực hiện nếu như tất cả các phần tử của mảng X và mảng Y có giá trị bằng nhau và bằng 0

*/
#include <stdio.h>
#include <stdlib.h>
void getN(int *N){
    printf("Nhap vao so N (4 <= N <= 10) N="); scanf("%d",N);
    while(*N<4||*N>10){
        printf("Nhap lai: So N="); scanf("%d",N);
    }
}

int getArray(float X[], float Y[], int N){
    for(int i=0;i<N;i++){
        printf("Nhap toa do x cua diem thu %d: x%d=",i+1,i+1); scanf("%f",&X[i]);
        printf("Nhap toa do y cua diem thu %d: y%d=",i+1,i+1); scanf("%f",&Y[i]);
    }
}

int checkArray(float X[], float Y[], int N){
    int j=0;
    for(int i=0;i<N;i++){
        if(X[i]==X[i+1]||Y[i]==Y[i+1]) 
            j++;
    }
    if(j==N-1) {
        printf("Cac diem lien tiep deu song song voi cac truc toa do");
        return 1;
    }
    else {
        printf("Cac diem lien tiep khong song song voi cac truc toa do");
        return 0;
    }
}

int main(){
    int N=11;
    int m=0;
    int k=0;
    float X[N],Y[N];
    while(m!=4)
        {
            printf("\nMenu\n1. Nhap vao so N (4 <= N <= 10)\n2. Nhap vao mang N phan tu la cac diem co toa do (x, y)\n3. Kiem tra hai diem lien tiep co tao thanh canh song song truc toa do khong?\n4. Thoat\n");
            scanf("%d",&m);
            switch(m){
                case 1 : 
                    getN(&N); break;
                case 2 : 
                    if(N==11) 
                        printf("Hay thuc hien chuc nang 1");
                    else {
                        getArray(X,Y,N);
                        k=1;
                    }
                    break;
                case 3 : 
                    if(k==1){
                        checkArray(X,Y,N);
                        printf("\n3 is done");
                    }
                    else 
                        printf("Hay thuc hien chuc nang 2");
                    break;
                case 4 : printf("\nThoat chuong trinh !");
                    exit(0);
                default: printf("Hay chon lai");
            }
        }
}

/*
Menu
1. Nhap vao so N (4 <= N <= 10)
2. Nhap vao mang N phan tu la cac diem co toa do (x, y)
3. Kiem tra hai diem lien tiep co tao thanh canh song song truc toa do khong?
4. Thoat
3
Hay thuc hien chuc nang 2
Menu
1. Nhap vao so N (4 <= N <= 10)
2. Nhap vao mang N phan tu la cac diem co toa do (x, y)
3. Kiem tra hai diem lien tiep co tao thanh canh song song truc toa do khong?
4. Thoat
2
Hay thuc hien chuc nang 1
Menu
1. Nhap vao so N (4 <= N <= 10)
2. Nhap vao mang N phan tu la cac diem co toa do (x, y)
3. Kiem tra hai diem lien tiep co tao thanh canh song song truc toa do khong?
4. Thoat
1
Nhap vao so N (4 <= N <= 10) N=4

Menu
1. Nhap vao so N (4 <= N <= 10)
2. Nhap vao mang N phan tu la cac diem co toa do (x, y)
3. Kiem tra hai diem lien tiep co tao thanh canh song song truc toa do khong?
4. Thoat
2
Nhap toa do x cua diem thu 1: x1=3
Nhap toa do y cua diem thu 1: y1=4
Nhap toa do x cua diem thu 2: x2=3
Nhap toa do y cua diem thu 2: y2=5
Nhap toa do x cua diem thu 3: x3=4
Nhap toa do y cua diem thu 3: y3=5
Nhap toa do x cua diem thu 4: x4=4
Nhap toa do y cua diem thu 4: y4=7

Menu
1. Nhap vao so N (4 <= N <= 10)
2. Nhap vao mang N phan tu la cac diem co toa do (x, y)
3. Kiem tra hai diem lien tiep co tao thanh canh song song truc toa do khong?
4. Thoat
3
Cac diem lien tiep deu song song voi cac truc toa do
3 is done
Menu
1. Nhap vao so N (4 <= N <= 10)
2. Nhap vao mang N phan tu la cac diem co toa do (x, y)
3. Kiem tra hai diem lien tiep co tao thanh canh song song truc toa do khong?
4. Thoat
4

Thoat chuong trinh !
*/