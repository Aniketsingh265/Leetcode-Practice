class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        // using BFS , we will use queue.
        queue<TreeNode*>qu;
        qu.push(root);
        bool past = false;
        while (qu.size() != 0) {
            TreeNode* curr = qu.front();
            qu.pop();
            if (curr == NULL) {
                past = true;
            } else {
                if (past == true) {
                    return false;
                }
                qu.push(curr->left);
                qu.push(curr->right);
            }
        }
        return true;
    }
};
