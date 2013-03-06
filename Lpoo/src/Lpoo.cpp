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
	String *a = new String("boisahzashdacaraverdeepretaeazuleamarelaecinzaevermelha");
	a->print();
	String * s = new String("freestepehnoisquevoaashashashhasshashhasssasassadasd");
	String * b = new String("kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk");

	String c = "oi papai da cara azul e vermelha";

	//String p = *a + *s;
	//*a = *s + "zzzz";
	a->print();
	s->print();
	return 0;
}
