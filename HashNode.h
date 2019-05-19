#include <iostream>

template <typename K, typename V>
class HashNode {

public:
    HashNode();
    HashNode(const K&, const V&);
    HashNode(const HashNode&);
    V getValue();
    K getKey();
    HashNode getNext();
    void setValue(V);
    void setKey(K);
    void setNext(HashNode*);
private:
    K _Key;
    V _Value;
    HashNode* _Next;
};
