#include "HashNode.h"
#include "KeyHash.h"
#include <iostream>
using namespace std;

template <class K, class V, class F = KeyHash<K>>
class HashMap {

public:
    HashMap();
    ~HashMap();
    HashMap(const HashMap&);
    void push(const K&, const V&);
    void remove(const K&);
    V get(const K&);

private:
    int _Size;
    HashNode<K, V> **_M;
    F _F;
};
