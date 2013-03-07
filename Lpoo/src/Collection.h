#ifndef COLLECTION_H_
#define COLLECTION_H_

#include <stdio.h>

template<typename E>
class Iterator
{
	public:
		virtual ~Iterator() {}
		virtual bool hasNext() const = 0;
		virtual const E& next() = 0;
};

template<typename E>
class IteratorPtr
{
	private:
		Iterator<E>* iterator;
		IteratorPtr(const IteratorPtr<E>&);
		IteratorPtr<E>& operator=(const Iterator<E>&);
	public:
		IteratorPtr(Iterator<E>* it) :
				iterator(it)
		{
		}
		~IteratorPtr()
		{
			delete iterator;
		}
		//sobrecarga de operador
		Iterator<E>* operator->() const
		{
			return iterator;
		}
};

template<typename E>
class Collection
{

	public:
		//metodo virtual puro
		virtual void add(const E & value) = 0;
		//metodo virtual
		virtual void add(const Collection<E>& collection);
		virtual bool remove(const E& value) = 0;
		virtual void clear() = 0;
		virtual ~Collection()
		{

		}
		//perguntando se a colecao eh vaziazona ou gordona
		virtual bool isEmpty() const = 0;
		virtual int size() const = 0;
		virtual bool contains(const E& value) const = 0;
		//a colecao disponibiliza um ponteiro para o iterador,
		//que eh o objeto responsavel pela manipulacao da colecao
		virtual Iterator<E>* iterator() const = 0;

};

template<typename E> // << isso é um link //ah vá
//adiciona todos os elementos de uma coleção nesta
void Collection<E>::add(const Collection<E>& collection)
{
	for (IteratorPtr<E> i(collection.iterator()); i->hasNext();) {
		this->add(i->next());
	}

}

#endif

