#ifndef HASHTABLECHAININGWITHLIST_H
#define HASHTABLECHAININGWITHLIST_H

// HashTableChainingWithList.h
#include "HashTable.h"

template <typename K, typename V>
class HashTableChainingWithList : public HashTable<K, V> {
private:
    vector<list<pair<K, V>>> table;
    size_t tableSize;
    size_t currentSize;

    int hash(const K& key) const {
        return std::hash<K>{}(key) % tableSize;
    }

public:
    HashTableChainingWithList(size_t size);
    void insert(const K& key, const V& value) override;
    bool search(const K& key, V& value) override;
    bool remove(const K& key) override;
    void rehash() override;
    void resizeIfNeeded() override;
    int probe(int index, int i) const override;
};

#endif