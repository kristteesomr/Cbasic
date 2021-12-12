//PHONE MANAGE DÙNG LINKED LIST

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Address
{
    char name[10];
    char phoneNum[10];
    char email[20];
} adr;
struct Node{
    struct Node *next; // phải là *next thì mới dùng linked list
    adr pAdd;
};
void inputNode(struct Node ** head_node){ //2 sao vì head_node phải gắn pointer để có thể lưu dữ liệu, nếu ko gắn thì sẽ ko lưu được dữ liệu
    struct  Node * new_node = (struct Node *) malloc(sizeof(struct Node)); // Các biến này cũng phải cùng kiểu với next thì mới cho bằng được
    printf("Input owner name: \n");
    scanf("%s", (new_node)->pAdd.name);
    printf("Input phone number of owner: \n");
    scanf("%s", (new_node)->pAdd.phoneNum);
    printf("Input email of owner: \n");
    scanf("%s", (new_node)->pAdd.email);
    new_node->next = (*head_node);
    (*head_node) = new_node; // *head_node = &head_node = &NULL là địa chỉ của NULL, new_node cũng là địa chỉ, cho 2 địa chỉ bằng nhau
}
void printList(struct Node * head_node){ //hàm 1 sao thì head_node là con trỏ luôn lên ko cần dấu gì nữa
    struct Node * temp = head_node; 
    int i = 1;
    while (temp != NULL){ 
        printf("Node %d:\n", i);
        i++;
        printf("Name: %s\n", temp->pAdd.name);
        printf("Phone: %s\n", temp->pAdd.phoneNum);
        printf("Email: %s\n", temp->pAdd.email);
        temp = temp->next;
    }
}
void reverse(struct Node** head_node)
{
    struct Node* prev = NULL;
    struct Node* current = *head_node;
    struct Node* next = NULL;
    while (current != NULL) {
        // Store next
        next = current->next;
 
        // Reverse current node's pointer
        current->next = prev;
 
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    *head_node = prev;
}
struct Node *findNode(struct Node ** head_node){
    char fname[9];
    printf("Input finding name: \n");
    scanf("%s", fname);
    int check = 1;
    struct Node *current_node = (*head_node);
    while (current_node != NULL){
        if (strcmp(fname,current_node->pAdd.name) == 0)
        {
            printf("Phone: %s\n", current_node->pAdd.phoneNum);
            printf("Email: %s\n", current_node->pAdd.email);
            check = 0;
            break;
        }
        current_node = current_node->next;
    }
    if (check == 1) printf("Khong tim thay\n");
    return current_node;
}
struct Node * deleteList(struct Node *head_node){
    struct Node *to_free = head_node ;
    while (to_free != NULL)
    {
         head_node =  head_node->next;
        free(to_free);
        to_free =  head_node;
    }
    return  head_node;
}

int main(){
    struct Node* head_node = NULL;//head_node là biến con trỏ
    int choice;
    printf("1. Thêm một địa chỉ vào đầu danh sách \n");
    printf("2. In ra toàn bộ danh sách\n");
    printf("3. Tìm kiếm danh bạ theo tên, trả về con trỏ đến phần tử tương ứng và in ra số điện thoại và địa chỉ email tương ứng\n");
    printf("4. Đảo ngược danh sách\n");
    printf("5. Xóa toàn bộ danh sách & Thoát khỏi chương trình\n");
    do {
        printf("Input your choice: \n");
        scanf("%d", &choice);
        switch(choice){
            case 1: inputNode(&head_node); break;
            case 2: printList(head_node); break;
            case 3: findNode(&head_node); break;
            case 4: reverse(&head_node); printList(head_node); break;
            case 5: deleteList(head_node); return 0;
            case 6: printf("Goodbye, Sir!\n"); return 0;
        }
    } while(1);

}
