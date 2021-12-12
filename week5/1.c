/*
Viết chương trình C in ra menu để giúp người dùng thực hiện các chức năng sau:
====Program for management car parking====
1) Numbers of Parking lot & columns:
2) Insert new car:
3) Search:
4) Remove a car:
5) Quit
SV viết được chương trình sao cho in ra menu (1 ĐIỂM) và nhận lựa chọn của người dùng là một giá trị từ 1 đến 5, nếu sai thì thông báo nhập lại (0.5 ĐIỂM). 
Nếu chương trình thoát khi người dùng nhập 5 thì sinh viên sẽ được thêm (0.5 ĐIỂM).
1) Khi người dùng chọn chức năng 1, chương trình sẽ in ra câu hỏi yêu cầu người dùng nhập giá trị N < 100 biểu thị số ô đỗ của xe. 
Và còn yêu cầu nhập thêm số C là số cột để đậu xe

10 xe 5 cột
X X X X X
X X X X X

Như hình vẽ trên, có tất cả N = 10 ô đỗ và C = 5 cột
Sau khi nhập xong thì in ra thông báo về số ô đỗ, số hàng đậu xe và số cột để đậu xe (2 ĐIỂM)

2) Yêu cầu người dùng nhập vào một xe muốn nằm trong ô đỗ, biết rằng sẽ sắp xếp theo kiểu Stack: nếu có R chỗ trống trong một cột thì xe phải đặt ở ô đỗ dưới cùng trước. 
Giả sử cách chọn cột để đỗ xe như sau: chọn ưu tiên từ trái sang phải. Nếu cột nào đầy thì được phép xếp sang cột sau.
Ở đây xe có thông tin như sau: char name[256] (biển số), int year (năm sản xuất), char brand[256] (nhãn hiệu của xe)
Nếu trường hợp không còn ô đỗ nào trống thì bắt buộc phải báo cho người dùng rằng tất cả các ô đều đầy. (1 ĐIỂM)
Nếu SV viết được mã nguồn cho phép nhập vào một xe trong khi vẫn còn ô đỗ thì SV được 1 ĐIỂM.
Khi nhập xong một xe, in ra thông tin về các xe trong bãi. Chẳng hạn như sau:

X _ _ _
X X _ _

In ra được thông tin như trên (1 ĐIỂM)
Chú ý ta không cần kiểm tra xem các biển số xe có bị trùng nhau hay không? (NÊN DÙNG THEO MẢNG)
3) Yêu cầu người dùng nhập thông tin biển số xe, rồi tìm kiếm để ra được vị trí đặt xe (hàng nào, cột nào) cũng như năm sản xuất và nhãn hiệu của xe (1.5 ĐIỂM)
Nếu trong bãi không có xe nào như vậy thì in ra thông báo rồi quay lại menu chính. (0.5 ĐIỂM)
4) Yêu cầu người dùng nhập thông tin biển số xe, rồi di chuyển xe đó ra khỏi ô đỗ. 
Nếu sau khi di chuyển mà các ô đỗ cùng cột đó vẫn còn chỗ trống thì sẽ lấy một xe ở cột bên cạnh cho vào.
Nếu trong bãi không có xe nào như vậy thì in ra thông báo rồi quay lại menu chính.
Ví dụ trước khi di chuyển các xe có bố trí như sau:
X  _ _ _
X X _ _
Nếu ta di chuyển một xe ở cột đầu tiên, thì sau đó, các xe sẽ được bố trí như sau
X  _ _ _
X  _ _ _
(1 ĐIỂM)
Chi tiết barem câu (4) như sau:
Yêu cầu của câu (4) là SV nếu in ra được thông báo khi không có xe nào trùng với biển được nhập thì được 0.5 ĐIỂM
nếu in ra được bố trí xe trước khi di chuyển thì được 0.25 ĐIỂM
nếu in ra được bố trí xe sau khi di chuyển thì được 0.25 ĐIỂM
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
STACK
LAST IN FIRST OUT VÀO SAU RA TRƯỚC
isEmpty: kiểm tra xem stack có rỗng hay không
Push: thêm 1 đối tượng vào đầu stack 
Pop: lấy 1 đối tượng ở đầu stack và trả về giá trị của đối tượng đó, sau đó xóa đối tượng đó ra khỏi stack
Top: trả về đối tượng đầu stack
*/

//Khai báo cấu trúc Node
typedef struct Node{ // Một node
	char plate[256];
	int year;
	char brand[256];
	struct Node* next; // con trỏ liên kết các node 
} *node_t; // Sử dụng con trỏ hàm để lưu giá trị trong quá trình sử dụng trong các hàm khác nhau

//Khai báo cấu trúc Stack
typedef struct Stack{ // Hàng chờ 
	int count; //biến đếm có bao nhiêu node trong stack // struct không cho khởi tạo giá trị ko thể cho count = 0
	struct Node* top; // con trỏ đầu để quản lí stack
	struct Stack* next; // con trỏ liên kết các stack với nhau
} *stack_t; // Sử dụng con trỏ hàm để lưu giá trị trong quá trình sử dụng trong các hàm khác nhau

//Khởi tạo stack mới
stack_t makeStack(stack_t *s,int *number){
    stack_t new_stack = (stack_t) malloc(sizeof(struct Stack)); // Các biến này cũng phải cùng kiểu với next thì mới cho bằng được
    new_stack->top = NULL; //Khởi tạo phần tử node top = 0
    new_stack->next = NULL; //Tạo liên kết với stack sau
    new_stack->count = 0; //Số lượng node trong stack cho bằng 0 vì ko khởi tạo được ở trong struct
    *s = new_stack; // Cho stack hiện tại  đang xử lí s = stack vừa mới lập
    *number ++; // số lượng stack hiện tại tăng lên 1
    return *s;
} 

