#include <bits/stdc++.h>

using namespace std;

class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : value(value), left(nullptr), right(nullptr) {}

    // Height of tree (in nodes)
    static int heightoftree(TreeNode* root) {
        if (root == nullptr) return 0;

        int leftheight = heightoftree(root->left);
        int rightheight = heightoftree(root->right);

        return 1 + max(leftheight, rightheight);
    }

    // Count leaves
    static int countleaves(TreeNode* root) {
        if (root == nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr) return 1;

        return countleaves(root->left) + countleaves(root->right);
    }

    // Count internal nodes
    static int internalcount(TreeNode* root) {
        if (root == nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr) return 0;

        return 1 + internalcount(root->left) + internalcount(root->right);
    }

    // Count total nodes
    static int totalnodes(TreeNode* root) {
        if (root == nullptr) return 0;

        return 1 + totalnodes(root->left) + totalnodes(root->right);
    }

    // Identical trees
    static bool identical(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;

        return p->value == q->value
            && identical(p->left, q->left)
            && identical(p->right, q->right);
    }

    // Symmetry (mirror check). Call as: symmetry(root->left, root->right)
    static bool symmetry(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;

        return p->value == q->value
            && symmetry(p->left, q->right)
            && symmetry(p->right, q->left);
    }

    // Diameter (longest path through any node, measured in edges)
    static int diameterHelper(TreeNode* root, int& dia) {
        if (root == nullptr) return 0;

        int leftHeight = diameterHelper(root->left, dia);
        int rightHeight = diameterHelper(root->right, dia);

        dia = max(dia, leftHeight + rightHeight);

        return 1 + max(leftHeight, rightHeight);
    }

    static int diameter(TreeNode* root) {
        int dia = 0;
        diameterHelper(root, dia);
        return dia;
    }

    // BST validation. Call as: validbst(root, LLONG_MIN, LLONG_MAX)
    static bool validbst(TreeNode* root, long long low, long long high) {
        if (root == nullptr) return true;
        if (root->value <= low || root->value >= high) return false;

        return validbst(root->left, low, root->value)
            && validbst(root->right, root->value, high);
    }

    // BST search
    static bool searchbst(TreeNode* root, int key) {
        if (root == nullptr) return false;
        if (root->value == key) return true;

        if (key < root->value) return searchbst(root->left, key);
        return searchbst(root->right, key);
    }

    // Invert a tree
    static void invert(TreeNode* root) {
        if (root == nullptr) return;

        swap(root->left, root->right);

        invert(root->left);
        invert(root->right);
    }

    // Lowest common ancestor (assumes both values exist in the tree)
    static TreeNode* lca(TreeNode* root, int a, int b) {
        if (root == nullptr) return nullptr;
        if (root->value == a || root->value == b) return root;

        TreeNode* left = lca(root->left, a, b);
        TreeNode* right = lca(root->right, a, b);

        if (left && right) return root;

        return left ? left : right;
    }

    // Max root-to-leaf path sum
    static int maxpathsum(TreeNode* root) {
        if (root == nullptr) return INT_MIN;  // never chosen over a real path

        if (root->left == nullptr && root->right == nullptr) {
            return root->value;
        }

        int left = maxpathsum(root->left);
        int right = maxpathsum(root->right);

        return root->value + max(left, right);
    }

    // Count of root-to-leaf paths whose sum equals target
    static int countpath(TreeNode* root, int target) {
        if (root == nullptr) return 0;

        target -= root->value;

        if (root->left == nullptr && root->right == nullptr) {
            return (target == 0) ? 1 : 0;
        }

        return countpath(root->left, target) + countpath(root->right, target);
    }

    // Left view
    static vector<int> leftview(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                if (i == 0) {
                    result.push_back(curr->value);
                }
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }
        return result;
    }

    // Right view
    static vector<int> rightview(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                if (i == size - 1) {
                    result.push_back(curr->value);
                }
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }
        return result;
    }

    // Serialise (preorder, "N" for null)
    static void serialise(TreeNode* root) {
        if (root == nullptr) {
            cout << "N ";
            return;
        }
        cout << root->value << " ";
        serialise(root->left);
        serialise(root->right);
    }

    // Max level sum
    static int maxlevelsum(TreeNode* root) {
        if (root == nullptr) return 0;

        queue<TreeNode*> q;
        q.push(root);

        int maxsum = INT_MIN;

        while (!q.empty()) {
            int size = q.size();
            int levelsum = 0;

            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                levelsum += curr->value;

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            maxsum = max(maxsum, levelsum);
        }
        return maxsum;
    }
    // Left boundary: top to bottom, skip leaves
void leftboundary(TreeNode* root, vector<int>& res) {
    TreeNode* curr = root->left;

    while (curr) {
        if (!isleaf(curr)) res.push_back(curr->value);

        if (curr->left) curr = curr->left;
        else curr = curr->right;
    }
}

// Leaves: left to right
void addleaves(TreeNode* root, vector<int>& res) {
    if (root == nullptr) return;

    if (isleaf(root)) {
        res.push_back(root->value);
        return;
    }

    addleaves(root->left, res);
    addleaves(root->right, res);
}

// Right boundary: collect top to bottom, add in reverse, skip leaves
void rightboundary(TreeNode* root, vector<int>& res) {
    TreeNode* curr = root->right;
    vector<int> temp;

    while (curr) {
        if (!isleaf(curr)) temp.push_back(curr->value);

        if (curr->right) curr = curr->right;
        else curr = curr->left;
    }

    for (int i = temp.size() - 1; i >= 0; i--) {
        res.push_back(temp[i]);
    }
}

// Boundary traversal: root -> left boundary -> leaves -> right boundary (reversed)
vector<int> boundary(TreeNode* root) {
    vector<int> res;
    if (root == nullptr) return res;

    res.push_back(root->value);
    if (isleaf(root)) return res;  // single node tree

    leftboundary(root, res);
    addleaves(root, res);
    rightboundary(root, res);

    return res;
}

vector<int> topview(TreeNode* root) {
    vector<int> res;
    if (root == nullptr) return res;

    map<int, int> m;                 // hd -> first node value seen
    queue<pair<TreeNode*, int>> q;   // node, hd
    q.push({root, 0});

    while (!q.empty()) {
        TreeNode* curr = q.front().first;
        int hd = q.front().second;
        q.pop();

        if (m.find(hd) == m.end()) {
            m[hd] = curr->value;
        }

        if (curr->left) q.push({curr->left, hd - 1});
        if (curr->right) q.push({curr->right, hd + 1});
    }

    for (auto& p : m) {
        res.push_back(p.second);
    }
    return res;
}
};
