#include <iostream>
#include <vector>

class BTreeNode {
   public:
    std::vector<int> keys;
    int value;

};

class BTree {
   public:
    BTreeNode* root_;   // pointer root node
    int t_;             // minimum degree

    BTree(int t): root_(nullptr), t_(t) {};

    void insert(int k) {
        if (root_ == nullptr) {
            root_ = new BTreeNode();
        }
    }
};

int main(int argc, char* argv[]) {
    (void) argc;
    (void) argv;

    BTree tree(5);

    return 0;
}