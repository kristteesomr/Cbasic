

#include <stdio.h>
#include <stdlib.h>
int main(){
    int i, n, *p;
    printf("How many numbers do you want to enter?\n");
    scanf("%d", &n);
    p = (int *)malloc(n * sizeof(int));
    if (p == NULL){
    printf("Memory allocation failed!\n");
    return 1;
    }
    /* Nhập các số nguyên */
    printf("Please enter %d numbers:\n",n);
    for(i=0;i<n;i++)
        scanf("%d",&p[i]);
    
    /* Hiển thị chúng theo chiều ngược lại */

    printf("Numbers in reversed order:\n");
    for(i=n;i>=0;i--)
        printf("%d\n",p[i]);

// dùng p+i cũng được

    free(p); /* Giải phóng bộ nhớ */
    return 0;
}