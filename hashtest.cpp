#include <iostream>
#include <fstream>

#include "hashtest.h"

using namespace std;

HashTest::HashTest() {
    for (int i = 0; i < SIZE; i++) {
        hashPointer[i] = NULL;
    }
}

void HashTest::fileIn() {
    ifstream infile("data.txt");
    for (int i = 0; i < 144; i++) {
        char *wordBuffer = new char;
        infile >> wordBuffer;
        wordArray[i].word = wordBuffer;
    }
}

void HashTest::outList() {
    cout << "\n\n";
    for (int i = 0; i < arrSize; i++) {
        cout << wordArray[i].word << " "<< wordArray[i].hashCode << " ";
    }
    cout << "\n\n";
    for (int i = 0; i < SIZE; i++) {
        if (hashPointer[i] != NULL) {
            cout <<"\n"<< i << " element of HashTable: "<< hashPointer[i]->word ;
        }
    }
    cout << "\n\n";
}

void HashTest::hashFuncLin () {
    int collisionCounter = 0;
    for (int i =0; i < arrSize; i++) {
        for (int j =0; wordArray[i].word[j] != '\0'; j++) {
            wordArray[i].hashCode = (wordArray[i].hashCode * 256 + wordArray[i].word[j]) % m;
        }
        if (hashPointer[wordArray[i].hashCode] == NULL) {
            hashPointer[wordArray[i].hashCode] = &wordArray[i];
        } else {
            for (int j = 1; hashPointer[wordArray[i].hashCode] != NULL &&  j< m; j++) {
                wordArray[i].hashCode = (wordArray[i].hashCode + j) % m;
                collisionCounter++;
                if ((wordArray[i].hashCode + j)==m) {
                    throw "small hashtable";
                }
                if (hashPointer[wordArray[i].hashCode] == NULL) {
                    hashPointer[wordArray[i].hashCode] = &wordArray[i];
                    break;
                }
            }
        }
    }
    cout << "arrSize " << arrSize <<  "  collisions: " << collisionCounter<<"\n";
    outList();
    for (int i = 0; i < arrSize; i++) {
        wordArray[i].hashCode = 0;
    }
    for (int i = 0; i < SIZE; i++) {
        hashPointer[i] = NULL;
    }
}

void HashTest::hashFuncSquare () {
    int collisionCounter = 0;
    for (int i =0; i < arrSize; i++) {
        for (int j =0; wordArray[i].word[j] != '\0'; j++) {
            wordArray[i].hashCode = (wordArray[i].hashCode * 256 + wordArray[i].word[j]) % m;
        }
        if (hashPointer[wordArray[i].hashCode] == NULL) {
            hashPointer[wordArray[i].hashCode] = &wordArray[i];
        } else {
            for (int j = 1; hashPointer[wordArray[i].hashCode] != NULL &&  j*j< m; j++) {
                wordArray[i].hashCode = (wordArray[i].hashCode + j*j) % m;
                collisionCounter++;
                if ((wordArray[i].hashCode + j*j)==m) {
                    throw "small hashtable";
                }
                if (hashPointer[wordArray[i].hashCode] == NULL) {
                    hashPointer[wordArray[i].hashCode] = &wordArray[i];
                    break;
                }
            }
        }
    }
    cout << "arrSize " << arrSize <<  "  collisions: " << collisionCounter<<"\n";
    outList();
    for (int i = 0; i < SIZE; i++) {
        hashPointer[i] = NULL;
    }
}
