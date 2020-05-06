class Solution {
    
public:
    
    int sumHelper(TreeNode *t, int &max_sum)
    {
        if(!t)
            return 0;
        
        int l=  max(0, sumHelper(t->left, max_sum));
        int r = max(0, sumHelper(t->right, max_sum));
                    
        max_sum = max(max_sum, l+r+t->val);
                    
        return max(l,r)+t->val;
    }
    
    int maxPathSum(TreeNode* root) {
        
        if(!root)
            return 0;
        
        int max_sum=INT_MIN;
    
        sumHelper(root, max_sum);
        
        return max_sum;

    }
};