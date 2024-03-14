#include "pch.h"
#include "iostream"
#define Maxsize 10
using namespace std;
typedef struct {
	int data[Maxsize];
	int front, rear;
}sqQueue;

bool isEmpty(sqQueue Q) {
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}
void Initlize(sqQueue& Q) {
	Q.front = Q.rear = 0;
}
void EnQueue(sqQueue& Q,int x) {
	if (Q.front == (Q.rear + 1) % Maxsize) {
		cout << "队列满" << endl;
		exit(1);
	}
	Q.data[Q.rear] = x;
	Q.rear = (Q.rear + 1) % Maxsize;
}
void DeQueue(sqQueue& Q, int& x) {
	if (Q.front == Q.rear) {
		cout << "队列空" << endl;
		exit(1);
	}
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % Maxsize;
}
int QueueLength(sqQueue Q) {
	int x;
	x = (Q.rear - Q.front+Maxsize) % Maxsize;
	return x;
}
int main()
{
	//分别定义客车，货车，轮渡队列为Q1,Q2,Q3
	sqQueue Q1, Q2,Q3;
	int x;
	Initlize(Q1);
	Initlize(Q2);
	Initlize(Q3);
	cout << "输入车辆驶入序列" << endl;
	cout << "输入数字大于5为货车，小于等于5为客车，不可为0" << endl;
	cin >> x;
	while (x != 0) {
		if (x > 5) {
			EnQueue(Q2, x);
			cout << "序号为" << x << "的货车已位于等待区" << endl;
		}
		else {
			EnQueue(Q1, x);
			cout << "序号为" << x << "的客车已位于等待区" << endl;
		}
		cin >> x;
	}
	while  (QueueLength(Q1) >= 4&&QueueLength(Q3)<=10) {
		int i = 4;
		while (i > 0) {
			DeQueue(Q1, x);
			EnQueue(Q3, x);
			i--;
		}
		if (QueueLength(Q2) > 0) {
			DeQueue(Q2, x);
			EnQueue(Q3, x);
		}
	}
	while (QueueLength(Q1) < 4 && QueueLength(Q3) <= 10) {
		while (QueueLength(Q1) > 0) {
			DeQueue(Q1, x);
			EnQueue(Q3, x);
		}
		if (QueueLength(Q2) > 0) {
			DeQueue(Q2, x);
			EnQueue(Q3, x);
		}
		else
			break;
	}
	if (QueueLength(Q3) == 10)
		cout << "轮渡已出发" << endl;
	cout << "轮渡出发序列为" << endl;
	while (QueueLength(Q3) > 0) {
		DeQueue(Q3, x);
		cout << x << " ";
	}
}
