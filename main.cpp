#include <iostream>
#include "HashMap.cpp"
//#include "KeyHash.h"
using namespace std;
/*
struct HashKey {
    unsigned long operator() (const )
};
*/
int main()
{
    HashMap<int, int, KeyHash<int> > H;
    H.push(12, 1234);
    cout << H.get(12) << endl;
    H.remove(12);
    //H.push(134, 1234);
    //cout << H.get(134);
    //H.push(2, 5678);
    //H.push(3, 9101112);
    return 0;
}
