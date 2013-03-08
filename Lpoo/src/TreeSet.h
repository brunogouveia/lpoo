/*
 * TreeSet.h
 *
 *  Created on: Mar 7, 2013
 *      Author: bruno
 */

#ifndef TREESET_H_
#define TREESET_H_

#include <stdlib.h>
#include<stdio.h>

#ifndef SORTEDSET_H_
#include "SortedSet.h"
#endif

template<typename E>
class TreeSet;
template<typename E>
class TreeSetIterator;


template<typename E>
class TreeSetNode {
	private:
		friend class TreeSet<E> ;
		friend class TreeSetIterator<E> ;
		TreeSetNode()
				: parent(NULL), left(NULL), right(NULL) {
		}
		TreeSetNode(const E value, TreeSetNode<E> * parent)
				: value(value), parent(parent), left(NULL), right(NULL) {
		}
		TreeSetNode(const E value, const TreeSetNode<E> * parent, const TreeSetNode<E> * left, const TreeSetNode<E> * right) {
			this->value = value;
			this->parent = parent;
			this->left = left;
			this->right = right;
		}
		~TreeSetNode() {
		}

		E value;
		TreeSetNode<E> * parent;
		TreeSetNode<E> * left;
		TreeSetNode<E> * right;
};

/********************************************************************************
 ************************                             ***************************
 ***************               TreeSet Template               *******************
 ************************                             ***************************
 ********************************************************************************/

template<typename E>
class TreeSet: public SortedSet<E> {
	public:
		TreeSet()
				: root(NULL) {
			this->numNodes = 0;
		}
		virtual ~TreeSet() {
			this->clear();
		}
		virtual void add(const E & value);
		virtual bool remove(const E& value);
		virtual bool isEmpty();
		virtual Iterator<E>* iterator() const;

	private:
		TreeSetNode<E> * getLess(TreeSetNode<E> * point) const;
		virtual bool contains(const E& value, TreeSetNode<E> *& parent) const;
	private:
		using Set<E>::numNodes;
		TreeSetNode<E> * root;
};

template<typename E>
void TreeSet<E>::add(const E& value) {
	TreeSetNode<E> * parent;
	if (!contains(value, parent)) {
		if (parent == NULL) {
			root = new TreeSetNode<E>(value, NULL);
		} else if (parent->value > value) {
			parent->left = new TreeSetNode<E>(value, parent);
		} else {
			parent->right = new TreeSetNode<E>(value, parent);
		}
		this->numNodes++;
	}
}

template<typename E>
bool TreeSet<E>::remove(const E& value) {
	if (root == NULL) {
		return false;
	}
	TreeSetNode<E> * parent;
	if (contains(value, parent)) {
		TreeSetNode<E> * temp;
		if (parent == NULL) {
			if (root->left != NULL && root->right != NULL) {
				TreeSetNode<E> * less = getLess(root->right);
				E value = less->value;
				remove(value);
				root->value = value;
			} else if (root->left != NULL) {
				temp = root;
				root = root->left;
				root->parent = NULL;
				delete temp;
			} else {
				temp = root;
				root = root->right;
				root->parent = NULL;
				delete temp;
			}
		} else {
			TreeSetNode<E> *& node = (parent->value > value) ? parent->left : parent->right;
			if (node->left != NULL && node->right != NULL) {
				TreeSetNode<E> * less = getLess(node->right);
				E value = less->value;
				remove(value);
				node->value = value;
			} else if (node->left != NULL) {
				temp = node;
				node = node->left;
				node->parent = parent;
				delete temp;
			} else {
				temp = node;
				node = node->right;
				node->parent = parent;
				delete temp;
			}
		}
		this->numNodes--;
	}
	return false;
}

template<typename E>
bool TreeSet<E>::isEmpty() {
	return root == NULL;
}

template<typename E>
Iterator<E>* TreeSet<E>::iterator() const {
	return new TreeSetIterator<E>(root);
}

template<typename E>
bool TreeSet<E>::contains(const E& value, TreeSetNode<E> *& parent) const {
	parent = NULL;
	TreeSetNode<E> * node = root;
	while (node != NULL) {
		if (node->value == value) {
			return true;
		} else {
			parent = node;
			node = (node->value < value) ? node->right : node->left;
		}
	}
	return false;
}

template<typename E>
TreeSetNode<E> * TreeSet<E>::getLess(TreeSetNode<E>* point) const {
	TreeSetNode<E> * node = point;
	while (node != NULL) {
		if (node->left == NULL)
			return node;
		node = node->left;
	}
	return NULL;
}

/********************************************************************************
 ************************                             ***************************
 ***************           TreeSetIterator Template           *******************
 ************************                             ***************************
 ********************************************************************************/


template<typename E>
class TreeSetIterator: public Iterator<E> {
	private:
		friend class TreeSet<E> ;
		TreeSetIterator() {
			node = NULL;
			lastMove = Printed;
		}
		TreeSetIterator(TreeSetNode<E> * root)
				: node(root) {
			while (node != NULL) {
				if (node->left == NULL)
					break;
				node = node->left;
			}
			if (node == root) {
				lastMove = UpFromLeft;
			} else {
				lastMove = Down;
			}
		}
		virtual ~TreeSetIterator() {
		}
		virtual bool hasNext() const {
			return node != NULL;
		}
		virtual const E& next();
	private:
		enum {
			Printed, UpFromLeft, UpFromRight, Down
		} lastMove;
		TreeSetNode<E> * node;
		E nextValue;
};

template<typename E>
const E& TreeSetIterator<E>::next() {
	while (lastMove == Down && node->left != NULL) {
		node = node->left;
	}
	nextValue = node->value;

	if (lastMove == UpFromLeft || lastMove == Down) {
		if (node->right != NULL) {
			node = node->right;
			lastMove = Down;
		} else {
			if (node->parent != NULL) {
				lastMove = (node->parent->value < node->value) ? UpFromRight : UpFromLeft;
			}
			node = node->parent;
		}
	}
	while (lastMove == UpFromRight && node != NULL) {
		if (node->parent != NULL) {
			lastMove = (node->parent->value < node->value) ? UpFromRight : UpFromLeft;
		}
		node = node->parent;
	}

	return nextValue;
}

#endif /* TREESET_H_ */
