//============================================================================
// Name        : LPOO-C++.cpp
// Author      : Bruno Gouveia
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
using namespace std;

#include "String.h"
#include "Array.h"

int main() {
	Array<int, 3> * ar = new Array<int, 3>();

	ar->add(122);
	ar->add(22);
	ar->add(221);
	ar->add(221);
	ar->add(1);
	ar->add(10);
	ar->remove(122);
	Array<int, 3> * ar2 = new Array<int, 3>();
	ar2->Collection<int>::add(*ar);
	ar2->remove(1);
	ar2->clear();
	for (int i = 0; i < ar->usedSize; i++)
		printf("%d ", ar->array[i]);

	for (int i = 0; i < ar2->usedSize; i++)
		printf("%d ", ar2->array[i]);
	printf("\n%d %d\n", ar->maxSize, ar2->maxSize);

	return 0;
}
