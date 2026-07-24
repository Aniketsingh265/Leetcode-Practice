class Solution {
public:
TreeNode* deleteHelper(TreeNode* root , unordered_set<int>&st , vector<TreeNode*>&result){
    if(root==NULL){
        return NULL;
    }

    root->left = deleteHelper(root->left , st , result);
    root->right = deleteHelper(root->right , st , result);

    if(st.find(root->val) != st.end()){
        if(root->left != NULL){
            result.push_back(root->left);
        }
        if(root->right != NULL){
            result.push_back(root->right);
        }
        return NULL;
    }
    else{
        return root;
    }
}
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& nums) {
        vector<TreeNode*>result;
        // to_delete is stored in the set , so that we can use the find function to firnd the element fornm the nums to delete.
        unordered_set<int>st;
        for(int i =0;i<nums.size();i++){
            st.insert(nums[i]);
        }

        deleteHelper(root , st , result);


        if(st.find(root->val) == st.end()){
            result.push_back(root);
        }
        return result;
    }
};
