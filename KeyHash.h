template <typename K>
class KeyHash {
public:
    unsigned long operator()(const K&);
};
