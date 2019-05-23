#include "KeyHash.h"

template <typename K>
unsigned long KeyHash<K>::operator()(const K& key) {
    return reinterpret_cast<unsigned long> (&key) % 111;
}
