#include <iostream>
#include <fstream>

#include "hashtest.h"

using namespace std;
using namespace std;

int main() {
    HashTest hashtest;
    try {
        hashtest.fileIn();
        hashtest.hashFuncLin();
    } catch (const char *str) {
        cout<<str<<"  in hashFuncLin() test\n";
    }
    try {
        hashtest.hashFuncSquare();
    } catch (const char *str) {
        cout<<str<<"  in hashFuncLin() test\n";
    }
    return 0;
}
