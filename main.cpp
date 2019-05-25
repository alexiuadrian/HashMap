#include <iostream>
#include "HashMap.cpp"
//#include "KeyHash.h"
using namespace std;

int main()
{
    HashMap<int, int, KeyHash<int> > H;
    int p = 12, x = 13;
    H.push(p, 1234);
    H.push(x, 5678);
    cout << H.get(p) << ' ' << H.get(x) << endl;
    //H.remove(p);
    H.remove(p);
    cout << H.get(x) << endl;
    //H.push(134, 1234);
    //cout << H.get(134);
    //H.push(2, 5678);
    //H.push(3, 9101112);
    return 0;
}
