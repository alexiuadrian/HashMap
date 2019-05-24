template <typename K>
class KeyHash {
public:
    const unsigned long operator()(const K& key) const {
        return reinterpret_cast<unsigned long> (&key) % 111;
    };
};
