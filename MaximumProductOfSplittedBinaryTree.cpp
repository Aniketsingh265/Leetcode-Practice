class Solution {
public:
    long long SUM = 0;
    long long maxP = 0;
    int tatalSum(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int left = tatalSum(root->left);
        int right = tatalSum(root->right);

        return root->val + left + right;
    }

    int subtreeSum(TreeNode* root){ // finding the sum of the subTree
        if(root == NULL){
            return 0;
        }

        int left = subtreeSum(root->left);
        int right = subtreeSum(root->right);

        long long S1 = root->val + left + right; // S1 is the sum of the subtree

        long long S2 = SUM - S1;

        maxP = max(maxP , S1*S2); // finding the maximum product
        return S1; // returns the subtree sum.
    }
    int maxProduct(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        SUM = tatalSum(root);

        subtreeSum(root);

        return maxP%1000000007;
    }
};
