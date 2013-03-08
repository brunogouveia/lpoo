/*
 * SortedSet.h
 *
 *  Created on: Mar 8, 2013
 *      Author: bruno
 */

#ifndef SORTEDSET_H_
#define SORTEDSET_H_

#ifndef SET_H_
#include "Set.h"
#endif

/********************************************************************************
 ************************                             ***************************
 ***************              SortedSet Template              *******************
 ************************                             ***************************
 ********************************************************************************/

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
	while (node != NULL && node->value < value) {
		if (node->value == value)
			return true;
		prev = node;
		node = node->next;
	}
	return false;
}

#endif /* SORTEDSET_H_ */
