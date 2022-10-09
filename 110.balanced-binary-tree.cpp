// 110. Balanced Binary Tree
#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
    public:
        Node(int data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

Node* buildTree() {

    int n;
    cin >> n;

    if(n == -1) {
        return NULL;
    }

    Node* root = new Node(n);

    root->left = buildTree();

    root->right = buildTree();

    return root;
}

int height(Node* root) {
    if(root == NULL)
        return 0;

    int leftAns = height(root->left);
    int rightAns = height(root->right);

    return 1 + max(leftAns, rightAns);
}

bool isBalanced1(Node* root) {
    
    if(root == NULL)
        return true;

    bool leftAns = isBalanced1(root->left);    
    bool rightAns = isBalanced1(root->right);

    bool diff = abs(height(root->left) - height(root->right)) <= 1;
    
    if(leftAns && rightAns && diff)
        return true;
    else
        return false;
}

pair<int, bool> solve(Node* root) {
    
    if(root == NULL)
        return make_pair(0, true);
    
    pair<int, bool> leftAns = solve(root->left);
    pair<int, bool> rightAns = solve(root->right);

    bool diff = abs(leftAns.first - rightAns.first) <= 1;

    if(leftAns.second && rightAns.second && diff)
        return make_pair(max(leftAns.first, rightAns.first) + 1, true);
    else
        return make_pair(max(leftAns.first, rightAns.first) + 1, false);

}

bool isBalanced(Node* root) {
    pair<int, bool> ans = solve(root);
    return ans.second;
}

int main() {

    Node* root = buildTree();

    cout << isBalanced(root) << endl;

    return 0;
}