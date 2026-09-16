class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        
        if(root == NULL)
            return -1;

        queue<TreeNode*> q;
        q.push(root);

        vector<long long> ans;

        while(q.size()!=0) {

            int n = q.size();
            long long sum = 0;

            for(int i = 0; i < n; i++) {

                TreeNode* top = q.front();
                q.pop();

                sum += top->val;

                if(top->left != NULL)
                    q.push(top->left);

                if(top->right != NULL)
                    q.push(top->right);
            }
            ans.push_back(sum);
        }

        if(k>ans.size()){
            return -1;
        }
        sort(ans.rbegin(), ans.rend());//sorted in descending order 

        return ans[k - 1];
    }
};