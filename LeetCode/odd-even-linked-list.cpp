//Problem Link : https://leetcode.com/problems/odd-even-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        
        if(head == NULL) return NULL;
        if(head->next == NULL) return head;
        if(head->next->next == NULL) return head;
        
        ListNode* odd;
        ListNode* even;
        ListNode* evenH;
        ListNode* oddH;
        int c=1;
        
       
        odd = head;
        oddH = head;
        head = head->next;
 
        even = head;
        evenH = head;
        head = head->next;
        
        
        while(head!=NULL)
        {
            
            cout<<head->val<<endl;
            if(c%2)
            {
                 odd->next = head;
                 odd = odd->next;
            }
            else {
                even->next = head;
                even = even->next;
            }
            
            c++;
            head=head->next;
            
        
        }
        odd->next = evenH;
        even->next = NULL;       
        
        
        
        return oddH;
    }
};