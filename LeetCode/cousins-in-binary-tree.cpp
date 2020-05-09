Problem Link : https://leetcode.com/problems/cousins-in-binary-tree/


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
    bool isCousins(TreeNode* root, int x, int y) {
        // Base Conditions
        if(root->val == x || root->val == y) return false;
        
        // Intializing variables
        int p1=-1,p2=-1; // p1 & p2: Parent for both x & y respectively
        int h1=0,h2=0; // Height for x & y respectively
        
        int xh = getDepth(root,x,p1,h1);
        int yh = getDepth(root,y,p2,h2);
        
        if(p1!=p2 && xh==yh)return true;
        
        return false;
    }
    

    int getDepth(TreeNode *root, int val,int &parent, int depth) 
    { 
       // This function will update the parent and return the height
        if(root == NULL) {
            return 0;
        } // Baseline condition
        
        if(root->val == val) {
            return depth;
        } // If root value matches with desired value initiate return
        
        parent = root->val;
        int left = getDepth(root->left,val,parent,depth+1);
        if(left) return left;       
        
        parent = root->val;
        int right = getDepth(root->right,val,parent,depth+1);
        if(right) return right;
        
        return 0;
    }
        
};