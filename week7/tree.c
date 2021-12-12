#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char name[256];
    struct Node* leftMostChild;
    struct Node* rightSibling;
}Node;

Node* root; // Tạo ra 1 biến cấu trúc dạng cây root ban đầu

Node* makeNode(char* name){
    // Tạo biến cây p có nội dung là biến name, con trái và phải = NULL
    Node* p = (Node*)malloc(sizeof(Node));
    strcpy(p->name,name);
    p->leftMostChild = NULL;
    p->rightSibling = NULL;
    return p;
}

Node* find(Node* r, char* name){
    //Hàm này là tìm vị trí đỉnh có dữ liệu là name trả về biến cây r 

    if(r == NULL) return NULL; // Nếu biến cấu trúc dạng cây nhập vào hàm ko có dữ liệu => return NULL

    if(strcmp(r->name,name) == 0) return r; // Nếu biến đó giống với dữ liệu ở xâu name => return r

    Node* p = r->leftMostChild; // Khi biến r->name không giống với name -> tạo 1 biến cấu trúc dạng cây p là con bên trái của r
    while(p != NULL){ // Vòng lặp kết thúc khi p đã được điền thông tin
        Node* q = find(p,name); // Tạo biến cấu trúc dạng cây q với dữ liệu cây p và name nhập vào, thực hiện lại hàm find
        if(q != NULL) return q; // Nếu q khác rỗng thì trả về q
        p = p->rightSibling; // Nếu q rỗng thì đặt p là con bên trái của p
    }
}

Node* addLast(Node* p, char*name){ //Thêm con phải vào biến cây có sẵn (Đệ qui đến khi nhập hết dữ liệu)
    if(p == NULL) return makeNode(name); //Nếu root = NULL thì tạo biến cấu trúc dạng cây p, trả kết quả hàm về biến cây p có dữ liệu là name
    p->rightSibling = addLast(p->rightSibling, name); // Con phải của p = biến cây có dữ liệu name // Vòng lặp này vô hạn đến khi nhập xong dữ liệu file vào biến cây chung
    return p;
}

void addChild(char*name, char* child){
    //Thêm con trái cùng vào đỉnh biến cây

    Node* r = find(root,name); //Tìm đỉnh nào có dữ liệu là name

    if(r == NULL) return; //Nếu không có thì ko có gì
    r->leftMostChild = addLast(r->leftMostChild,child);//Nội dung chính của hàm
}

void printTree(Node* r){
    //Hàm này in ra cây với dữ liệu đỉnh parent và các đỉnh con

    if(r == NULL) return; //Nếu cây chưa có gì => không in ra

    printf("%s: ",r->name); // In ra đỉnh đầu của cây
    Node* p = r->leftMostChild;
    while(p != NULL){
        printf("%s ",p->name); // In ra con trái của đỉnh trên
        p = p->rightSibling; 
    }
    printf("\n");
    p = r->leftMostChild;
    while(p != NULL){
        printTree(p);
        p = p->rightSibling;
    }
}

void printTreeF(Node* r, FILE* f){
    // Hàm này nhập ngược dữ liệu từ cây vào file txt 
    if(r == NULL) return;
    fprintf(f,"%s ",r->name);
    Node* p = r->leftMostChild;
    while(p != NULL){
        fprintf(f,"%s ",p->name);
        p = p->rightSibling;
    }
    fprintf(f," $\n");
    p = r->leftMostChild;
    while(p != NULL){
        printTreeF(p,f);
        p = p->rightSibling;
    }
}

void processFind(){
    //
    //Hàm này dùng hàm find và in ra kết quả có đỉnh đó hay không
    char name[256];
    scanf("%s",name);
    Node* p = find(root,name);
    if(p == NULL)
        printf("Not Found %s\n",name);
    else printf("Found %s\n",name);
}

void processFindChildren(){

    // Hàm này dùng hàm find in ra kết quả là các con của đỉnh cây cần tìm
    char name[256];
    scanf("%s",name);
    Node* p = find(root,name);
    if(p == NULL)
        printf("Not Found %s\n",name);
    else{
        printf("Found %s with children: ",name);
        Node* q = p->leftMostChild;
        while(q != NULL){
            printf("%s ",q->name);
            q = q->rightSibling;
        }
    }
    printf("\n");
}

