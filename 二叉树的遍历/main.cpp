#include "pch.h"
#include "iostream"

using namespace std;
#define Maxsize 100
typedef struct BiNode{
	char data;
	struct BiNode* lchild, * rchild;
}BiNode,*BiTree;

typedef struct {
	BiTree data[Maxsize];
	int top;
}sqStack;

typedef struct {
	BiTree data[Maxsize];
	int front, rear;
}sqQueue;

void Initlize(sqStack& S) {
	S.top = -1;
}
void Push(sqStack& S, BiTree x) {
	if (S.top == Maxsize - 1) {
		cout << "栈满" << endl;
		exit(1);
	}
	S.top++;
	S.data[S.top] = x;
}
BiTree Pop(sqStack& S,BiTree &x) {
	x = S.data[S.top];
	S.top--;
	return x;
}
bool isEmpty(sqStack S) {
	if (S.top == -1)
		return true;
	else
		return false;
}
void Initlize(sqQueue& Q) {
	Q.front = Q.rear = 0;
}
void EnQueue(sqQueue& Q, BiTree p) {
	if (Q.front == (Q.rear + 1) % Maxsize) {
		cout << "队列已满" << endl;
		exit(1);
	}
	Q.data[Q.rear] = p;
	Q.rear++;
}
void DeQueue(sqQueue& Q, BiTree& p) {
	if (Q.front == Q.rear && Q.front == 0) {
		cout << "队列为空" << endl;
		exit(1);
	}
	p = Q.data[Q.front];
	Q.front++;
	cout << p->data << " ";
}
bool isEmpty(sqQueue Q) {
	if (Q.front == Q.rear && Q.front == 0)
		return true;
	else
		return false;
}
BiNode *NewNode(int x) {
	BiNode *node = new BiNode;
	node->data = x;
	node->lchild = node->rchild = NULL;
	return node;
}
//拓展二叉树
void Insert(BiTree* T) {
	char data;
	cin >> data;
	if (data == '#')
		*T = NULL;
	else
	{
		*T = new BiNode;
		(*T)->data = data;
		Insert(&((*T)->lchild));
		Insert(&((*T)->rchild));
	}
}

void PerSearch(BiTree T) {
	if (T == NULL) {
		return;
	}
	cout << T->data <<" ";
	PerSearch(T->lchild);
	PerSearch(T->rchild);

}
void MidSearch(BiTree T) {
	if (T == NULL) {
		return;
	}
	MidSearch(T->lchild);
	cout << T->data << " ";
	MidSearch(T->rchild);
}
void RearSearch(BiTree T) {
	if (T == NULL) {
		return;
	}
	RearSearch(T->lchild);
	RearSearch(T->rchild);
	cout << T->data<<" ";
}
void PreorderSe(BiTree T) {
	cout << "非递归前序" << endl;
	sqStack S;
	Initlize(S);
	BiTree p = T;
	while (p || !isEmpty(S)) {

		if (p) {
			cout << p->data << " ";
			Push(S, p);
			p = p->lchild;
		}
		else {
			Pop(S,p);
			p=p->rchild;
		}
	}
	
}
void LevelOrder(BiTree T) {
	cout << "层次遍历" << endl;
	sqQueue Q;
	Initlize(Q);
	BiTree p = T;
	EnQueue(Q, p);
	while (!isEmpty(Q)) {
		DeQueue(Q,p);
		cout << p->data << " ";
		if (p->lchild != NULL)
			EnQueue(Q, p->lchild);
		if (p->rchild != NULL)
			EnQueue(Q, p->rchild);
	}
}
int main()
{
	BiTree T;
	Insert(&T);
	cout << "前序遍历" <<endl;
	PerSearch(T);
	cout <<endl << "中序遍历" << endl;
	MidSearch(T);
	cout<<endl << "后序遍历" << endl;
	RearSearch(T);
	cout << endl;
	PreorderSe(T);
	cout << endl;
	LevelOrder(T);
}
