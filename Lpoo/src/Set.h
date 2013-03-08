#ifndef __SET_H
#define __SET_H

#ifndef COLLECTION_H
#include "Collection.h"
#endif

#include<stdio.h>

template<typename E>
class Set;
template<typename E>
class SortedSet;
template<typename E>
class SetIterator;

template<typename E>
class SetNode {
	private:
		friend class Set<E> ;
		friend class SortedSet<E> ;
		friend class SetIterator<E> ;
		SetNode()
				: next(NULL) {
		}
		SetNode(E value)
				: value(value), next(NULL) {
		}
		SetNode(E value, SetNode * next)
				: value(value), next(next) {
		}
		~SetNode() {
		}
	private:
		E value;
		SetNode * next;
};

template<typename E>
class SetIterator: public Iterator<E> {
	private:
		friend class Set<E> ;
		SetIterator(SetNode<E> * head)
				: node(head) {
		}
		~SetIterator() {
		}
		bool hasNext() const {
			return node != NULL;
		}
		const E & next() {
			E& value = node->value;
			node = node->next;
			return value;
		}

	private:
		SetNode<E> * node;
};

template<typename E>
class Set: public Collection<E> {

	public:
		using Collection<E>::add;
		Set()
				: numNodes(0), head(NULL) {
		}
		virtual ~Set() {
			clear();
		}

		virtual void add(const E & value);
		virtual bool remove(const E& value);
		virtual void clear();

		virtual bool isEmpty() const;
		virtual int size() const;
		virtual bool contains(const E& value) const;
		virtual Iterator<E>* iterator() const;
	private:
		Set(const Set & obj)
				: numNodes(0), head(NULL) {
		}
		virtual bool contains(const E & value, SetNode<E> * & previ) const;
	protected:
		int numNodes;
		SetNode<E> * head;

};

template<typename E>
void Set<E>::add(const E & value) {
	SetNode<E> * previ;
	if (!contains(value, previ)) {
		if (head == NULL) {
			head = new SetNode<E>(value);
			numNodes = 1;
		} else {
			previ->next = new SetNode<E>(value, previ->next);
			numNodes++;
		}
	}
}

template<typename E>
bool Set<E>::remove(const E& value) {
	if (head == NULL)
		return false;
	SetNode<E> * node;
	if (contains(value, node)) {
		SetNode<E> * del;
		if (node == NULL) {
			del = head;
			head = head->next;
		} else {
			del = node->next;
			node->next = del->next;
		}
		delete del;
		numNodes--;
		return true;
	} else {
		return false;
	}
}

template<typename E>
void Set<E>::clear() {
	while (!isEmpty()) {
		remove(head->value);
	}
}

template<typename E>
bool Set<E>::isEmpty() const {
	return (head == NULL);
}

template<typename E>
int Set<E>::size() const {
	return numNodes;
}

template<typename E>
bool Set<E>::contains(const E& value) const {
	SetNode<E> * node;
	return contains(value, node);
}

template<typename E>
bool Set<E>::contains(const E& value, SetNode<E> * & prev) const {
	prev = NULL;
	SetNode<E> * node = head;
	while (node != NULL) {
		if (node->value == value)
			return true;
		prev = node;
		node = node->next;
	}
	return false;
}

template<typename E>
Iterator<E>* Set<E>::iterator() const {
	return new SetIterator<E>(head);
}

template<typename E>
class SortedSet: public Set<E> {
	private:
		virtual bool contains(const E& value, SetNode<E> *& prev) const;

	public:
		using Collection<E>::add;
		SortedSet()
				: Set<E>() {
		}
		//metodo virtual puro
		virtual void add(const E & value);
		virtual ~SortedSet() {
			this->clear();
		}
};

template<typename E>
void SortedSet<E>::add(const E & value) {
	SetNode<E> * previ;
	if (!contains(value, previ)) {
		if (this->head == NULL) {
			this->head = new SetNode<E>(value);
			this->numNodes = 1;
		} else {
			if (previ == NULL) {
				this->head = new SetNode<E>(value, Set<E>::head);
			} else {
				previ->next = new SetNode<E>(value, previ->next);
			}
			this->numNodes++;
		}
	}
}

template<typename E>
bool SortedSet<E>::contains(const E& value, SetNode<E> * & prev) const {
	prev = NULL;
	SetNode<E> * node = Set<E>::head;
	while (node != NULL && node->value <= value) {
		if (node->value == value)
			return true;
		prev = node;
		node = node->next;
	}
	return false;
}

#endif
