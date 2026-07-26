class Solution {
public:
    vector<vector<int>>result;

    void solve(TreeNode* root , int sum , int &targetSum , vector<int>temp){
        if(root==NULL){
            return;
        }

        sum+=root->val;
        temp.push_back(root->val);

        if(root->left == NULL and root->right == NULL){
            if(sum == targetSum){
                result.push_back(temp);
            }
            return;
        }

        solve(root->left , sum , targetSum , temp);
        solve(root->right , sum ,targetSum , temp);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        vector<int>temp;
        solve(root ,sum , targetSum ,temp);
        return result;
    }
};
