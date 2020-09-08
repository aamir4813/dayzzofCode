/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A) {
    int count_zero = 0;
    int count_one = 0;
    ListNode * curr = A;
    while(curr){
        if(curr->val == 0)
            count_zero++;
        else
            count_one++;
        
        curr = curr->next;
    }
    // ListNode* ans = A;
    curr = A;
    while(count_zero or count_one){
        
        if(count_zero){
            // ans->next = new ListNode();
            curr->val = 0;
            count_zero--;
        }
        else{
            curr->val = 1;
            count_one--;
        }
        curr = curr->next;
    }
    
    return A;
}

