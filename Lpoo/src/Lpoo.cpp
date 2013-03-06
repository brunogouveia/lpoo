//============================================================================
// Name        : LPOO-C++.cpp
// Author      : Bruno Gouveia
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>;
using namespace std;

#include "String.h"

int main()
{
	//StringData *d = new StringData();
	String *a = new String("BrunoHenriqueGouveiaYuriClaureNetoFilhoDaSilva");
	String * s = new String("AlvaroBotturaSantosDeMeloDaFonsecaJuniolMalboroBoro");
	String * b = new String("BrunoHenriqueGouveiaYuriClaureNetoFilhoDaSilva");

	String *pt;
	{
		String *p = new String("abelha");
		String *x = new String("aabelha");
		*p += "tentei te esquecer";
		printf("%d\n", p->data->refCount);
		//*a = *s + "zzzz";
		p->print();
		pt = p;
	}
	delete pt;
	printf("%d\n", a->data->refCount);

	return 0;
}
