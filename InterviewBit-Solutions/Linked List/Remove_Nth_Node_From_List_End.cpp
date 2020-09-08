/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    
    ListNode* curr = A;
    
    int n = 0 ;
    while(curr){
        ++n;
        curr = curr->next;
    }
    
    if(n <= B){
        return A->next;
    }
    
    n-= B;
    curr= A;
    ListNode* prev = A;
    while(n){
        --n;
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    
    return A;
}

