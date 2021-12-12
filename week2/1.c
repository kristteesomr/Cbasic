/*
Viết một chương trình C như sau:
a) Yêu cầu người dùng nhập vào từ bàn phím số n, mã nguồn phải kiểm tra bằng vòng lặp while sao cho n phải số lớn hơn hoặc bằng 1 và bé hơn 6. 
Nếu người dùng nhập không đúng thì phải yêu cầu người dùng nhập lại cho đến khi đúng (2 điểm)
b) Yêu cầu người dùng nhập vào n số thực từ bàn phím. Các số được nhập hoàn toàn ngẫu nhiên và giả sử rằng người dùng luôn nhập con số. Các số đó lưu vào mảng X (1.5 điểm)
c) Yêu cầu người dùng nhập vào giá trị số thực lambda. Nếu người dùng nhập lambda trong khoảng (0, 1) thì đó là số hợp lệ. 
Ngược lại thì yêu cầu người dùng nhập cho đến khi đúng (1.5 điểm)
d) Tạo ra mảng Y có n phần tử trong đó phần tử thứ i trong mảng đó sẽ được tìm ra theo công thức đệ quy:
Y[0] = X[0]
Y[k] = (1 - lambda)*Y[k - 1] + lambda*X[k].
In ra các giá trị của mảng Y. 
Chú ý rằng phải nói rõ thứ tự in ra (từ chỉ số 0 trở đi hay từ chỉ số n -1 trở xuống) 
(2 điểm)
e) Yêu cầu người dùng nhập vào một giá trị số thực bất kỳ và in ra số thực đó. (1 điểm)
f) Tính toán lại mảng Y với tham số lambda bằng 0.4, sau đó in ra phần tử cuối cùng của mảng Y. (2 điểm)

*/

#include <stdio.h>

void DeQui(int n, double lambda, float X[]){
    float Y[n];
    Y[0]=X[0];
    printf("Thu tu in ra tu chi so 0 tro di: \nY[0]=%f\n",Y[0]);
    for(int k=1;k<n;k++){
        Y[k] = (1 - lambda)*Y[k - 1] + lambda*X[k];
        printf("Y[%d]=%f\n",k,Y[k]);
    }
}
int main(){
    //Cau a
    int n;
    printf("Nhap so n="); scanf("%d",&n);
    while(n<1||n>=6){
        printf("Nhap lai: So n="); scanf("%d",&n);
    }

    //Cau b
    float X[n];
    for(int i=0;i<n;i++){
        printf("Nhap so thu %d:",i+1); scanf("%f",&X[i]);
    }

    //Cau c
    double lambda;
    printf("Nhap so lambda (0<lambda<1): lambda="); scanf("%lf",&lambda);
    while(lambda>=1||lambda<=0){
        printf("Nhap lai: So lambda="); scanf("%lf",&lambda);
    }

    //Cau d
    DeQui(n,lambda,X);

    //Cau e
    float m;
    printf("Nhap so m="); scanf("%f",&m);
    printf("m=%f\n",m);

    //Cau f
    DeQui(n,0.4,X);





}