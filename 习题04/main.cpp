#include "pch.h"
#include "iostream"
#define Maxsize 100
using namespace std;
typedef struct {
	int* data;
	int length, size;
}sqList;
sqList Initlize(sqList& L) {
	if ((L.data = new int[Maxsize]) == NULL) {
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

sqList DelSame(sqList& L) {
	int i = 0;
	int n = 0;
	while(i<L.length){
		if (L.data[i] == L.data[i + 1]) {
			cout << "发现重复数字" << L.data[i] << endl;
			n++;
		}
		else
			L.data[i - n] = L.data[i];
		i++;
	}
	L.length -= n;
	return L;
}
int main()
{
	int s, t;
	int n = 0;
	int i = 0;
	sqList L;
	cout << "请输入范围"<<endl;
	cin >> s >> t;
	if (s >= t) {
		cout << "输入不合法" << endl;
		exit(1);
	}
	Initlize(L);
	Assign(L);
	while (i < L.length) {
		if (L.data[i] > s && L.data[i] < t) {
			cout << L.data[i] << "在范围内" << endl;
			n++;
		}
		else
			L.data[i - n] = L.data[i];
		i++;
	}
	L.length = L.length - n;
	cout << endl << "共删除了" << n << "个元素" << endl;
	DelSame(L);
}
