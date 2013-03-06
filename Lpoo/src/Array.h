/*
 * Array.h
 *
 *  Created on: Mar 4, 2013
 *      Author: bruno
 */

#ifndef ARRAY_H_
#define ARRAY_H_

#include "Collection.h"

template<typename yurao, int initialSize>
class Array: public Collection<yurao>
{
	public:
		Array();
		~Array();

		//metodo virtual puro
		void add(const yurao & value);
		//metodo virtual
		bool remove(const yurao& value);
		void clear();
		//perguntando se a colecao eh vaziazona ou gordona
		bool isEmpty() const;
		int size() const;
		bool contains(const yurao& value) const;
		//a colecao disponibiliza um ponteiro para o iterador,
		//que eh o objeto responsavel pela manipulacao da colecao
		Iterator<yurao>* iterator() const;

	private:
		yurao * array;
		int usedSize;
		int maxSize;
};

#endif /* ARRAY_H_ */
