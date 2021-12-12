#include <stdio.h>

int main(){
    struct point {
        int x;
        int y;
    };
    struct point my_point = {3,7};
    struct point *p = &my_point;
    printf("%d",(*p).x); // 3
    printf("%d",p->x); // 3
}
