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
	/* Testando o array de int */
	Array<int> * arrayInt = new Array<int>();

	printf("Array<int> * arrayInt\n");
	printf("Teste com adição:\n");
	srand(time(NULL));
	for (int i = 0; i < 15; i++) {
		int r = rand() % 100;
		if (arrayInt->contains(r)) {
			printf("arrayInt ja contem o inteiro %2d.\n", r);
		} else {
			printf("O inteiro %2d foi adicionado em arrayInt.\n", r);
			arrayInt->add(r);
		}
	}
	printf("Teste com iterator:\n");
	Iterator<int> * iteratorArray = arrayInt->iterator();
	while (iteratorArray->hasNext())
		printf("%d ", iteratorArray->next());
	printf("\n");

	printf("\Teste com remoção:\n");
	srand(time(NULL));
	for (int i = 0; i < 15; i++) {
		int r = rand() % 50;
		if (!arrayInt->contains(r)) {
			printf("arrayInt não contem o inteiro %2d\n", r);
		} else if (arrayInt->remove(r)) {
			printf("o inteinro %2d foi removido de arrayInt\n", r);
		} else {
			/*Se o programa estiver certo, esse printf não será executado.*/
			printf("Erro ao remover %2d.\n", r);
		}
	}
	delete arrayInt;

	/*Testando o TreeSet de float*/
	TreeSet<float> *tFloat = new TreeSet<float>();

	printf("\nTreeSet<float> * tFloat\n");
	printf("Teste com adição:\n");
	srand(time(NULL));
	for (int i = 0; i < 15; i++) {
		float r = (float) (rand() % 10000);
		r /= 100;
		if (tFloat->contains(r)) {
			printf("tFloat ja contem o float %5.2f.\n", r);
		} else {
			printf("O float %5.2f foi adicionado em tFloat.\n", r);
			tFloat->add(r);
		}
	}

	printf("Teste com iterator:\n");
	Iterator<float> * iteratorTreeFloat = tFloat->iterator();
	while (iteratorTreeFloat->hasNext())
		printf("%.2f ", iteratorTreeFloat->next());
	printf("\n");

	printf("Teste com remoção:\n");
	srand(time(NULL));
	for (int i = 0; i < 15; i++) {
		float r = (float) (rand() % 5000);
		r /= 100;
		if (!tFloat->contains(r)) {
			printf("tFloat não contem o float %5.2f\n", r);
		} else if (tFloat->remove(r)) {
			printf("o float %5.2f foi removido de tFloat\n", r);
		} else {
			/*Se o programa estiver certo, esse printf não será executado.*/
			printf("Erro ao remover %5.2f.\n", r);
		}
	}
	delete tFloat;

	/*Testando o TreeSet de float*/
	TreeSet<String> *tString = new TreeSet<String>();
	String * string = new String[10];
	string[0] = "Asiáticos";
	string[1] = "Bruno";
	string[2] = "Maleta";
	string[3] = "Cara de boi";
	string[4] = "Zebra";
	string[5] = "Tijolo";
	string[6] = "Casa verde";
	string[7] = "Lpoo";
	string[8] = "String";
	string[9] = "Baralho";

	printf("\nTreeSet<float> * tFloat\n");
	printf("Teste com adição:\n");
	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		if (tString->contains(string[i])) {
			printf("tString ja contem a string \"%s\".\n", string[i].toChar());
		} else {
			printf("a string \"%s\" foi adicionado em tString.\n", string[i].toChar());
			tString->add(string[i]);
		}
	}

	printf("Teste com iterator:\n");
	Iterator<String> * iteratorTreeString = tString->iterator();
	while (iteratorTreeString->hasNext())
		printf("\"%s\" ", iteratorTreeString->next().toChar());
	printf("\n");

	printf("Teste com remoção:\n");
	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		if (!tString->contains(string[i])) {
			printf("tString não contem a string \"%s\"\n", string[i].toChar());
		} else if (tString->remove(string[i])) {
			printf("a string \"%s\" foi removido de tString\n", string[i].toChar());
		} else {
			/*Se o programa estiver certo, esse printf não será executado.*/
			printf("Erro ao remover \"%s\".\n", string[i].toChar());
		}
	}

	String * soma = new String();
	*soma = string[0] + string[1];
	printf("\"%s\" = \"%s\" + \"%s\"\n", soma->toChar(), string[0].toChar(), string[1].toChar());
	*soma += string[2];
	printf("\"%s\" = \"%s\" + \"%s\"\n", soma->toChar(), soma->toChar(), string[2].toChar());
	if (*soma == ((string[0] + string[1]) += string[2]))
		printf("\"%s\" = ((\"%s\" + \"%s\") += \"%s\")\n", soma->toChar(), string[0].toChar(), string[1].toChar(), string[2].toChar());

	delete soma;
	delete tString;
	delete[] string;

	return 0;
}
