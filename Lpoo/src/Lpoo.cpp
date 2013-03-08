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
#include "Set.h"
#include "TreeSet.h"

int main() {
	TreeSet<int> *t = new TreeSet<int>();
	t->add(10);
	t->add(12);
	t->add(1);
	t->add(7);
	t->add(140);
	t->add(0);
	t->add(0);
	t->add(2);
	t->add(22);
	t->add(17);
	t->add(122);
	t->add(54);
	t->add(-22);
	t->add(-2);
	t->add(3);
	t->remove(12);

	if (t->isEmpty())
		puts("Vazio");

	Iterator<int> *i = t->iterator();
	while (i->hasNext()) {
		printf("%d ",i->next());
	}
	printf("\n%d\n", t->size());

	return 0;
}
