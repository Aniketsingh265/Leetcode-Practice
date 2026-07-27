class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // Moriss Inorder Traversal 
        vector<int>ans;

        TreeNode* curr = root;

        while(curr!=NULL){
            if(curr->left == NULL){
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else{
                //find the Inorder Predecessor (IP)
                TreeNode* IP = curr->left;
                while(IP->right != NULL and IP->right != curr){ // IP->right != curr => to check that thread did not exits.
                    IP = IP->right;
                }
                if(IP->right == NULL){
                    IP->right = curr; // create the thread.
                    curr = curr->left;
                }
                else{
                    IP->right = NULL; // delete the thre
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};
