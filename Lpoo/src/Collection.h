#ifndef COLLECTION_H_
#define COLLECTION_H_

template<typename yurao>
class Iterator
{
	public:
		virtual ~Iterator();
		virtual bool hasNext() const = 0;
		virtual const yurao& next() = 0;
};

template<typename yurao>
class IteratorPtr
{
	private:
		Iterator<yurao>* iterator;
		IteratorPtr(const IteratorPtr<yurao>&);
		IteratorPtr<yurao>& operator=(const Iterator<yurao>&);
	public:
		IteratorPtr(Iterator<yurao>*) :
				iterator()
		{
		}
		~IteratorPtr()
		{
			delete iterator;
		}
		//sobrecarga de operador
		Iterator<yurao>* operator->() const
		{
			return iterator;
		}
};

template<typename yurao>
class Collection
{

	public:
		//metodo virtual puro
		virtual void add(const yurao & value) = 0;
		//metodo virtual
		virtual void add(const Collection<yurao>& collection);
		virtual bool remove(const yurao& value) = 0;
		virtual void clear() = 0;
		virtual ~Collection()
		{

		}
		//perguntando se a colecao eh vaziazona ou gordona
		virtual bool isEmpty() const = 0;
		virtual int size() const = 0;
		virtual bool contains(const yurao& value) const = 0;
		//a colecao disponibiliza um ponteiro para o iterador,
		//que eh o objeto responsavel pela manipulacao da colecao
		virtual Iterator<yurao>* iterator() const = 0;

};

template<typename yurao> // << isso é um link //ah vá
//adiciona todos os elementos de uma coleção nesta
void Collection<yurao>::add(const Collection<yurao>& collection)
{
	for (IteratorPtr<yurao> i(collection.iterator()); i->hasNext();)
		this->add(i->next());

}

#endif

