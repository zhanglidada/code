#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main() {
	// C 中用 malloc() 函数申请
	char* p1 = (char *)malloc(10);
	cout<<(int*)p1<<endl;		//输出：00000000003BA0C0
	
	// 用 free() 函数释放
	free(p1);
   
	// C++ 中用 new 运算符申请
	char* p2 = new char[10];
	cout << (int*)p2 << endl;		//输出：00000000003BA0C0
	
	// 用 delete 运算符释放
	delete[] p2;

	char str[32767];

	return 0;
}