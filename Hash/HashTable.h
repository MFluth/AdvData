#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <functional>

using namespace std;

enum class HashTableType {
    ChainingWithVector,
    ChainingWithList,
    ChainingWithBST,
    LinearProbing,
    QuadraticProbing,
    DoubleHashing
};

template <typename K, typename V>
class HashTable {
public:
    virtual void insert(const K& key, const V& value) = 0;
    virtual bool search(const K& key, V& value) = 0;
    virtual bool remove(const K& key) = 0;
    virtual void rehash() = 0;
    virtual void resizeIfNeeded() = 0;
    virtual int probe(int index, int i) const = 0;
};

#endif // HASHTABLE_H