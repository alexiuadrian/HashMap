#include <iostream>
#include "HashMap.cpp"
//#include "KeyHash.h"
using namespace std;

//struct

int main()
{
    HashMap<int, int, KeyHash<int> > H;
    H.push(1, 1234);
    //H.push(2, 5678);
    //H.push(3, 9101112);
    return 0;
}
