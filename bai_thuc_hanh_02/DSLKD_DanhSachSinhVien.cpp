#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
typedef struct{
	char hoTen[30];
	int maSV;
	float d1, d2, d3; 
}Data; 
typedef struct tagNode{
	Data infor;
	struct tagNode *link; 
}Node; 
typedef struct{
	Node *pHead;
	Node *pTail;
	int spt = 0; 
}LList;
//////////////////////////////////////////////////
void initList(LList *L){
	L->pHead = NULL;
	L->pTail = NULL;
	L->spt =  0; 
} 
int emptyList(LList L){
	return (L.spt==0); 
} 
void insertHead(LList *L, Data x){
	Node *pp;
	pp = (Node*)malloc(sizeof(Node));
	pp->infor = x;
	pp->link = NULL;
	if(emptyList(*L)){
		L->pHead = pp;
		L->pTail = pp; 
	} 
	else{
		pp->link = L->pHead;
		L->pHead = pp; 
	} 
	L->spt++; 
} 
void insertTail(LList *L, Data x){
	Node *pp;
	pp = (Node*)malloc(sizeof(Node));
	pp->infor = x;
	pp->link = NULL;
	if(emptyList(*L)){
		L->pHead = pp;
		L->pTail = pp; 
	} 
	else{
		L->pTail->link = pp;
		L->pTail = pp; 
	} 
	L->spt++; 
} 
void insertAfter(LList *L, Node *q, Data x){
	Node *pp;
	if(q==NULL) return;
	else{
		pp = (Node*)malloc(sizeof(Node));
		pp->infor = x;
		pp->link = q->link;
		q->link = pp;
		if(q==L->pTail) L->pTail = pp; 
		L->spt++; 
	} 
} 
void delHead(LList *L){
	Node *pp;
	if(emptyList(*L)) return;
	else{
		pp = L->pHead;
		L->pHead = pp->link;
		free(pp);
		L->spt--; 
		if(L->pHead == NULL)
			L->pTail = NULL;  
	} 
} 
void delAfter(LList *L, Node *q){
	Node *pp;
	if(q==NULL) return;
	else{
		pp = q->link;
		if(L->pTail == q->link)
			L->pTail = q;
		q->link = pp->link;
		free(pp);
		L->spt--; 
	} 
} 
/////////////////////////////////////////
void nhapDL(Data *x){
	printf("Nhap ma SV: ");
	scanf("%d",&(x->maSV));
	if(x->maSV>0){
		printf("Nhap ten SV: ");
		getchar();
		fgets(x->hoTen,sizeof(x->hoTen),stdin);
		x->hoTen[strlen(x->hoTen)-1]='\0';
		printf("Nhap diem mon 1: ");
		scanf("%f",&(x->d1));
		printf("Nhap diem mon 2: ");
		scanf("%f",&(x->d2));
		printf("Nhap diem mon 3: ");
		scanf("%f",&(x->d3));		 
	} 
} 
void inDL(Data x){
	printf("Ten: %s, Ma: %d, Diem 1: %.2f, Diem 2: %.2f, Diem 3: %.2f\n",
	x.hoTen, x.maSV, x.d1, x.d2, x.d3); 
} 
void processList(LList L){
	Node *pp = L.pHead;
	while(pp!=NULL){
		inDL(pp->infor);
		pp = pp->link; 
	} 
} 
Node *search(LList L, int id){
	Node *pp = L.pHead;
	while(pp != NULL && pp->infor.maSV!=id)
		pp = pp->link;
	return pp; 
} 
//////////////////////////////////////////////////////////
int main(){
	LList L;
	int kt = 0;
	Data x;
	Node q; 
	initList(&L);
	do{
		printf("\nChuong trinh lam viec voi DSLK don SV\n"); 
		printf("\n1: Them nut vao dau danh sach");
		printf("\n2: Them nut vao cuoi danh sach");
		printf("\n3: Them nut vao sau mot nut khac trong danh sach");
		printf("\n4: Xoa nut dau danh sach"); 
		printf("\n5: Xoa nut sau mot nut khac trong danh sach"); 
		printf("\n9: Duyet danh sach");
		printf("\n0: Thoat");
		printf("\nMoi ban chon: ");
		int chon; 
		scanf("%d",&chon);
		switch(chon){
			case 1:
				printf("Nhap thong tin sv can them\n");
				nhapDL(&x);
				if(x.maSV > 0)
					insertHead(&L,x);
				break;
			case 2:
				printf("Nhap thong tin sv can them\n");
				nhapDL(&x);
				if(x.maSV > 0)
					insertTail(&L,x);
				break;
			case 3:{
				printf("Nhap thong tin sinh can them\n");
				nhapDL(&x);
				int id; 
				printf("Nhap ma sinh vien phia truoc sinh vien can them\n");
				scanf("%d",&id);
				Node *q = search(L,id);
				if(q!=NULL && x.maSV>0)
					insertAfter(&L, q, x);
				else
					printf("Khong tim thay sinh vien\n");
				break;
			}
			case 4:{
				delHead(&L); 
				break;
			} 
			case 5:{
				int id; 
				printf("Nhap ma sinh vien phia truoc sinh vien can xoa\n");
				scanf("%d",&id);
				Node *q = search(L, id);
				if(q!=NULL)
					delAfter(&L, q);
				else
					printf("Khong tim thay sinh vien\n");
				break;
			} 
			case 9:
				processList(L);
				break;
			case 0:
				printf("Byebye\n");
			kt = 1; 
		} 
	}while(kt==0); 
} 

