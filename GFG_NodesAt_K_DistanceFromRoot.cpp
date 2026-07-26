class Solution {
  public:
    vector<int> kdistance(Node *root, int k) {
        vector<int>ans;
        
        if(root == NULL){
            return ans;
        }
        
        int cnt =0;
        
        queue<Node*>qu;
        qu.push(root);
        
        while(qu.size()!=0){
            int n = qu.size();
            
            if(cnt == k){
                while(qu.size()!=0){
                    Node* curr = qu.front();
                    ans.push_back(curr->data);
                    qu.pop();
                }
                return ans;
            }
            else{
                while(n!=0){
                    Node* curr = qu.front();
                    qu.pop();
                    
                    if(curr->left!=NULL){
                        qu.push(curr->left);
                    }
                    
                    if(curr->right!=NULL){
                        qu.push(curr->right);
                    }
                    n--;
                }
                cnt++;
            }
        }
        return ans;
    }
};
