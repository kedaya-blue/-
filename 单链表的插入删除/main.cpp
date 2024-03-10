#include "pch.h"
#include "iostream"

using namespace std;

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, *LinkList;

LinkList HeadInsert(LinkList& L) {
	L = new LNode;
	L->next = NULL;
	LNode* s;
	int x;
	cout << "请输入元素" << endl;
	cin >> x;
	while (x != 999) {
		s = new LNode;
		s->data = x;
		s->next = L->next;
		L->next = s;
		cin >> x;
	}
	return L;
}
LinkList TailInsert(LinkList& L) {
	L = new LNode;
	L->next = NULL;
	LNode* s, * r = L;
	int x;
	cout << "请输入元素" << endl;
	cin >> x;
	while (x != 999) {
		s = new LNode;
		r->next = s;
		s->data = x;
		s->next = NULL;
		r = s;
		cin >> x;
	}
	return L;
}
//输出单链表
void Output(LinkList& L) {
	LNode* p = L->next;
	cout << "单链表为: ";
	while (p->next != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << p->data<<endl;
}
//求单链表长度
int Length(LinkList& L) {
	int k = 1;
	LNode* p = L->next;
	while (p->next != NULL) {
		k++;
		p = p->next;
	}
	return k;
}
//插入指定位置的元素
LinkList Insert(LinkList& L, int m,int n) {
	int k = 0;
	LNode* p = L->next,*s;	
	if (n > Length(L) ||n<=0) {
		cout << "超过线性表最大位数"<<endl;
		exit(1);
	}
	while (p->next != NULL && k < n - 2) {
		p = p->next;
		k++;
	}
	s = new LNode;
	s->data = m;
	s->next = p->next;
	p->next = s;
	return L;
}
//删除链表中值为m的元素
LinkList DelElem(LinkList& L, int m) {
	int k = 0;
	LNode* p = L->next;
	if (p->data == m)
		L->next = NULL;
	while (p->next!=NULL) {
		if (p->next->data == m) {
			p->next = p->next->next;
			free(p->next);
		}
		p = p->next;
	}
	return L;
}
int main()
{
	int m, n;
	LinkList L;
	TailInsert(L);
	Output(L);
	cout << "位数" << Length(L) << endl;
	cout<< "请输入要插入的数字，位置" << endl;
	cin >> m >> n;
	Insert(L, m, n);
	Output(L);
	cout << "请输入要删除的数字" << endl;
	cin >> m;
	DelElem(L, m);
	Output(L);
}
