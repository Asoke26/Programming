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
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        
        int n = arr.size();
        if(root == nullptr || n==0) return false;
        if(arr[0] != root->val) return false;
              
        stack<pair<TreeNode* , vector<int> >> STACK;
        STACK.push(make_pair(root,arr));
        
        while(!STACK.empty())
        {
            pair<TreeNode* , vector<int> > TOP = STACK.top();
            STACK.pop();
            TreeNode* tempNode = TOP.first;
            vector<int> tempVec = TOP.second;
            if(tempNode == NULL || tempVec.size()==0) continue;
            if(tempNode->val == tempVec[0])
            {
                tempVec.erase(tempVec.begin()); // Erase first element
                if(tempVec.size()==0 && tempNode->right==NULL && tempNode->left==NULL)  return true;         
               
                STACK.push(make_pair(tempNode->left,tempVec));
                STACK.push(make_pair(tempNode->right,tempVec));
                
            }
            
        }     
        return false;    
    }
};