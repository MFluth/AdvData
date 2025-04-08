#ifndef HASHTABLECHAININGLINEARPROBING_H
#define HASHTABLECHAININGLINEARPROBING_H

// HashTableLinearProbing.h
#include "HashTable.h"

template <typename K, typename V>
class HashTableLinearProbing : public HashTable<K, V> {
private:
    vector<pair<K, V>> table;
    size_t tableSize;
    size_t currentSize;

    int hash(const K& key) const;
    int probe(int index, int i) const override;

public:
    HashTableLinearProbing(size_t size);
    void insert(const K& key, const V& value) override;
    bool search(const K& key, V& value) override;
    bool remove(const K& key) override;
    void rehash() override;
    void resizeIfNeeded() override;
};

#endif