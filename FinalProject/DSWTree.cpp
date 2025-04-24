#include "DSWTree.h"
#include <vector>

DSWTree::DSWNode::DSWNode(int t, int v) : timestamp(t), vehicleCount(v), left(nullptr), right(nullptr) {}

DSWTree::DSWTree() : root(nullptr) {}

void DSWTree::inorderStore(DSWNode* node, std::vector<DSWNode*>& nodes) {
    if (!node) return;
    inorderStore(node->left, nodes);
    nodes.push_back(node);
    inorderStore(node->right, nodes);
}

DSWTree::DSWNode* DSWTree::buildBalanced(std::vector<DSWNode*>& nodes, int start, int end) {
    if (start > end) return nullptr;
    int mid = (start + end) / 2;
    DSWNode* root = nodes[mid];
    root->left = buildBalanced(nodes, start, mid - 1);
    root->right = buildBalanced(nodes, mid + 1, end);
    return root;
}

void DSWTree::printInorder(DSWNode* node, std::ofstream& out) {
    if (!node) return;
    printInorder(node->left, out);
    out << "Timestamp: " << node->timestamp << ", Vehicles: " << node->vehicleCount << std::endl;
    printInorder(node->right, out);
}

void DSWTree::insert(int timestamp, int vehicleCount) {
    DSWNode* node = new DSWNode(timestamp, vehicleCount);
    if (!root) root = node;
    else {
        DSWNode* curr = root;
        while (true) {
            if (timestamp < curr->timestamp) {
                if (!curr->left) { curr->left = node; break; }
                curr = curr->left;
            } else {
                if (!curr->right) { curr->right = node; break; }
                curr = curr->right;
            }
        }
    }
}

void DSWTree::rebalance() {
    std::vector<DSWNode*> nodes;
    inorderStore(root, nodes);
    root = buildBalanced(nodes, 0, nodes.size() - 1);
}

void DSWTree::displayHistory(std::ofstream& out) {
    out << "\nHistorical Traffic Data:\n";
    printInorder(root, out);
}
