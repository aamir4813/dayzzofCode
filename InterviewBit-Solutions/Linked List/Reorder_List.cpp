/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 
void print(ListNode* head){
    
    ListNode* y = head;
    
     while(y){
        cout << y->val << " " ;
        y = y->next;
    }
    cout << endl;
    
}
 
ListNode* Solution::reorderList(ListNode* A) {
    
    ListNode* slow = A;
    ListNode* fast = A;
    if(A == NULL)
        return A;
    int cnt = 0 ;
    
    auto midHead = slow;
    while(slow and fast and fast->next and fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
        cnt++;
    }
    
    if(slow->next == NULL)
        return A;
    
    ListNode* curr = slow->next;
    slow->next = NULL;
    
    ListNode* head = NULL;
    while(curr){
        ListNode* temp = curr->next;
        curr->next = head;
        head = curr;
        curr = temp;
        
    }
    
    ListNode* temp = new ListNode(-1);
    ListNode* ans = temp;
    
    curr = midHead;
    
    // print(curr);
    // print(head);
    
    while(curr and head){
            temp->next = curr;
            temp = temp->next;
            curr = curr->next;
        
            temp->next = head;
            temp = temp->next;
            head = head->next;
    }
    
    if(curr){
        temp->next = curr;
        temp = temp->next;
    }
    
    temp->next = NULL;
    return ans->next;
}

