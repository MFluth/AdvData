#include "Hash.h"
#include <chrono>

using namespace std;

template <typename T>
void runBenchmark(HashTableType type, const vector<string>& keys, const vector<T>& values) {
    HashTable<string, T>* table = nullptr;

    switch (type) {
        case HashTableType::ChainingWithVector:
            table = new HashTableChainingWithVector<string, T>();
            break;
        case HashTableType::ChainingWithList:
            table = new HashTableChainingWithList<string, T>();
            break;
        case HashTableType::LinearProbing:
            table = new HashTableLinearProbing<string, T>();
            break;
    }

    auto start = chrono::high_resolution_clock::now();

    for (size_t i = 0; i < keys.size(); ++i) {
        table->insert(keys[i], values[i]);
    }

    auto mid = chrono::high_resolution_clock::now();

    T out;
    for (const auto& key : keys) {
        table->search(key, out);
    }

    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> insertTime = mid - start;
    chrono::duration<double> searchTime = end - mid;

    cout << "Insert time: " << insertTime.count() << "s\n";
    cout << "Search time: " << searchTime.count() << "s\n";

    delete table;
}

int main() {
    vector<string> keys = {"alpha", "beta", "gamma", "delta", "epsilon"};
    vector<int> values = {1, 2, 3, 4, 5};

    cout << "\n--- Chaining with Vector ---\n";
    runBenchmark(HashTableType::ChainingWithVector, keys, values);

    cout << "\n--- Chaining with List ---\n";
    runBenchmark(HashTableType::ChainingWithList, keys, values);

    cout << "\n--- Linear Probing ---\n";
    runBenchmark(HashTableType::LinearProbing, keys, values);

    return 0;
}
