#include "KeyHash.h"
/*
template <typename K>
const unsigned long KeyHash<K>::operator()(const K& key) {
    return reinterpret_cast<unsigned long> (&key) % 111;
}
*/
template class KeyHash<int>;