// Kiểm tra xem stack có rỗng không
int stackEmpty(stack_t s){
    if(s->top == NULL){ //trả về 1 nếu stack rỗng
        return 1;
    }
    return 0;
} 

//Kiểm tra stack có full không
int stackFull(stack_t s, int *R){
    if(s->count == *R)
        return 1;
    else 
        return 0;
} //trả về 1 nếu stack full

//Hàm khởi tạo node
node_t makeNode(node_t *head){ //Dùng con trỏ của con trỏ để lưu được thông tin
    node_t new_node = (node_t) malloc(sizeof(struct Node)); // Các biến này cũng phải cùng kiểu với next thì mới cho bằng được
    printf("Input car number plate: \n");
    scanf("%s", new_node->plate);
    printf("Input year of manufacture: \n");
    scanf("%d", &new_node->year);
    printf("Input brand of car: \n");
    scanf("%s", new_node->brand); //mảng với char * nên không có &
    new_node->next = *head;
    *head = new_node;
    return *head;
}



//Hàm in ra thông tin 1 node
void printList(node_t head,int *number){ //hàm 1 sao thì head_node là con trỏ luôn lên ko cần dấu gì nữa
    node_t temp = head; 
    int i = 1;

    while (temp != NULL){ 
        printf("Stack %d, ",*number);
        printf("Node %d:\n", i);
        i++;
        printf("Plate: %s\n",temp->plate);
        printf("Year: %d\n", temp->year);
        printf("Brand: %s\n",temp->brand);
        temp = temp->next;
    }
}

//Thêm 1 node vào stack 

int push(stack_t s,node_t head,int *number,int *R){    
    if(stackEmpty(s)==1){ // nếu stack rỗng -> bắt đầu tạo node head đầu cho stack
        s->top = makeNode(&head); // node head chính là node đầu của stack
        s->count ++; //Vừa thêm 1 node vào nên +1 số node trong stack
        
    }
    else if(stackFull(s,R)==1){ //stack đã đầy -> tạo stack mới liên kết với stack cũ -> quay lại thực hiện hàm push lần 2 (stack rỗng)
        makeStack(&s,number);
        push(s,head,number,R);//number, R ở trong hàm push to là con trỏ mang địa chỉ biến R ở hàm main nên không cần &R &number nữa
        
    }
    else{ //stack còn chỗ
        node_t p = makeNode(&head); // Tạo 1 node p liên kết với node head    
        p->next = s->top;  //Cho Node sau p thành node top NULL
        s->top = p; //Cho Node node top NULL thành node p vừa nhập liệu
        s->count ++; //Vừa thêm 1 node vào nên +1 số node trong stack
       
    }
}

/*
char pop(){    
    if(stackEmpty()) 
        return ' ';    
    char x = top->c;    
    Node* tmp = top; 
    top = top->next; 
    free(tmp);    
    return x;
}
*/


/*


void push(Stack *s) trong hàm này yêu cầu người dùng nhập dữ liệu, rồi hàm sẽ tạo ra Node mới, trỏ đến, và chèn vào Stack *s
void printStacks(Stack *s){	Stack* tmp;
	for(tmp = s; tmp != NULL; tmp = tmp->next)
	{
		Node* n;
		for(n = s->top; n != NULL; n = n->next)
		{
			if(n->year = -1)
			{
				printf(“ “);
			}
			else{
				printf(“X”);
			}		
		}
		printf(“\n”);
	}
}
*/


int ParkingLotAndColumns(int *N,int *C,int *R){
    printf("\nNhap so o do xe (N<100):N ="); scanf("%d",N);
    printf("Nhap so cot do xe (C<=N):C ="); scanf("%d",C);
    while(*N%*C!=0){
        printf("\n So cot do xe khong hop le, yeu cau nhap lai C ="); scanf("%d",C);
    }
    *R = *N/(*C);
    printf("So o do xe la N = %d",*N);
    printf("\nSo cot do xe la C = %d",*C);
    printf("\nSo hang do xe la R = %d",*R);
}

void InsertNewCar(){

}


int main(){
    node_t head = NULL;
    stack_t s;
    int number = 0; //biến đếm số thứ tự stack hiện tại
    int N=0;
    int C=0;
    int R=0;
    int m;
    while(m!=5){
            printf("\n====Program for management car parking====");
            printf("\n1) Numbers of Parking lot & columns:");
            printf("\n2) Insert new car:");
            printf("\n3) Search:");
            printf("\n4) Remove a car:");
            printf("\n5) Quit\n");
            scanf("%d",&m);
            switch(m){
                case 1 : 
                    ParkingLotAndColumns(&N,&C,&R);
                    break;
                case 2 : 
                // Khởi tạo stack -> Khởi tạo node -> Đẩy node vào stack -> Stack đầy -> Khởi tạo stack nối liền với stack đó
                    makeStack(&s,&number);
                    push(s,head,&number,&R);
                    printList(head,&number);
                    break;
                case 3 : 
                    break;
                case 4 :
                    break;
                case 5 : printf("\nThoat chuong trinh !");
                    exit(0);
                default: printf("Hay chon lai");
            }
    }
}