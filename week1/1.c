#include <stdio.h>

// REVERSE ORDER
int main(){
    int i, A[10];

    printf("Please enter 10 numbers:\n");
    for(i=0;i<10;i++)
        scanf("%d",&A[i]);

    printf("Numbers in reversed order:\n");
    for(i=9;i>=0;i--)
        printf("%d\n",A[i]);
    return 0;
}

/*
Please enter 10 numbers:
1
2
3
4
5
6
7
8
9
10
Numbers in reversed order:
10
9
8
7
6
5
4
3
2
1
*/
