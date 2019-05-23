#include "HashMap.h"

template <class K, class V, class F>
HashMap<K, V, F>::HashMap() {
    /*
    this->_Prim = this->_Ultim = NULL;
    this->_Size = 0;
    */
    _M = new HashNode<K, V> *[_Size];
}

template <class K, class V, class F>
void HashMap<K, V, F>::push(const K& k, const V& v) {
    unsigned long funcVal = _F(k);
    HashNode<K, V> *aux = _M[funcVal];
    int i = 0;

    while(aux != NULL && aux->getNext() != NULL && aux->getKey() != k) {    //daca nu s-a terminat lista si daca nu s-a mai gasit cheia curenta
        aux = aux->getNext();
        i++;
    }

    if(aux == NULL) {   //daca s-a ajuns la finalul listei la cautare
        aux = new HashNode<K, V>(k, v);
        if(i == 0) {    //inserez la inceput daca nu mai e niciun element in lista
            _M[funcVal] = aux;
        }
        else {      //altfel inserez la final
            aux->setNext(aux);
        }
    }

}
/*
template<class K, class V, class F>
HashMap<K, V, F>::~HashMap() {
    for(int i = 0; i < _Size; i++) {
        HashNode<K, V> *aux  = _M[i];
        HashNode<K, V> *aux2  = NULL;
        while(aux != NULL) {
            aux2 = aux;
            delete aux2;
            aux = aux->getNext();
        }
    }
    delete[] _M;
}
*/
template<typename K, typename V, typename F>
void HashMap<K, V, F>::remove(const K& k) {
    unsigned long funcVal = _F(k);
    HashNode<K, V> *aux = _M[funcVal];
    HashNode<K, V> *last = NULL;    //retin ultimul element din lista inainte de aux
    int i = 0;

    while(aux != NULL && aux->getKey() != k) {    //daca nu s-a terminat lista si daca nu s-a mai gasit cheia curenta
        last = aux;
        aux = aux->getNext();
        i++;
    }

    if(i == 0) {    //daca nu s-a gasit elementul cu cheia respectiva ies din functie
        return;
    }

    if(i == 1) {    //verific daca e primul element din lista
        _M[funcVal] = aux->getNext();
        delete aux;
        return;
    }

    last->setNext(aux->getNext());
    delete aux;
}

template <typename K, typename V, typename F>
V HashMap<K, V, F>::get(const K& k, const V& v) {
    unsigned long funcVal = _F(k);
    HashNode<K, V> *aux = _M[funcVal];

    if(aux == NULL) {   //daca nu exista cheia returnez NULL
        return NULL;
    }

    while(aux != NULL) {    //altfel caut in lista pana il gasesc
        if(aux->getValue() == v) {
            return aux->getValue();
        }
        aux = aux->getNext();
    }
}

/*
template <class K, class V, class F>
HashMap<K, V, F>::HashMap(const HashMap& x) {
    HashNode<K, V>* p = _Prim;
    for(int i = 0; i < this->_Size; ++i) {

    }

}
*/

/*
template <class K, class V, class F>
HashMap<K, V, F>::~HashMap() {
    for(int i = 0)
}
*/
