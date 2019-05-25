#include "HashMap.h"

template <class K, class V, class F>
void HashMap<K, V, F>::push(const K& k, const V& v) {
    unsigned long valFunc = _F(k);
    HashNode<K, V> *last = NULL;
    HashNode<K, V> *aux = _M[valFunc];

    while(aux != NULL && aux->getKey() != k) {
        last = aux;
        aux = aux->getNext();
    }

    if(aux == NULL) {
        aux = new HashNode<K, V>(k, v);

        if(last == NULL) {
            _M[valFunc] = aux;
        }
        else {
            last->setNext(aux);
        }
    }
    else if(last != NULL) {
        HashNode<K, V> *aux1 = new HashNode<K, V>(k, v);
        last->setNext(aux1);
        aux1->setNext(aux);
    }

    if(valFunc > _Size) {
        _Size = valFunc;
    }
}

template<class K, class V, class F>
HashMap<K, V, F>::~HashMap() {
    const int size = 111;

    for(int i = 0; i < size; i++) {
        HashNode<K, V> *aux  = _M[i];
        HashNode<K, V> *aux2  = NULL;
        while(aux != NULL) {
            aux2 = aux;
            aux = aux->getNext();
            delete aux2;
        }
    }
    delete[] _M;
}

template<typename K, typename V, typename F>
void HashMap<K, V, F>::remove(const K& k) {
    unsigned long funcVal = _F(k);
    HashNode<K, V> *aux = _M[funcVal];
    HashNode<K, V> *last = NULL;    //retin ultimul element din lista inainte de aux
    bool found = false;
    int i = 0, pozK = 0;

    do {
        i++;
        last = aux;
        if(aux->getKey() == k) {
            found = true;
            pozK = i;
        }
        aux = aux->getNext();
    }while(aux != NULL && aux->getKey() != k);      //daca nu s-a terminat lista si daca nu s-a mai gasit cheia curenta

    if(found == false) {    //daca nu s-a gasit elementul cu cheia respectiva ies din functie
        return;
    }

    if(pozK == 1) {    //verific daca e primul element din lista
        _M[funcVal] = aux;
        return;
    }

    last->setNext(aux->getNext());
    delete aux;
}

template <typename K, typename V, typename F>
V HashMap<K, V, F>::get(const K& k) {
    unsigned long funcVal = _F(k);
    HashNode<K, V> *aux = _M[funcVal];

    if(aux == NULL) {   //daca nu exista cheia returnez NULL
        return NULL;
    }

    //cout << funcVal << endl;
    while(aux != NULL) {    //altfel caut in lista pana il gasesc
        if(aux->getKey() == k) {
            return aux->getValue();
        }
        aux = aux->getNext();
    }

    //return 1;
}


template <class K, class V, class F>
HashMap<K, V, F>::HashMap(const HashMap& x) {
    this->_Size = x._Size;

    for(int i = 0; i < this->_Size; ++i) {
        push(x._M[i]->getKey(), x._M[i]->getValue());
    }

    this->_F = x._F;
}


template <class K, class V, class F>
HashMap<K, V, F> HashMap<K, V, F>::operator=(const HashMap& x) {
    this->_Size = x._Size;

    for(int i = 0; i < this->_Size; ++i) {
        push(x._M[i]->getKey(), x._M[i]->getValue());
    }

    this->_F = x._F;
}

template <class K, class V, class F>
V HashMap<K, V, F>::operator[](const K& k) {
    unsigned long funcVal = _F(k);
    HashNode<K, V> *aux = _M[funcVal];

    while(aux != NULL) {
        if(aux->getKey() == k) {
            return aux->getValue();
        }
        aux = aux->getNext();
    }

    return -1;
}

template<class K, class V, class F>
int HashMap<K, V, F>::getNrOfKeys() {
    int nr = 0;
    const int size = 111;
    for(int i = 0; i < size; i++) {
        if(_M[i] != NULL) {
            nr++;
        }
    }

    return nr - 1;
}

template<class K, class V, class F>
vector<V> HashMap<K, V, F>::getVals(const K& k) {
    unsigned long funcVal = _F(k);
    HashNode<K, V> *aux = _M[funcVal];
    vector<V> v;

    while(aux != NULL) {
        if(aux->getKey() == k) {
            v.push_back(aux->getValue());
        }
        aux = aux->getNext();
    }

    return v;
}

template<class K, class V, class F>
ostream& operator<<(ostream& out, const HashMap<K, V, F>& x) {
    const int size = 111;
    for(int i = 0; i < size; i++) {
        HashNode<K, V> *aux = x._M[i];
        while(aux != NULL) {
            out << aux->getKey() << ' ' << aux->getValue() << endl;
            aux = aux->getNext();
        }
    }
}

template class HashMap<int, int, KeyHash<int> >;
