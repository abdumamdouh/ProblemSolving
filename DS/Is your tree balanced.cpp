#include<iostream>

using namespace std;

class treeNode {
public:
    int data;
    treeNode * left;
    treeNode * right;


    treeNode(int n){
        this->data = n;
        left = nullptr;
        right = nullptr;
    }

    friend  class bSearchTree;
};

class bSearchTree {
public:

    treeNode* insertNode(int x, treeNode* t)
    {
        if(t == nullptr)
            t = new treeNode(x);
        else if(x < t->data)
            t->left = insertNode(x, t->left);
        else if(x > t->data)
            t->right = insertNode(x, t->right);
        return t;
    }

    treeNode* treeRoot;

    bSearchTree() {
        this->treeRoot = nullptr;
    }

    void insert(int x) {
        this->treeRoot = insertNode(x, treeRoot);
    }

    int height(treeNode* node)
    {
        if (node == nullptr)
            return 0;

        return 1 + max(height(node->left),
                       height(node->right));
    }

    bool balanced(treeNode* root)
    {
        int leftH,rightH;

        if (root == nullptr)
            return true;

        leftH = height(root->left);
        rightH = height(root->right);

        if (abs(leftH - rightH) <= 1 && balanced(root->left) && balanced(root->right))
            return true;

        return false;
    }

};

int max(int a, int b){
    if(a >= b)
        return a;
    else
        return b;
}

int main() {

    int n;
    cin >> n;

    int * arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bSearchTree t;

    for (int i = 0; i < n; i++)
        t.insert(arr[i]);


    if(t.balanced(t.treeRoot))
        cout << "YES";
    else
        cout << "No";

    delete[] arr;

    return 0;
}

