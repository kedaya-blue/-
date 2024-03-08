#include "pch.h"
#include "iostream"
using namespace std;

typedef struct LNode{
	int data;
	struct LNode* next;
}LNode,*Linklist;
Linklist Initlize(Linklist& L) {
	L = new LNode;
	L->data = 0;
	L->next = NULL;
	return L;
}
Linklist HeadInsert(Linklist& L) {
	LNode* s;
	L = new LNode;
	L->next = NULL;
	int x=0;
	cout << "请输入要插入的值" << endl;
	cin >> x;
	while(x!= 999){
		s = new LNode;
		s->data = x;
		s->next = L->next;
		L->next = s;
		cin >> x;
	}
	return L;
}
Linklist TailInsert(Linklist& L) {
	L = new LNode;
	L->next = NULL;
	LNode* s, * r = L;
	int x = 0;
	cout << "请输入要插入的值" << endl;
	cin >> x;
	while (x != 999) {
		s = new LNode;
		r->next = s;
		s->data = x;
		r = s;
		cin >> x;
	}
	return L;

}
int main()
{
	Linklist L;
	//HeadInsert(L);
	TailInsert(L);
	LNode* p = L->next;
	while (p->next != NULL) {
		cout << p->data<<" ";
		p = p->next;
	}
	cout <<p->data << endl;
}
