#ifndef SET_H_
#define SET_H_

#ifndef COLLECTION_H_
#include "Collection.h"
#endif

/********************************************************************************
 ************************                             ***************************
 ***************                 Set Template                 *******************
 ************************                             ***************************
 ********************************************************************************/

template<typename E>
class Set: public Collection<E> {

	public:
		virtual ~Set(){
		}
		virtual void add(const E & value)=0;
		virtual bool remove(const E& value)=0;
		virtual void clear()=0;

		virtual bool isEmpty() const=0;
		virtual int size() const=0;
		virtual bool contains(const E& value) const=0;
		virtual Iterator<E>* iterator() const=0;

};

#endif
