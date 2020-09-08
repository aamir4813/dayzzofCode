/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 void print(ListNode* curr){
     ListNode* temp = curr;
     
     while(temp){
         cout << temp->val <<" ";
         temp = temp->next;
     }
     cout << endl;
 }
ListNode* Solution::solve(ListNode* A) {
    
    int n = 1;
    
    ListNode* curr = A;
    ListNode* B = A;
    ListNode* even = new ListNode(-1);
    ListNode* temp = even;
    
    ListNode* even_main = even;
    while(curr){
        
        if(n % 2 == 0 ){
            even->next = new ListNode(curr->val);
            even = even->next;
        }
        ++n;
        curr= curr->next;
    }
    even = even_main->next;
    // print(even);
    // print(A);
    
    ListNode* head = NULL;
    while(even){
        ListNode* temp = even->next;
        even->next = head;
        head = even;
        even = temp;
    }
    
    n = 1;
    curr = B;
    // print(head);
    // print(B);
    while(curr){
        
        if(n %2  == 0){
            
            curr->val = head->val;
            head= head->next;
        }
        ++n;
        curr = curr->next ;
    }
    
    return A;
}

