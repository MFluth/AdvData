#ifndef BINOMIAL_HEAP_H
#define BINOMIAL_HEAP_H

#include <vector>
#include <memory>
#include <limits>
#include "edge.h"

template <typename T>
class BinomialHeap {
private:
    struct Node {
        T key;
        int degree;
        Node* parent;
        Node* child;
        Node* sibling;

        Node(const T& k) : key(k), degree(0), parent(nullptr), child(nullptr), sibling(nullptr) {}
    };

    Node* head;

    void linkTrees(Node* y, Node* z) {
        y->parent = z;
        y->sibling = z->child;
        z->child = y;
        z->degree++;
    }

    Node* mergeHeaps(Node* h1, Node* h2) {
        if (!h1) return h2;
        if (!h2) return h1;

        Node* head = nullptr;
        Node** pos = &head;

        while (h1 && h2) {
            if (h1->degree <= h2->degree) {
                *pos = h1;
                h1 = h1->sibling;
            } else {
                *pos = h2;
                h2 = h2->sibling;
            }
            pos = &((*pos)->sibling);
        }

        *pos = (h1) ? h1 : h2;
        return head;
    }

    Node* unionHeaps(Node* h1, Node* h2) {
        Node* newHead = mergeHeaps(h1, h2);
        if (!newHead) return nullptr;

        Node* prev = nullptr;
        Node* curr = newHead;
        Node* next = curr->sibling;

        while (next) {
            if ((curr->degree != next->degree) ||
                (next->sibling && next->sibling->degree == curr->degree)) {
                prev = curr;
                curr = next;
            } else if (curr->key < next->key) {
                curr->sibling = next->sibling;
                linkTrees(next, curr);
            } else {
                if (!prev) newHead = next;
                else prev->sibling = next;
                linkTrees(curr, next);
                curr = next;
            }
            next = curr->sibling;
        }
        return newHead;
    }

    void deleteAll(Node* node) {
        if (!node) return;
        deleteAll(node->child);
        deleteAll(node->sibling);
        delete node;
    }

public:
    BinomialHeap() : head(nullptr) {}

    ~BinomialHeap() {
        deleteAll(head);
    }

    void insert(const T& value) {
        Node* newNode = new Node(value);
        head = unionHeaps(head, newNode);
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    T extractMin() {
        if (!head) throw std::runtime_error("Heap is empty");

        Node* minNode = head;
        Node* minPrev = nullptr;
        Node* prev = nullptr;
        Node* curr = head;

        T minVal = curr->key;
        while (curr) {
            if (curr->key < minVal) {
                minVal = curr->key;
                minNode = curr;
                minPrev = prev;
            }
            prev = curr;
            curr = curr->sibling;
        }

        if (minPrev) minPrev->sibling = minNode->sibling;
        else head = minNode->sibling;

        Node* child = minNode->child;
        Node* revChild = nullptr;
        while (child) {
            Node* next = child->sibling;
            child->sibling = revChild;
            child->parent = nullptr;
            revChild = child;
            child = next;
        }

        head = unionHeaps(head, revChild);
        T result = minNode->key;
        delete minNode;
        return result;
    }
};

#endif
