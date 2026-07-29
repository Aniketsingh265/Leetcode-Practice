class Solution {
public: 
    // Optimal Approach 
    // in this method we are finding the maximum value and minimum val  and cheching there difference at root  , for both left side and the right side and at last finding the maximum  diff between the left and right side.
    int FindMaxDiff(TreeNode* root , int minV ,int maxV){
        if(root == NULL){
            return abs(minV-maxV);
        }
        minV = min(minV , root->val);
        maxV = max(maxV , root->val);

        int left = FindMaxDiff(root->left , minV , maxV);
        int right = FindMaxDiff(root->right , minV ,maxV);

        return max(left , right);
        
    }
    int maxAncestorDiff(TreeNode* root) {
        int maxDiff = FindMaxDiff(root , root->val , root->val);

        return maxDiff;
    }
};
