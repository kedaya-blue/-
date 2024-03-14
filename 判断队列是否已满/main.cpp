#include "pch.h"
#include "iostream"

#define Maxsize 5
using namespace std;

typedef struct {
	int data[Maxsize];
	int front, rear;
	int tag;
}sqQueue;
void Initlize(sqQueue& Q) {
	Q.front = Q.rear = 0;
}
bool isEmpty(sqQueue Q) {
	if (Q.rear == Q.front && Q.tag == 0)
		return true;
	else
		return false;
}
void EnQueue(sqQueue& Q, int x) {
	if (Q.rear==Q.front&&Q.tag==1) {
		cout << "队列已满" << endl;
		exit(1);
	}
	Q.data[Q.rear] = x;
	Q.rear=(Q.rear+1)%Maxsize;
	Q.tag = 1;
}
void DeQueue(sqQueue& Q, int& x) {
	if (Q.rear == Q.front && Q.tag == 0) {
		cout << "队列为空" << endl;
		exit(1);
	}
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % Maxsize;
	Q.tag = 0;
}

int main()
{
	sqQueue Q;
	int x;
	Initlize(Q);
	cout << "输入" << endl;
	cin >> x;
	while (cin.get() != '\n') {
		EnQueue(Q, x);
		cout << x << "已入队" << endl;
		cin >> x;
	}
	while (!isEmpty) {
		DeQueue(Q, x);
		cout << x << " ";
	}

}