int height(Node* p){

    // Hàm này tính toán độ cao height của 1 đỉnh trong cây 
    // Ví dụ có 3 tầng cây, thì đỉnh ở tầng 1 có độ cao là 3, đỉnh ở tầng 2 có độ cao là 2, đỉnh ở tầng 1 có độ cao là 1
    if(p == NULL) return 0;
    int maxH = 0;
    Node* q = p->leftMostChild;
    while(q != NULL){
        int h = height(q);
        maxH = maxH < h ? h : maxH;
        q = q->rightSibling;
    }
    return maxH + 1;
}

void processHeight(){
    // Hàm này dùng hàm find và height
    // in ra kết quả là độ cao của đỉnh đó so với tầng con cuối cùng
    char name[256];
    scanf("%s",name);
    Node* p = find(root,name);
    if(p == NULL)
        printf("Not Found %s\n",name);
    else
        printf("Found %s having height = %d\n",name,height(p));
}

int count(Node* r){
    //Hàm này tính toán số lượng đỉnh của cả cây root
    if(r == NULL) return 0;
    int cnt = 1;
    Node* q = r->leftMostChild;
    while(q != NULL){
        cnt += count(q);
        q = q->rightSibling;
    }
    return cnt;
}

void processCount(){
    // Hàm này sử dụng hàm count
    // In ra số lượng đỉnh của cả cây root
    printf("Number of members is %d\n",count(root));
}

void processStore(){
    //Hàm này yêu cầu nhập vào kí tự là tên file 
    // Lưu dữ liệu cây vào file mới
    // Sử dụng hàm printTreeF 
    char filename[256];
    scanf("%s",filename);
    FILE* f = fopen(filename,"w");
    printTreeF(root,f);
    fprintf(f,"$$");
    fclose(f);
}

void freeTree(Node* r){
    if(r == NULL) return;
    Node* p = r->leftMostChild;
    while(p != NULL){
        Node* sp = p->rightSibling;
        freeTree(p);
        p = sp;
    }
    printf("free node %s\n",r->name);
    free(r);
    r = NULL;
}

void processLoad(){
    // Nhập vào tên file txt đã chuẩn bị sẵn 
    // Mỗi lần fscanf chỉ nhận vào 1 từ 
    // Đồng bộ hóa dữ liệu từ txt sang dữ liệu kiểu cấu trúc cây xong hàm này là có cây
    // Các dữ liệu sẽ nhập vào cây ban đầu là root
    // Trong hàm này có sử dụng các hàm khác : addLast (Thêm vào con phải), addChild (Thêm vào con trái), find (Tìm đỉnh có dữ liệu cho sẵn)
    char filename[256];
    scanf("%s",filename);
    FILE* f = fopen(filename,"r");

    char Child[256]="",Parent[256]=""; //Gọi 2 xâu child và parent
    Node *p; // Tạo biến cấu trúc dạng cây p

    fscanf(f,"%s",Parent); //Nhập dữ liệu kí tự vào parent
    while(strcmp(Parent,"$$")!=0){ // Vòng lặp dừng lại khi gặp kí tự $$

        p=find(root,Parent); //vòng lặp đầu tiên p = NULL

        if (p==NULL) 
            root=addLast(root,Parent); // Nếu p = NULL thì tạo con phải cho p

        fscanf(f,"%s",Child); // Nhập dữ liệu file vào xâu Child

        while(strcmp(Child,"$")!=0){ //Vòng lặp dừng lại khi gặp $
            addChild(Parent,Child); //Thêm con trái vào biến cây gốc
            fscanf(f,"%s",Child);
        }
        fscanf(f,"%s",Parent);
    }
    fclose(f);
}

void processPrint(){ 
    //Hàm này in ra cây root
    // Sử dụng hàm khác: printTree với dữ liệu nhập vào là root
    printTree(root);
}

void main(){
    while(1){
        char cmd[256];
        printf("Enter command: ");
        scanf("%s",cmd);
        if(strcmp(cmd,"Quit") == 0) break;
        else if(strcmp(cmd,"Load")==0) processLoad();
        else if(strcmp(cmd,"Print")==0) processPrint();
        else if(strcmp(cmd,"Find")==0) processFind();
        else if(strcmp(cmd,"FindChildren")==0) processFindChildren();
        else if(strcmp(cmd,"Height")==0) processHeight();
        else if(strcmp(cmd,"Count")==0) processCount();
        //else if(strcmp(cmd,"AddChild")==0) processAddChild(); //Unimplemented Chức năng thêm đỉnh chưa được thực hiện ở trong này
        else if(strcmp(cmd,"Store")==0) processStore();
    }
    freeTree(root);
}

