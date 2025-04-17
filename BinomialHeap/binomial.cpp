#include "binomial.h"

binomialNode::binomialNode(int k)
{
    key = k;
    degree = 0;
    parent = nullptr;
    sibling = nullptr;
    child = nullptr;
}

// ---------------------- PRIVATE FUNCTIONS ------------------------------

binomialNode* BinomialHeap::unionHeap(binomialNode* heap1, binomialNode* heap2)
{
    if (!heap1) return heap2;
    if (!heap2) return heap1;

    binomialNode* newHead = nullptr;
    binomialNode** pos = &newHead;

    while (heap1 && heap2)
    {
        if (heap1->degree <= heap2->degree)
        {
            *pos = heap1;
            heap1 = heap1->sibling;
        }
        else
        {
            *pos = heap2;
            heap2 = heap2->sibling;
        }
        pos = &((*pos)->sibling);
    }

    *pos = (heap1) ? heap1 : heap2;

    return newHead;
}

binomialNode* BinomialHeap::mergeTrees(binomialNode* tree1, binomialNode* tree2)
{
    if (tree1->key > tree2->key)
        swap(tree1, tree2);

    tree2->parent = tree1;
    tree2->sibling = tree1->child;
    tree1->child = tree2;
    tree1->degree++;

    return tree1;
}

void BinomialHeap::linkTrees(binomialNode*& prev, binomialNode*& cur, binomialNode*& next)
{
    if (cur->degree != next->degree || (next->sibling && next->sibling->degree == cur->degree))
    {
        prev = cur;
        cur = next;
    }
    else
    {
        if (cur->key <= next->key)
        {
            cur->sibling = next->sibling;
            mergeTrees(cur, next);
        }
        else
        {
            if (!prev)
                head = next;
            else
                prev->sibling = next;
            mergeTrees(next, cur);
            cur = next;
        }
    }
}

void BinomialHeap::clear(binomialNode* node)
{
    if (!node) return;

    clear(node->child);
    clear(node->sibling);
    delete node;
}

binomialNode* BinomialHeap::findNode(binomialNode* node, int key)
{
    if (!node) return nullptr;

    if (node->key == key)
        return node;

    binomialNode* res = findNode(node->child, key);
    if (res) return res;

    return findNode(node->sibling, key);
}

// ---------------- PUBLIC FUNCTIONS ------------------------------

BinomialHeap::BinomialHeap()
{
    head = nullptr;
}

BinomialHeap::~BinomialHeap()
{
    clear(head);
}

void BinomialHeap::insert(int key)
{
    BinomialHeap tempHeap;
    tempHeap.head = new binomialNode(key);
    head = unionHeap(head, tempHeap.head);

    if (!head || !head->sibling)
        return;

    binomialNode* prev = nullptr;
    binomialNode* cur = head;
    binomialNode* next = cur->sibling;

    while (next)
    {
        linkTrees(prev, cur, next);
        next = cur->sibling;
    }
}

void BinomialHeap::merge(BinomialHeap& other)
{
    head = unionHeap(head, other.head);
    other.head = nullptr;

    if (!head || !head->sibling)
        return;

    binomialNode* prev = nullptr;
    binomialNode* cur = head;
    binomialNode* next = cur->sibling;

    while (next)
    {
        linkTrees(prev, cur, next);
        next = cur->sibling;
    }
}

int BinomialHeap::findMin()
{
    if (!head)
        throw runtime_error("Heap is empty");

    binomialNode* minNode = head;
    int minKey = head->key;

    binomialNode* temp = head->sibling;
    while (temp)
    {
        if (temp->key < minKey)
        {
            minKey = temp->key;
            minNode = temp;
        }
        temp = temp->sibling;
    }

    return minKey;
}

void BinomialHeap::decreaseKey(int oldKey, int newKey)
{
    if (newKey > oldKey)
    {
        cout << "New key is greater than old key." << endl;
        return;
    }

    binomialNode* node = findNode(head, oldKey);
    if (!node)
    {
        cout << "Key not found." << endl;
        return;
    }

    node->key = newKey;

    binomialNode* current = node;
    binomialNode* parent = node->parent;

    while (parent && current->key < parent->key)
    {
        swap(current->key, parent->key);
        current = parent;
        parent = current->parent;
    }
}

void BinomialHeap::deleteKey(int key)
{
    decreaseKey(key, INT_MIN);
    deleteMin();
}

void BinomialHeap::deleteMin()
{
    if (!head)
    {
        cout << "Heap is empty.\n";
        return;
    }

    binomialNode* minNode = head;
    binomialNode* minPrev = nullptr;
    binomialNode* prev = nullptr;
    binomialNode* curr = head;
    int minKey = curr->key;

    while (curr)
    {
        if (curr->key < minKey)
        {
            minKey = curr->key;
            minNode = curr;
            minPrev = prev;
        }
        prev = curr;
        curr = curr->sibling;
    }

    if (minPrev)
        minPrev->sibling = minNode->sibling;
    else
        head = minNode->sibling;

    binomialNode* child = minNode->child;
    binomialNode* revChild = nullptr;

    while (child)
    {
        binomialNode* next = child->sibling;
        child->sibling = revChild;
        child->parent = nullptr;
        revChild = child;
        child = next;
    }

    BinomialHeap newHeap;
    newHeap.head = revChild;

    head = unionHeap(head, newHeap.head);

    binomialNode* prevLink = nullptr;
    binomialNode* curLink = head;
    binomialNode* nextLink = curLink ? curLink->sibling : nullptr;

    while (nextLink)
    {
        linkTrees(prevLink, curLink, nextLink);
        nextLink = curLink->sibling;
    }

    delete minNode;
}

void BinomialHeap::printHeap()
{
    cout << "Binomial Heap:\n";
    binomialNode* current = head;

    while (current != nullptr)
    {
        cout << endl << "Tree of degree " << current->degree << endl;
        printTree(current, 0);
        current = current->sibling;
    }
}

void BinomialHeap::printTree(binomialNode* node, int space)
{
    if (node == nullptr)
        return;

    cout << setw(space) << "" << node->key << endl;

    binomialNode* child = node->child;
    while (child)
    {
        printTree(child, space + 4);
        child = child->sibling;
    }
}
