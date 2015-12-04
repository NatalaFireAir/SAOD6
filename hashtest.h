#ifndef HASHTEST_H
#define HASHTEST_H

#define SIZE 2777

class HashTest {
    struct Elem {
        char *word;
        int hashCode = 0;
    };
    int arrSize = 144;
    Elem wordArray[144];
    int m = SIZE;
    Elem *hashPointer[SIZE];
public:
    HashTest();
    void fileIn();
    void outList();
    void hashFuncLin();
    void hashFuncSquare ();
};

#endif // HASHTEST_H
