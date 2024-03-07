#include "pch.h"
#include "iostream"
#define Maxsize 100
using namespace std;
typedef struct {
	int* data;
	int length, size;
}sqList;
sqList Initlize(sqList& L) {
	if ((L.data = new int[Maxsize]) == NULL)
	{
		cout << "创建失败" << endl;
		exit(1);
	}
	L.length = 0;
	L.size = Maxsize;
	return L;
}
sqList Assign(sqList& L) {
	L.data = new int[Maxsize];
	for (int i = 0; i < 10; i++) {
		L.data[i] = i;
		L.length++;
	}
	return L;
}
sqList DelX(sqList& L, int x) {
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] == x) {
			L.data[i] = L.data[i + 1];
			L.length--;
			cout << i+1 << "位置的数" << x << "已删除" << endl;
		}
	}
	return L;
}
int main()
{
	sqList L;
	int x;
	cout << "请输入要删除的数" << endl;
	cin >> x;
	Initlize(L);
	Assign(L);
	DelX(L,x);
}
