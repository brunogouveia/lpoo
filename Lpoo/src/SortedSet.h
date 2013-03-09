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
	public:
		virtual ~SortedSet() {
		}

		virtual void add(const E & value)=0;
		virtual bool remove(const E& value)=0;
		virtual void clear()=0;

		virtual bool isEmpty() const=0;
		virtual int size() const=0;
		virtual bool contains(const E& value) const=0;
		virtual Iterator<E>* iterator() const=0;
};

#endif /* SORTEDSET_H_ */
