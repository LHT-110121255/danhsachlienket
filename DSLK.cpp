#include <stdio.h>
#include <stdlib.h>

typedef struct NhanVien
{
	int MaSo;
	char HoTen[31];
	int Luong;
}NhanVien;

typedef struct NODE
{
	NhanVien info;
	NODE * pNext = NULL;
}NODE;

typedef struct NodeList
{
	NODE *pHead = NULL;
	NODE *pTail = NULL;
}NodeList;

void AddLast(NodeList &l, NODE * new_Node);
void AddAfter(NodeList &l, NODE *Q, NODE * new_Node);
void AddFirst(NodeList &l, NODE * new_Node);
void XuatThongTin(NODE nv);
void NhapThongTin(NODE &nv);
void XuatDanhSach(NodeList l);
NODE* TaoNode(NODE x);

int main() 
{	
	NodeList DanhSach;
	NODE nv;

	int i, n;
	printf("Nhap bao nhieu nhan vien ? \t"); scanf("%d", &n);
	for(i = 1; i <=n; i++)
	{
		NhapThongTin(nv);
		AddLast(DanhSach, TaoNode(nv));

	}
		XuatDanhSach(DanhSach);
	
}

NODE* TaoNode(NODE x) 
{
    //tao mot node p moi
    NODE *p;
    p = new NODE;
    //neu p==NULL thi khong du bo nho
    if (p==NULL) {
        printf ("KHONG DU BO NHO");
        return NULL;
    }
    //gan thanh phan data = x
    p->info = x.info;
    //gan con tro next = NULL
    p->pNext=NULL;
    //tra ve node p da tao
    return p;
}

void NhapThongTin(NODE &nv)
{
	printf("Nhap Ma So: "); fflush(stdin); scanf("%d", &nv.info.MaSo);
	printf("Nhap Ho&ten: ");fflush(stdin); gets(nv.info.HoTen);
	printf("Nhap Luong: "); fflush(stdin); scanf("%d", &nv.info.Luong);
}

void XuatThongTin(NODE nv)
{
	printf("Ma So: %10d    ", nv.info.MaSo ); 
	printf("Ho&ten: %31s   ", nv.info.HoTen);
	printf("Luong: %10d    \n", nv.info.Luong); 
}

void AddFirst(NodeList &l, NODE * new_Node)
{
	if (l.pHead == NULL)
	{
		l.pHead = new_Node;
		l.pTail = l.pHead;
	} else
	{
		new_Node->pNext = l.pHead;
		l.pHead = new_Node;
	}
}

void AddAfter(NodeList &l, NODE *Q, NODE * new_Node)
{
	if (Q != NULL)
	{
		new_Node->pNext = Q->pNext;
		Q->pNext = new_Node;
		if(Q == l.pTail)
			l.pTail = new_Node;
	} else
	{
		AddFirst(l, new_Node);
	}
}

void AddLast(NodeList &l, NODE * new_Node)
{
	if (l.pHead == NULL)
	{
		l.pHead = new_Node;
		l.pTail = l.pHead;
	} else
	{

		l.pTail->pNext = new_Node;
		l.pTail = new_Node;
	}
}

void XuatDanhSach(NodeList l)
{
	NODE *p;
	p = l.pHead;
	while(p != NULL)
	{
		XuatThongTin(*p);
		p = p->pNext;
	}
}

