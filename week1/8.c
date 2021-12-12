#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    int k;
    char article[5][5] = {"the","a","one","some","any"};
    char article1[5][5] = {"The","A","One","Some","Any"};

    char noun[5][5] = {"boy","girl","dog","town","car"};
    char verb[5][10] = {"drove","jumped","ran","walked","skipped"};
    char preposition[5][6]= {"to","from","over","under","on"};

    for(int i=0;i<10;i++){
        k = rand() %5;
        printf("%s ", article1[k]);
        k = rand() %5;
        printf("%s ", noun[k]);
        k = rand() %5;
        printf("%s ", verb[k]);
        k = rand() %5;
        printf("%s ", preposition[k]);
        k = rand() %5;
        printf("%s ", article[k]);
        k = rand() %5;
        printf("%s.\n", noun[k]);
    }

 
}