class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        if(root == p or  root == q){
            return root;
        }
        //left side leftNode nikal lo 
        TreeNode* leftN = lowestCommonAncestor(root->left , p , q);
        //right side se rightNode nikal Lo.
        TreeNode* rightN = lowestCommonAncestor(root->right , p, q);

        if(leftN != NULL and rightN != NULL){
            return root;
        }

        if(leftN == NULL){
            return rightN;
        }
        return leftN;
    }
};
