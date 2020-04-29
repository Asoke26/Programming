// Problem Link : https://leetcode.com/problems/binary-tree-maximum-path-sum/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root){
        
        if(root == NULL) return 0;
        
        int left_tree_h = maxheightsum(root->left);
        int right_tree_h = maxheightsum(root->right);
        
        int left_diameter = maxPathSum(root->left);
        int right_diameter = maxPathSum(root->right);
        
        
       
        if(left_diameter <=0 && right_diameter<=0) {
            if(left_diameter == 0 && right_diameter==0) return root->val;
            
            int max_val;
            if(left_diameter < 0 && right_diameter<0) max_val = max(left_diameter,right_diameter);
            else max_val = (left_diameter<0?left_diameter:right_diameter);
            return max(root->val,max(root->val + max_val,max_val));
            
        }
        
        
        int tree_diameter = max(root->val,max(root->val + left_tree_h + right_tree_h,max(max(left_diameter,right_diameter),max(root->val + left_tree_h,root->val + right_tree_h))));
        
        return tree_diameter;
    }
    
    
    int maxheightsum(TreeNode* root)
    {
        if(root == NULL) return 0;
        
        int left_h = maxheightsum(root->left);
        int right_h = maxheightsum(root->right);
        int root_h = max(root->val,root->val + max(left_h,right_h));
        
        return root_h;
    }
};