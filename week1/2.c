#include <stdio.h>
#include <string.h>
// ĐẾM SỐ LẦN KÍ TỰ XUẤT HIỆN TRONG 1 XÂU KÍ TỰ
// Coi 1 o trong mang la 1 chu cai, chu so trong o do la so lan xuat hien
#define ALPHABET_LEN 26

int main(){
    int i=0;
    int count[ALPHABET_LEN]={0};
    char c='\0';

    printf("Please enter a line of text: \n");
    c=getchar();
    while(c!='\n' && c>=0){
        if(c<='z' && c>='a')    //QUAN TRONG NHAT
            ++count[c-'a'];     //QUAN TRONG NHAT
        if(c<='Z' && c>='A')    //QUAN TRONG NHAT
            ++count[c-'A'];     //QUAN TRONG NHAT
        c= getchar();
    }

    for(i=0;i<ALPHABET_LEN;i++){
        if(count[i]>0)
            printf("The letter '%c' appears %d time(s).\n", 'a'+i, count[i]);       //QUAN TRONG NHAT
    }
    return 0;

}