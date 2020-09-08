/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    
    ListNode* curr = A;
    
    ListNode* temp = new ListNode(-1);
    ListNode* ans = temp;
    while(curr){
        
        int cnt = 0;
        while(curr->next and curr->next->val == curr->val){
            cnt++;
            curr = curr->next;
        }
        
        if(cnt == 0){
            temp->next = new ListNode(curr->val);
            temp = temp->next;
        }
        curr= curr->next;
    }
    
    return ans->next;
}

