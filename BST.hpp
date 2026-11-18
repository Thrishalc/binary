
#ifndef BST_HPP
#define BST_HPP

#include <iostream>
using namespace std;

template <typename T>
class BST {

private:

    // Node structure
    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(T value) {
            data = value;
            left = nullptr;
            right = nullptr;
        }
    };

    Node* root;

    // Recursive insertion
    Node* insert(Node* node, T value) {

        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        }
        else if (value > node->data) {
            node->right = insert(node->right, value);
        }

        // Duplicate values are ignored
        return node;
    }

    // Recursive search
    bool search(Node* node, T value) const {

        if (node == nullptr) {
            return false;
        }

        if (node->data == value) {
            return true;
        }

        if (value < node->data) {
            return search(node->left, value);
        }

        return search(node->right, value);
    }

    // Find minimum node
    Node* findMin(Node* node) const {

        while (node != nullptr && node->left != nullptr) {
            node = node->left;
        }

        return node;
    }

    // Recursive deletion
    Node* deleteNode(Node* node, T value) {

        if (node == nullptr) {
            return nullptr;
        }

        if (value < node->data) {
            node->left = deleteNode(node->left, value);
        }
        else if (value > node->data) {
            node->right = deleteNode(node->right, value);
        }
        else {

            // Case 1: No child
            if (node->left == nullptr &&
                node->right == nullptr) {

                delete node;
                return nullptr;
            }

            // Case 2: One child
            else if (node->left == nullptr) {

                Node* temp = node->right;
                delete node;
                return temp;
            }

            else if (node->right == nullptr) {

                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Case 3: Two children
            Node* temp = findMin(node->right);

            node->data = temp->data;

            node->right =
                deleteNode(node->right, temp->data);
        }

        return node;
    }

    // In-Order traversal
    void inOrder(Node* node) const {

        if (node == nullptr) return;

        inOrder(node->left);

        cout << node->data << " ";

        inOrder(node->right);
    }

    // Pre-Order traversal
    void preOrder(Node* node) const {

        if (node == nullptr) return;

        cout << node->data << " ";

        preOrder(node->left);

        preOrder(node->right);
    }

    // Post-Order traversal
    void postOrder(Node* node) const {

        if (node == nullptr) return;

        postOrder(node->left);

        postOrder(node->right);

        cout << node->data << " ";
    }

    // Memory cleanup
    void destroyTree(Node* node) {

        if (node == nullptr) return;

        destroyTree(node->left);

        destroyTree(node->right);

        delete node;
    }

public:

    // Constructor
    BST() {
        root = nullptr;
    }

    // Public insertion
    void Insert(T value) {
        root = insert(root, value);
    }

    // Public search
    bool Search(T value) const {
        return search(root, value);
    }

    // Public deletion
    void Delete(T value) {
        root = deleteNode(root, value);
    }

    // Public traversals
    void InOrder() const {
        inOrder(root);
        cout << endl;
    }

    void PreOrder() const {
        preOrder(root);
        cout << endl;
    }

    void PostOrder() const {
        postOrder(root);
        cout << endl;
    }

    // Destructor
    ~BST() {
        destroyTree(root);
        root = nullptr;
    }

    // Prevent shallow copying and double deletion
    BST(const BST&) = delete;
    BST& operator=(const BST&) = delete;

};

#endif
