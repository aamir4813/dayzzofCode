/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 void print(ListNode* curr){
     auto temp = curr;
     
     while(temp){
         cout << temp->val<<" ";
         temp = temp->next;
     }
     cout << endl;
 }
ListNode* Solution::rotateRight(ListNode* A, int B) {
    int n  = 0 ;
    ListNode* curr = A;
    
    if(B == 0)
        return A;
    
    while(curr){
        ++n;
        curr = curr->next;
    }
    if(n == 1)
        return A;
    
    B = (B % n);
    
    if(B == 0)
        return A;
    
    n = n -  B - 1;
    
    curr = A;
    ListNode* head = curr;
    while(n--){
        curr = curr->next;
    }
    auto temp = curr->next;
    curr->next = NULL;
    // print(head);
    curr = temp;
    // print(curr);
    while(curr->next){
        curr = curr->next;
    }
    
    curr->next = head;
    
    return temp;
}

