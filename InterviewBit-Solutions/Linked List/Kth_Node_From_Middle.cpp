/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::solve(ListNode* A, int B) {
    ListNode* slow = A;
    ListNode* fast = A;
    
    int cnt = 0 ;
    while(fast and fast->next){
        cnt++;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    if(cnt < B)
        return -1;
        
    ListNode* curr = A;
    
    cnt -= B;
    while(cnt){
        curr= curr->next;
        --cnt;
    }
    
    return curr->val;
}

