/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    ListNode* slow = A;
    ListNode* fast = A;
    
    bool trigger = false;
    while(fast and fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            break;
    }
    if(slow != fast)
        return NULL;
    
    fast = A;
    // cout << slow->val << " " << fast->val <<endl;
    while(slow != fast){
        // 1 2 3 4 5 6 7 3
        fast = fast->next;
        slow = slow->next;
    }
    
    return fast;
}

