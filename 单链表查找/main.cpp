#include "pch.h"
#include "iostream"

using namespace std;
typedef struct LNode {
	int data;
	struct LNode *next;
}LNode, *LinkList;

LinkList HeadInsert(LinkList& L) {
	L = new LNode;
	L->next = NULL;
	LNode* s;
	int x;
	cout << "请输入元素值" << endl;
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
	L->next;
	LNode* s, * r = L;
	int x;
	cout << "请输入元素值" << endl;
	cin >> x;
	while (x != 999) {
		s = new LNode;
		s->data = x;
		r->next = s;
		r = s;
		r->next = NULL;
		cin >> x;
	}
	return L;
}
int main()
{
	LinkList L;
	TailInsert(L);
	int x, y,k=0;
	LNode* p = L->next;
	//给定值查询
	/*cout << "请输入要查询的值" << endl;
	cin >> x;
	while (p->next != NULL) {
		if (p->data == x)
			cout << "有值符合,为" << p->data << endl;
		p = p->next;
	}
	if (p->data == x)
		cout << "有值符合,为" << p->data << endl;*/

	//给定查询位置查询
	cout << "请输入要查询第几个值" << endl;
	cin >> y;
	while (p->next != NULL&&k<y-1) {
		p = p->next;
		k++;
	}
	//若k<y,在完成查询后，p指向的节点为所要查询位置的下一个节点
	cout << "第" << y << "个值为" << p->data << endl;

}
