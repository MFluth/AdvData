#ifndef DSWTREE_H
#define DSWTREE_H

#include <fstream>
#include <vector>

class DSWTree {
private:
    struct DSWNode {
        int timestamp;
        int vehicleCount;
        DSWNode* left, * right;
        DSWNode(int t, int v);
    };
    DSWNode* root;
    void inorderStore(DSWNode* node, std::vector<DSWNode*>& nodes);
    DSWNode* buildBalanced(std::vector<DSWNode*>& nodes, int start, int end);
    void printInorder(DSWNode* node, std::ofstream& out);

public:
    DSWTree();
    void insert(int timestamp, int vehicleCount);
    void rebalance();
    void displayHistory(std::ofstream& out);
};

#endif
