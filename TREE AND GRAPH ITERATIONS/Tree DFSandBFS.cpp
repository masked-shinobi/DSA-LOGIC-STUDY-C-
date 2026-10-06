#include <bits/stdc++.h>

using namespace std;

class TreeNode{
public:
    int v;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v){
        this->v = v;
        left = nullptr;
        right = nullptr;
    }
};

//DFS
TreeNode* inorder(TreeNode* root){
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->v;
    inorder(root->right);
}

TreeNode* preorder(TreeNode* root){
    if (root == nullptr) return;
    cout << root->v;
    preorder(root->left);
    preorder(root->right);
}

TreeNode* postorder(TreeNode* root){
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->v;
}

//BFS
void BFS(TreeNode* root) {
    if (root == nullptr) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        cout << current->v << " ";

        if (current->left != nullptr)
            q.push(current->left);

        if (current->right != nullptr)
            q.push(current->right);
    }
}

int main() {

    return 0;
}