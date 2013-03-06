#ifndef __SET_H
#define __SET_H

#ifndef COLLECTION_H
#include "Collection.h"
#endif


template<typename yurao>
class Set : public Collection<yurao>
{

};


template<typename yurao>
class SortedSet : public Set<yurao> {

};
#endif
