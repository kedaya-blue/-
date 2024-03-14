#include "pch.h"
#include "iostream"
#define Maxsize 100
using namespace std;
typedef struct {
	int data[Maxsize];
	int front, rear;
}sqQueue;
typedef struct {
	int data[Maxsize];
	int top;
}sqStack;
void Initlize(sqQueue& Q) {
	Q.front = Q.rear = 0;
}
bool isEmpty(sqQueue Q) {
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}
void EnQueue(sqQueue& Q, int x) {
	if (Q.front == (Q.rear + 1) % Maxsize) {
		cout << "队列已满" << endl;
		exit(1);
	}
	Q.data[Q.rear] = x;
	Q.rear = (Q.rear + 1) % Maxsize;
}
void DeQueue(sqQueue& Q, int &x) {
	if (Q.front == Q.rear) {
		cout << "队列为空" << endl;
		exit(1);
	}
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % Maxsize;
}
void Initlize(sqStack& S) {
	S.top = -1;
}
bool isEmpty(sqStack S) {
	if (S.top == -1)
		return true;
	else
		return false;
}
void Push(sqStack& S, int x) {
	if (S.top == Maxsize - 1) {
		cout << "栈满" << endl;
		exit(1);
	}
	S.top++;
	S.data[S.top] = x;
}
void Pop(sqStack& S, int& x) {
	if (S.top == -1) {
		cout << "栈空" << endl;
		exit(1);
	}
	x = S.data[S.top];
	S.top--;
}
int main()
{
	sqQueue Q;
	sqStack S;
	Initlize(S);
	Initlize(Q);
	int x;
	cout << "请输入" << endl;
	cin >> x;
	while (x!=0) {
		EnQueue(Q, x);
		cin >> x;
	}
	cout << "队列为：";
	while (!isEmpty(Q)) {
		DeQueue(Q, x);
		cout << x << " ";
		Push(S, x);
	}
	cout << endl << "逆置之后";
	while (!isEmpty(S)) {
		Pop(S, x);
		EnQueue(Q, x);
	}
	cout << "队列为：";
	while (!isEmpty(Q)) {
		DeQueue(Q, x);
		cout << x << " ";
	}

}
