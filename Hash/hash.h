#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <functional>
#include <stdexcept>

enum class HashTableType {
    ChainingWithVector,
    ChainingWithList,
    LinearProbing
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
    virtual ~HashTable() = default;
};

// --- Chaining with Vector ---
template <typename K, typename V>
class HashTableChainingWithVector : public HashTable<K, V> {
private:
    std::vector<std::vector<std::pair<K, V>>> table;
    size_t tableSize;
    size_t currentSize;

    int hash(const K& key) const {
        return std::hash<K>{}(key) % tableSize;
    }

public:
    HashTableChainingWithVector(size_t size = 101) : tableSize(size), currentSize(0) {
        table.resize(size);
    }

    void insert(const K& key, const V& value) override {
        int index = hash(key);
        for (auto& pair : table[index]) {
            if (pair.first == key) {
                pair.second = value;
                return;
            }
        }
        table[index].emplace_back(key, value);
        ++currentSize;
    }

    bool search(const K& key, V& value) override {
        int index = hash(key);
        for (const auto& pair : table[index]) {
            if (pair.first == key) {
                value = pair.second;
                return true;
            }
        }
        return false;
    }

    bool remove(const K& key) override {
        int index = hash(key);
        auto& bucket = table[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                --currentSize;
                return true;
            }
        }
        return false;
    }

    void rehash() override {
        // Simple rehash logic
    }

    void resizeIfNeeded() override {
        // Optional
    }

    int probe(int index, int i) const override {
        return (index + i) % tableSize; // Dummy for chaining
    }
};

// --- Chaining with List ---
template <typename K, typename V>
class HashTableChainingWithList : public HashTable<K, V> {
private:
    std::vector<std::list<std::pair<K, V>>> table;
    size_t tableSize;
    size_t currentSize;

    int hash(const K& key) const {
        return std::hash<K>{}(key) % tableSize;
    }

public:
    HashTableChainingWithList(size_t size = 101) : tableSize(size), currentSize(0) {
        table.resize(size);
    }

    void insert(const K& key, const V& value) override {
        int index = hash(key);
        for (auto& pair : table[index]) {
            if (pair.first == key) {
                pair.second = value;
                return;
            }
        }
        table[index].emplace_back(key, value);
        ++currentSize;
    }

    bool search(const K& key, V& value) override {
        int index = hash(key);
        for (const auto& pair : table[index]) {
            if (pair.first == key) {
                value = pair.second;
                return true;
            }
        }
        return false;
    }

    bool remove(const K& key) override {
        int index = hash(key);
        auto& bucket = table[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                --currentSize;
                return true;
            }
        }
        return false;
    }

    void rehash() override {}
    void resizeIfNeeded() override {}
    int probe(int index, int i) const override {
        return (index + i) % tableSize;
    }
};

// --- Linear Probing ---
template <typename K, typename V>
class HashTableLinearProbing : public HashTable<K, V> {
private:
    std::vector<std::pair<K, V>> table;
    std::vector<bool> occupied;
    size_t tableSize;
    size_t currentSize;

    int hash(const K& key) const {
        return std::hash<K>{}(key) % tableSize;
    }

public:
    HashTableLinearProbing(size_t size = 101) : tableSize(size), currentSize(0) {
        table.resize(size);
        occupied.resize(size, false);
    }

    void insert(const K& key, const V& value) override {
        int index = hash(key);
        int i = 0;
        while (occupied[probe(index, i)] && table[probe(index, i)].first != key) {
            ++i;
        }
        int pos = probe(index, i);
        table[pos] = {key, value};
        occupied[pos] = true;
        ++currentSize;
    }

    bool search(const K& key, V& value) override {
        int index = hash(key);
        int i = 0;
        while (occupied[probe(index, i)]) {
            if (table[probe(index, i)].first == key) {
                value = table[probe(index, i)].second;
                return true;
            }
            ++i;
        }
        return false;
    }

    bool remove(const K& key) override {
        int index = hash(key);
        int i = 0;
        while (occupied[probe(index, i)]) {
            if (table[probe(index, i)].first == key) {
                occupied[probe(index, i)] = false;
                --currentSize;
                return true;
            }
            ++i;
        }
        return false;
    }

    void rehash() override {}
    void resizeIfNeeded() override {}
    int probe(int index, int i) const override {
        return (index + i) % tableSize;
    }
};
