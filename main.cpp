#include <iostream>
#include <assert.h>
#include "HashMap.cpp"
using namespace std;

int main()
{
    HashMap<int, int, KeyHash<int> > H;
    int p = 12, x = 13;
    H.push(x, 1234);

    //assert(H.getNrOfKeys() == 1);
    assert(H.get(x) == 1234);

    H.push(p, 12);
    cout << H[x] << ' ' << H.getNrOfKeys() << endl;
    vector<int> V = H.getVals(p);
    cout << V[0] << endl;
    cout << H;
    return 0;
}
