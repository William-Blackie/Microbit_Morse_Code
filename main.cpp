#include <iostream>
class BinaryTree {

private:

    struct node{
        int key;
        node* left;
        node* right;
    };
    node* root;

    void addLeafPrivate(int key, node* ptr);
    void printInOrderPrivate(node* ptr);
    node* returnNodePrivate(int key, node* ptr);

public:

    BinaryTree();
    node* CreateLeaf(int key);
    void addLeaf(int key);
    void printInOrder();
    node* returnNode(int key);
};





using namespace std;

BinaryTree::BinaryTree() {
    root = nullptr;

}

BinaryTree::node* BinaryTree::CreateLeaf(int key) {

    auto n = new node;
    n->key= key;
    n->left = nullptr;
    n->right= nullptr;

    return n;

}

//always starts at the root. Calls the add leaf private function which passes in the key and the root pointer.
void BinaryTree::addLeaf(int key){
    addLeafPrivate(key, root);
}

void BinaryTree::addLeafPrivate(int key, node* ptr){
    if(root == nullptr){
        root = CreateLeaf(key);
    } else if(key < ptr->key){
        if(ptr->left != nullptr){
            addLeafPrivate(key, ptr->left);
        }else{
            ptr->left = CreateLeaf(key);
        }
    }
    else if(key > ptr->key){
        if(ptr->right != nullptr){
            addLeafPrivate(key, ptr->right);
        }
        else{
            ptr->right = CreateLeaf(key);
        }
    }
    else{
        cout << "The key" << key << " has already been added to the tree\n";
    }

}

void BinaryTree::printInOrder() {
    printInOrderPrivate(root);
}

void BinaryTree::printInOrderPrivate(node* ptr){
    if(root!= nullptr){
        if(ptr->left != nullptr){
            printInOrderPrivate(ptr->left);
        }
        cout << ptr->key << " ";

        if(ptr->right != nullptr){
            printInOrderPrivate(ptr->right);
        }
    }
    else{
        cout << "The tree is empty\n";
    }
}

BinaryTree::node* BinaryTree::returnNode(int key) {
        return returnNodePrivate(key, root);
}

BinaryTree::node* BinaryTree::returnNodePrivate(int key, node *ptr) {
    if(ptr != NULL){
        if(ptr->key == key){
            return ptr;
        }else{
            if(key < ptr->key){
                return returnNodePrivate(key, ptr->left);
            }else{
                return returnNodePrivate(key, ptr->right);
            }
        }
    }else{
        return NULL;
    }
}

int main() {

    int treeKeys[16] = {56, 17,23,34,2334,5656,7,8,555,6754457,654646,12,19,92,99,18};

    BinaryTree myTree;

    cout << "Printing the tree in order\nBefore adding numbers\n";

    myTree.printInOrder();

    for(int i=0; i<16; i++){
        myTree.addLeaf(treeKeys[i]);
    }
    cout << "Printing the tree in order\nAfter adding numbers\n";

    myTree.printInOrder();

    cout << endl;

    return 0;
}