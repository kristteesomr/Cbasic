// size_t fread(void *ptr, size_t size, size_t n, FILE *stream);
// size_t fwrite(const void *ptr, size_t size, size_t n, FILE *stream);
// int feof(FILE *stream);


/*
Cài đặt hàm my_strcat :
• Đầu vào là hai xâu ký tự s1 và s2
• Đầu ra: một con trỏ - trỏ tới vùng nhớ động chứa nội dung là xâu 
kết quả của phép nối hai xâu s1 và s2
• Ví dụ: Phép nối “hello_” và “world!” trả về “hello_world!” 
• Sử dụng kỹ thuật cấp phát bộ nhớ động
• Test your function
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *my_strcat(char *str1, char *str2){
    int len1, len2; char *result;
    len1 = strlen(str1); len2 = strlen(str2);
    result = (char*)malloc((len1 + len2 + 1) * sizeof(char)); //result là xâu kí tự có độ dài mới = len1 + len2 + kí tự EOF
    if (result == NULL) {
        printf("Allocation failed! Check memory\n");
        return NULL;
    }
    strcpy(result, str1); //gán str1 vào result
    strcpy(result + len1, str2); // gán str2 vào vị trí len1 +1 của result
    return result;
}

int main(){
    char str1[20], str2[20];
    char *cat_str;
    printf("Please enter two strings\n");
    scanf("%100s", str1);
    scanf("%100s", str2);
    cat_str = my_strcat(str1, str2);
    if (cat_str == NULL) {
        printf("Problem allocating memory!n");
        return 1;
    }
    printf("The concatenation of %s and %s is %s\n", str1, str2, cat_str);
    free(cat_str);
    return 0;
}

/*
Please enter two strings
hello
_world
The concatenation of hello and _world is hello_world
*/