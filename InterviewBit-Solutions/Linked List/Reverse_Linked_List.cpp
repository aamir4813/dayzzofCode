/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A) {
    stack<int> s;
    ListNode* curr = A;
    
    while(curr){
        s.push(curr->val);
        curr = curr->next;
    }
    
    curr = A;
    while(!s.empty()){
        curr->val = s.top();
        s.pop();
        curr = curr->next;
    }
    
    return A;
}

