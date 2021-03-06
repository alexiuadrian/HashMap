#include "HashNode.h"

template <class K, class V>
HashNode<K, V>::HashNode() {
    this->_Value = 0;
    this->_Next = NULL;
}

template <class K, class V>
HashNode<K, V>::HashNode(const K& k, const V& v) {
    this->_Value = v;
    this->_Key = k;
    this->_Next = NULL;
}


template <class K, class V>
HashNode<K, V>::HashNode(const HashNode& h) {
    this->_Key = h._Key;
    this->_Value = h._Value;
    this->_Next = h._Next;
}

template <class K, class V>
V HashNode<K, V>::getValue() const {
    return this->_Value;
}

template <class K, class V>
K HashNode<K, V>::getKey () const {
    return this->_Key;
}

template <class K, class V>
HashNode<K, V>* HashNode<K, V>::getNext() const {
    return this->_Next;
}

template <class K, class V>
void HashNode<K, V>::setValue(V x) {
    this->_Value = x;
}

template <class K, class V>
void HashNode<K, V>::setKey(K x) {
    this->_Key = x;
}

template <class K, class V>
void HashNode<K, V>::setNext(HashNode<K, V>* x) {
    this->_Next = x;
}

template class HashNode<int, int>;
