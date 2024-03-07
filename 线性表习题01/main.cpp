#include "pch.h"
#include "iostream"
#define Maxsize 100
using namespace std;
typedef struct {
	int* data;
	int length;
	int size;
}sqList;
sqList Initlize(sqList& L) {
	if ((L.data = new int(Maxsize)) = NULL) {
		cout << "创建失败" << endl;
		exit(1);
	}
	L.length = 0;
	L.size = Maxsize;
	return L;
}
sqList DelMin(sqList& L) {
	int min;
	min = L.data[0];
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] < min) {
			min = L.data[i];
		}
	}
	cout << "最小的元素是" <<min<<endl;
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] == min) {
			cout << "最小元素的位置是" << i + 1 << endl;
			L.data[i] = L.data[L.length - 1];
			L.length--;
			cout << "现在位置" << i + 1 << "的元素为" << L.data[i] << endl;
		}
	}
	return L;
}
int main()
{
	sqList L;
	Initlize(L);
	L.data = new int[Maxsize];
	for (int i = 0; i < 30; i++) {
		L.data[i] = rand();
		L.length++;
		cout << "第" << i << "项为" << L.data[i] << endl;
	}
	DelMin(L);
}
