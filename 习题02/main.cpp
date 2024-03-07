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
	for (int i = 0; i < 5; i++) {
		L.data[i] = rand();
		L.length++;
	}
	return L;
}
sqList Revert(sqList& L) {
	int mid;
	for (int i = 0; i < L.length / 2; i++) {
			mid = L.data[i];
			L.data[i] = L.data[L.length-i-1];
			L.data[L.length-i-1] = mid;
		
	}
	return L;
}
int main()
{
	sqList L;
	int mid;
	Initlize(L);
	Assign(L);
	cout << "逆置前" << endl;
	for (int i = 0; i < L.length; i++) {
		cout << L.data[i]<<" ";
	}
	Revert(L);
	cout <<endl << "逆置后" << endl;
	for (int i = 0; i < L.length; i++) {
		cout << L.data[i] << " ";
	}

}
