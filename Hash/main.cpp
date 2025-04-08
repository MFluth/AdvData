// main.cpp
#include <iostream>
#include "HashTableChainingWithVector.h"
#include "HashTableChainingWithList.h"
#include "HashTableLinearProbing.h"

using namespace std;

void benchmark(HashTableType tableType);

int main() {
    // Example benchmarks
    benchmark(HashTableType::ChainingWithVector);
    benchmark(HashTableType::LinearProbing);
    // Add more cases for different hash table types
    return 0;
}

void benchmark(HashTableType tableType) {
    // Create hash table based on the given type
    HashTable<string, int>* hashTable;

    switch (tableType) {
        case HashTableType::ChainingWithVector:
            hashTable = new HashTableChainingWithVector<string, int>(100);
            break;
        case HashTableType::ChainingWithList:
            hashTable = new HashTableChainingWithList<string, int>(100);
            break;
        case HashTableType::LinearProbing:
            hashTable = new HashTableLinearProbing<string, int>(100);
            break;
        // Add more cases for other types
    }

    // Insert, search, and remove operations for benchmarking
    // Example of inserting a key-value pair
    hashTable->insert("key1", 10);
    int value;
    if (hashTable->search("key1", value)) {
        cout << "Found key1 with value " << value << endl;
    }

    // Don't forget to delete the hash table
    delete hashTable;
}
