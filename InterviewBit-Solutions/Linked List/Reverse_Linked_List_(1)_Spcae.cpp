/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A) {
    
    ListNode* endNode = NULL;
    ListNode* curr = A;
    
    while(curr){
        ListNode* node = curr;
        curr = curr->next;
        node->next = endNode;
        endNode = node;
    }
    
    return endNode;;
}
