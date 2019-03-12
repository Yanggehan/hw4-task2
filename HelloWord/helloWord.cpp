//#include "stdafx.h" 

#include <iostream> 

using namespace std;
int main() {
	int i = 7;
	int n = 6;
	int*ptr;
	
	/*printf("value:%d\n", i);
	printf("array:%d\n", array[3]);*/
	printf("value:%d\n", *ptr);
	ptr = ptr + 4;
	printf("value:%d\n", *ptr);

}