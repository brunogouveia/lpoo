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

int main() {
	Set<int> *s = new Set<int>();
	s->add(10);
	s->add(30);
	s->add(12);
	s->remove(10);
	if (s->contains(30))
		puts("Tem");
	SortedSet<int> *ss = new SortedSet<int>();
	ss->add(*s);

	Array<int> *a = new Array<int>();
	a->add(2);
	a->add(10);
	Array<int> *ar = new Array<int>();
	ar->add(*a);

	Iterator<int> *i = ss->iterator();
	while (i->hasNext()) {
		printf("%d ", i->next());
	}
	printf("\n%d\n", s->size());

	return 0;
}
