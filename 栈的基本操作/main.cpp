#include "pch.h"
#include "iostream"

#define Maxsize 100
using namespace std;

typedef struct {
	int data[Maxsize];
	int top;
}sqStack;

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
	cout << S.data[S.top] << "已进栈" << endl;
}
void Pop(sqStack& S, int& x) {
	if (S.top == 1) {
		cout << "栈为空" << endl;
		exit(1);
	}
	x = S.data[S.top];
	cout << x << "已出栈" << endl;
	S.top--;
}
int Gettop(sqStack S) {
	if (S.top == -1) {
		cout << "栈空" << endl;
		exit(1);
	}
	return S.data[S.top];
}

int main()
{
	int x=0;
	sqStack S;
	Initlize(S);
	cout << "请输入要进栈的元素" << endl;
	cin >> x;
	while (x != 99) {
		Push(S, x);
		cin >> x;
		
	}
	Pop(S,x);
	cout << "栈顶元素为" << Gettop(S) << endl;

}
