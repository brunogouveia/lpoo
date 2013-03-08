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

template<typename E>
class TreeSet;

template<typename E>
class TreeSetNode {
	private:
		friend class TreeSet<E> ;
		TreeSetNode()
				: left(NULL), right(NULL) {
		}
		TreeSetNode(const E value)
				: value(value), left(NULL), right(NULL) {
		}
		TreeSetNode(const E value, const TreeSetNode * left, const TreeSetNode * right) {
			this->value = value;
			this->left = left;
			this->right = right;
		}
		~TreeSetNode() {
		}

		E value;
		TreeSetNode * left;
		TreeSetNode * right;
};

template<typename E>
class TreeSet: public SortedSet<E> {
	public:
		TreeSet(): numNodes(0), root(NULL) {
		}
		~TreeSet() {
			clear();
		}
		/*void add(const Collection<E> & collection){
			Collection<E>::add(collection);
		}*/
		void add(const E & value);
		bool remove(const E& value);
		void clear();
		bool isEmpty() const;
		int size() const;
		bool contains(const E& value) const;
		Iterator<E>* iterator() const;

	private:
		bool contains(const E& value, TreeSetNode<E> *& parent) const;
	private:
		int numNodes;
		TreeSetNode<E> * root;
};

template<typename E>
void TreeSet<E>::add(const E& value) {
	TreeSetNode<E> * parent;
	if (!contains(value, parent)) {
		if (parent == NULL) {
			root = new TreeSetNode<E>(value);
		} else if (parent->value < value) {
			parent->left = new TreeSetNode<E>(value);
		} else {
			parent->right = new TreeSetNode<E>(value);
		}
		numNodes++;
	}
}

template<typename E>
bool TreeSet<E>::remove(const E& value) {
	if (root == NULL) {
		return false;
	}
	TreeSetNode<E> * parent;
	if (contains(value, parent)) {
		TreeSetNode<E> * node;
		if (parent == NULL) {
			if (root->left == NULL && root->right == NULL) {
				delete root;
				root = NULL;
			} else if (root->left == NULL) {
				node = root;
				root = root->right;
				delete node;
			} else {
				node = root;
				root->left->right = root->right;
				root = root->left;
				delete node;
			}
		}
		numNodes--;
	} else {
		return false;
	}
}

template<typename E>
void TreeSet<E>::clear() {
	while (!isEmpty()) {
		remove(root->value);
	}
}

//perguntando se a colecao eh vaziazona ou gordona
template<typename E>
bool TreeSet<E>::isEmpty() const {
	return numNodes == 0;
}
template<typename E>
int TreeSet<E>::size() const {
	return numNodes;
}

template<typename E>
bool TreeSet<E>::contains(const E& value) const {
	TreeSetNode<E> * useless;
	return contains(value, useless);
}
//a colecao disponibiliza um ponteiro para o iterador,
//que eh o objeto responsavel pela manipulacao da colecao
template<typename E>
Iterator<E>* TreeSet<E>::iterator() const {

}

template<typename E>
bool TreeSet<E>::contains(const E& value, TreeSetNode<E> *& parent) const {
	parent = NULL;
	TreeSetNode<E> * node = root;
	while (node != root) {
		if (node->value == value) {
			return true;
		} else {
			parent = node;
			node = (node->value > value) ? node->right : node->left;
		}
	}
	return false;
}

#endif /* TREESET_H_ */
