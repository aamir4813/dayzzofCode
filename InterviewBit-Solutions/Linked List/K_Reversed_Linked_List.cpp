/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A, int B) {
    
     if(B == 1)
        return A;
    
    int c = 1;
    ListNode *temp = A, *prev = A, *curr = A->next, *next, *head = NULL, *temp2 = NULL;
    
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        c++;
        if(c % B == 0){
            head = !head ? prev : head;
            if(temp2)
                temp2->next = prev;
            temp2 = temp;
            temp = curr;
        }
    }
    
    temp2->next = NULL;
    
    return head;
}

