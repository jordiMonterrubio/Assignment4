//Jordi Monterrubio
//CS 300
//Assignment 4
//Binary Search Tree
#include <iostream>
using namespace std;

template<class T>
struct node {
    int id;
    T data;
    node<T>* left;
    node<T>* right;
};
template<class T>
class BinarySearchTree {
    //root of the tree
    node<T>* root;
    //finds an empty node to place a new node based on the id
    void findEmpty(node<T>* &a, node<T>* b) {
        if(a == NULL) {
            a = b;
        } else if (b->id < a->id) {
            findEmpty(a->left, b);
        } else if(b->id > a->id) {
            findEmpty(a->right, b);
        }
    }
    //returns data from a node which has the given id
    T returnData(node<T>* n, int id) {
        if(n == NULL) {
            return NULL;
        } else if(id == n->id) {
            return n->data;
        } else if (id < n->id) {
            return returnData(n->left, id);
        } else if(id > n->id) {
            return returnData(n->right, id);
        }
    }
    public:
        //constructor
        BinarySearchTree(){}
        //inserts a new node into the tree
        void insert(int id, T data) {
            node<T> n;
            n.id = id;
            n.data = data;
            if(root == NULL) {
                root = &n;
            } else {
                findEmpty(root, &n);
            }
        }
        //funds a node based on the id and returns the data
        T findData(int id) {
            return returnData(root, id);
        }
};
