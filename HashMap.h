#include "HashNode.h"
#include "KeyHash.h"
#include <iostream>
#include <vector>
using namespace std;

template <class K, class V, class F = KeyHash<K>>
class HashMap {

public:
    HashMap() : _M(), _F() {};
    ~HashMap();
    HashMap(const HashMap&);
    HashMap operator=(const HashMap&);
    V operator[](const K&);
    void push(const K&, const V&);
    void remove(const K&);
    V get(const K&);
    int getNrOfKeys();
    vector<V> getVals(const K&);
    template<class P, class O, class M>
    friend ostream& operator<<(ostream&, const HashMap<P, O, M>&);

private:
    int _Size;
    HashNode<K, V> *_M[111];
    F _F;
};
