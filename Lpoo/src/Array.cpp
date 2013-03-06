/*
 * Array.cpp
 *
 *  Created on: Mar 4, 2013
 *      Author: bruno
 */

#include "Array.h"

template<typename E, int initialSize>
Array<E, initialSize>::Array()
{
	array = new E[initialSize];
	usedSize = 0;
	maxSize = initialSize;
}

template<typename E, int initialSize>
Array<E, initialSize>::~Array()
{
	delete array;
}

//metodo virtual puro
template<typename E, int initialSize>
void Array<E, initialSize>::add(const E & value)
{
	if (usedSize == maxSize)
	{
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
bool Array<E, initialSize>::remove(const E& value)
{

}

template<typename E, int initialSize>
void Array<E, initialSize>::clear()
{

}
//perguntando se a colecao eh vaziazona ou gordona
template<typename E, int initialSize>
bool Array<E, initialSize>::isEmpty() const
{

}

template<typename E, int initialSize>
int Array<E, initialSize>::size() const
{

}
template<typename E, int initialSize>
bool Array<E, initialSize>::contains(const E& value) const
{

}
//a colecao disponibiliza um ponteiro para o iterador,

template<typename E, int initialSize>
Iterator<E>* Array<E, initialSize>::iterator() const
{

}
