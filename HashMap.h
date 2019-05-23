#include "HashNode.h"
#include "KeyHash.h"

template <class K, class V, class F = KeyHash<K>>
class HashMap {

public:
    HashMap();
    //~HashMap();
    HashMap(const HashMap&);
    void push(const K&, const V&);
    void remove(const K&);
    V get(const K&, const V&);

private:
    int _Size;
    HashNode<K, V> **_M;
    F _F;
};
