/*
 * Array.h
 *
 *  Created on: Mar 4, 2013
 *      Author: bruno
 */

#ifndef ARRAY_H_
#define ARRAY_H_

#include "Collection.h"

template<typename E, int initialSize = 10>
class ArrayIterator;

/********************************************************************************
 ************************                             ***************************
 ***************                Array Template                *******************
 ************************                             ***************************
 ********************************************************************************/
template<typename E, int initialSize = 10>
class Array: public Collection<E> {
	public:
		using Collection<E>::add;
		Array() {
			array = new E[initialSize];
			usedSize = 0;
			maxSize = initialSize;
		}
		~Array() {
			delete array;
		}

		void add(const E & value);
		bool remove(const E& value);
		void clear();
		bool isEmpty() const;
		int size() const;
		bool contains(const E& value) const;
		Iterator<E>* iterator() const;

	private:
		E * array;
		int usedSize;
		int maxSize;
};

//metodo virtual puro
template<typename E, int initialSize>
void Array<E, initialSize>::add(const E & value) {
	if (usedSize == maxSize) {
		maxSize *= 2;

		E * temp = array;
		array = new E[maxSize];

		for (int i = 0; i < usedSize; i++)
			array[i] = temp[i];

		delete temp;
	}
	array[usedSize++] = value;
}
//metodo virtual
template<typename E, int initialSize>
bool Array<E, initialSize>::remove(const E& value) {
	int i;
	for (i = 0; i < usedSize && array[i] != value; i++)
		;
	if (i == usedSize)
		return false;
	usedSize--;
	while (i < usedSize) {
		array[i] = array[i + 1];
		i++;
	}
	return true;
}

template<typename E, int initialSize>
void Array<E, initialSize>::clear() {
	usedSize = 0;
}
//perguntando se a colecao eh vaziazona ou gordona
template<typename E, int initialSize>
bool Array<E, initialSize>::isEmpty() const {
	return (usedSize == 0);
}

template<typename E, int initialSize>
int Array<E, initialSize>::size() const {
	return usedSize;
}
template<typename E, int initialSize>
bool Array<E, initialSize>::contains(const E& value) const {
	for (int i = 0; i < usedSize; i++) {
		if (array[i] == value)
			return true;
	}
	return false;
}
//a colecao disponibiliza um ponteiro para o iterador,

template<typename E, int initialSize>
Iterator<E>* Array<E, initialSize>::iterator() const {
	return new ArrayIterator<E, initialSize>(array, usedSize);
}

/********************************************************************************
 ************************                             ***************************
 ***************            ArrayIterator Template            *******************
 ************************                             ***************************
 ********************************************************************************/
template<typename E, int initialSize>
class ArrayIterator: public Iterator<E> {
	private:
		friend class Array<E, initialSize> ;
		ArrayIterator(E * array, int size) {
			this->array = array;
			this->size = size;
			i = 0;
		}
		~ArrayIterator() {
		}

		bool hasNext() const {
			return (i < size);
		}
		const E& next() {
			return array[i++];
		}

	private:
		E * array;
		int size;
		int i;
};

#endif /* ARRAY_H_ */
