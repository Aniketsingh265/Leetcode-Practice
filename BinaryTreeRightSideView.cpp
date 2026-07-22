class Solution {
public:
    vector<vector<int>>LevelOrderTraversal(TreeNode* root){
        vector<vector<int>>levels;
        if(root == NULL){
            return levels;
        }
        queue<TreeNode*>qu;
        qu.push(root);
        while(qu.size()!=0){
            vector<int>ans;
            int n = qu.size();
            for(int i =0;i<n;i++){
                TreeNode* curr = qu.front();
                qu.pop();
                ans.push_back(curr->val);
                if(curr->left != NULL){
                    qu.push(curr->left);
                }
                if(curr->right != NULL){
                    qu.push(curr->right);
                }
            }
            levels.push_back(ans);
        }
        return levels;
    }
    vector<int> rightSideView(TreeNode* root) {
        // using Level Order Traversal.
        vector<vector<int>>ans = LevelOrderTraversal(root);
        vector<int>res;
        for(int i =0 ;i<ans.size();i++){
            res.push_back(ans[i].back());
        }
        return res;
    }
};
