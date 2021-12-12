#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
struct carpark{
	int nam;
	char bien[256];
	char hieu[256];
	int pos; // Biến vị trí của 1 cái xe
	struct carpark *next;
	struct carpark *pre;
};

typedef struct carpark *node; // MẤU CHỐT biến hthành biến con trỏ BƯỚC NÀY SẼ KHÔNG CẦN DÙNG * HAY ** Trả về địa chỉ cái trả về // CON TRỎ HÀM

void nhapn(int *n,int *c){ //Nhập số ô đỗ xe, số cột => số hàng
	printf("Nhap so slot ");
	scanf("%d",n);
	printf("Nhap so cot ");
	scanf("%d",c);
	printf("%d %d",*n,*c);
}

node creatnode(){
	node tmp; 
	tmp = (node)malloc(sizeof(struct carpark));
	printf("Nhap so bien ");
	scanf("%s",tmp->bien); // ko có & vì con trỏ xâu ở vd 3.c
	printf("Nhap so nam ");
	scanf("%d",&tmp->nam); 
	printf("Nhap so hang ");
	scanf("%s",tmp->hieu);
	tmp->next = NULL;
	tmp->pre = NULL;
	return tmp; // trả về con trỏ tmp
}  // trả về địa chỉ được lưu trong tmp và trả về các địa chỉ trong tmp

node headl(){ //Cho biến head là NULL
	node head;
	head = NULL;
	return head;
}

int in(node head,int n, int c){
	int z=1,q=0;
	int k=n/c;
	if (head == NULL){
		for (int i=0;i<k;i++){
			for(int j = 0 ; j < c;j++)
				printf("- ");
			printf("\n");
		}
		return 0;
	}
	node l;
	
	for (int i=0;i<k;i++){
		l=head;
		do{
			if((l->pos+z)%k==0) q++;
			if (l->next == NULL) break;
			else l = l -> next;
		}while(1);
		for(int j = 0 ; j < q;j++)
			printf("X ");
		for(int j = 0 ; j < c-q;j++)
			printf("- ");
		z++;
		q=0;
		printf("\n");
	}
	return 0;
}
node nhapxe(node head,int n,int c){
	node tmp,p=head;
	tmp=creatnode();
	node l;
	if(head == NULL){
		head = tmp;
		head->pos=0;
		in(head,n,c);
		return head;
	}
	while(p->next != NULL){
		p = p->next;
		if(p->pos == n-1) {
			printf("bai xe da day");
			return head;
		}
	}
	p->next=tmp;
	tmp->pre=p;

	tmp->pos=p->pos+1;
	in(head,n,c);
	return head;
}

void timthongtin(node head,int n, int c){
	char l[256];
	int h=0;
	printf("Nhap so bien ");
	scanf("%s",l);
	node p=head;
	do{
			if(strcmp(l,p->bien)==0){
				h++;
				printf("Xe o hang %d \n",p->pos%c+1);
				printf("Xe o cot %d \n",p->pos/c+1);
				printf("%d \n",p->nam);
				printf("%s \n",p->hieu);
		}
			if (p->next == NULL) break;
			else p = p -> next;
		}while(1);
	if(h==0) printf("Khong tim thay xe");
}
node boxe(node head,int n,int c){
	char l[256];
	int h=0;
	node p=head;
	if(p == NULL) {
		printf("da het xe trong kho");
		return head;
	}
	printf("Nhap so bien ");
	scanf("%s",&l);
	do{
		if(strcmp(l,p->bien)==0){
			h++;
			if(p==head){
				if(p->next == NULL) {
					head=NULL;
					in(head,n,c);
					return head;
				}
				else {
					head=p->next;
					node r=head;
					do{
						r->pos--;
						if (r->next == NULL) break;
						else r = r -> next;
					}while(1);
					in(head,n,c);
				return head;
				}
			}
			if(p->next == NULL){
				p=NULL;
				in(head,n,c);
				return head;
			}
			node tmp;
			
			tmp=p->next;
			p=p->pre;
			p->next=tmp;
			printf("%d",p->pos);
			do{
				tmp->pos--;
				if (tmp->next == NULL) break;
				else tmp = tmp -> next;
			}while(1);
			in(head,n,c);
			return head;
		}
		if (p->next == NULL) break;
		else p = p -> next;
	}while(1);
	if(h==0) printf("khong tim thay xe");
	return head;
}
int main(){
	int n,c,m=0;
	node head =  headl();
	while(m!=5) {
	printf("\nMenu\n1.Nhap vao so slot va cot (1 <= N <= 100)\n2.Nhap thong tin xe\n3.Tim kiem\n4.Bo xe\n5.Thoat\n");
	scanf("%d",&m);
	switch(m){
		case 1:
			nhapn(&n,&c);
			break;
		case 2:
			head=nhapxe(head,n,c);
			break;
		case 3:
			timthongtin(head,n,c);
			break;
		case 4:
			head = boxe(head,n,c);
			break;
		case 5:
			printf("BYE");
			return 0;
			break;
		default : printf("Please Enter Again !");
	}
	}
	return 0;
}

