class Solution {
public:
    int countLeftNodes(TreeNode* root){
        int count = 0;

        while(root != NULL){
            count++;
            root = root->left;
        }
        return count;
    }
    int countRightNodes(TreeNode* root){
        int count = 0;

        while(root != NULL){
            count++;
            root = root->right;
        }
        return count;
    }
    int countNodes(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        int lh = countLeftNodes(root);
        int rh = countRightNodes(root);
    	// if the tree is perfect binary tree then formula is used to find the total number of nodes in the binary tree(pow(2,height)-1).
        if(lh == rh){
            return pow(2,lh)-1;
        }

        return countNodes(root->left) + countNodes(root->right) + 1;

    }
};
