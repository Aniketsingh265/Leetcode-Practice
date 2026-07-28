class Solution {
public:
    string rootLeaf(TreeNode* root, string& s) {

        if (root == NULL) {
            return s;
        }

        if (root->left == NULL and root->right == NULL) {
            s += root->val;
            return s;
        }
        // check the left side
        rootLeaf(root->left, s);
        // check right side
        rootLeaf(root->right, s);

        return s;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string s1 = "";
        string s2 = "";
        rootLeaf(root1, s1);
        rootLeaf(root2, s2);

        if (s1 == s2) {
            return true;
        }
        return false;
    }
};
