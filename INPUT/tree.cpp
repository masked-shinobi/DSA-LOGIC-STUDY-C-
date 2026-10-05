#include <bits/stdc++.h>

using namespace std;

class TreeNode{
public:
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value){
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode* tree_creation(vector<int> arr){
    if(arr.empty()) return nullptr;

    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();

        
        if(arr.size() > 1){
            TreeNode* node = new TreeNode(arr[i]);
            curr->left = node;
            q.push(node);
            i++;
        }
        if(arr.size() > 1){
            TreeNode* node = new TreeNode(arr[i]);
            curr->right = node;
            q.push(node);
            i++;
        }
    }
    
    return root;
}

int main() {

    // level order taken input as vector then taken forward to the function in creation
    // size given
    int x;
    cout << "Enter the size of the tree elements : ";
    cin >> x;

    vector<int> elements;
    cout << "Enter your tree elements size is "<< x << " : ";
    for( int i = 0; i < x; i++ ){
        int a;
        cin >> a;
        elements.push_back(a);
    }

    // creation of a tree
    TreeNode* root = tree_creation(elements);

  
    return 0;
}