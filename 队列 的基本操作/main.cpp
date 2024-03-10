#include "pch.h"
#include "iostream"
#define Maxsize 100
using namespace std;
typedef struct {
	int data[Maxsize];
	int front, rear;
}sqQueue;
void Initlize(sqQueue& Q) {
	Q.front = Q.rear = 0;
}
bool isEmpty(sqQueue Q) {
	if (Q.front == 0 && Q.rear == 0)
		return true;
	else
		return false;
}
void enQueue(sqQueue& Q, int x) {
	if ((Q.rear + 1) % Maxsize == Q.front) {
		cout << "队列已满" << endl;
		exit(1);
	}
	Q.data[Q.rear] = x;
	Q.rear = (Q.rear + 1) % Maxsize;
	
}
void outQueue(sqQueue& Q) {
	if ((Q.rear = Q.front) && (Q.rear == 0)) {
		cout << "队列为空" << endl;
		exit(1);
	}
	cout << Q.data[Q.front]<<"已出队列"<<endl ;
	Q.front = (Q.front + 1) % Maxsize;
}
int main()
{
	int x;
	sqQueue Q;
	Initlize(Q);
	cout << "请输入要进队列的元素" << endl;
	cin >> x;
	while (cin.get()!='\n') {
		enQueue(Q, x);
		cin >> x;
	}
	outQueue(Q);
}
