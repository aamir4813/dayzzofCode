/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode* ans = new ListNode(-1);
    
    ListNode* curr = ans;
    while(A and B){
        
        if(A->val < B->val){
            curr->next = A;
            A = A->next;
        }
        else{
            curr->next = B;
            B = B->next;
        }
        curr = curr->next;
    }
    
    
    while(A){
        curr->next = A;
        curr = curr->next;
        A = A->next;
    }
    
    while(B){
        curr->next = B;
        curr = curr->next;
        B = B->next;
    }
    
    return ans->next;
}
