class Solution {
public:
// we will treverse the tree like Root Right Left , like we will check if the level will be equal to the vector's size then we willl push it in the array.
    void solve(TreeNode* root , int level  , vector<int>&ans){
        if(root == NULL){
            return;
        }
        if(level == ans.size()){
            ans.push_back(root->val);
        }
        solve(root->right , level+1 , ans);
        solve(root->left , level +1 , ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        solve(root , 0 , ans);
        return ans;
    }
};
