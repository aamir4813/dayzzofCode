/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    
    ListNode* curr = A;
    
    int n = 0 ;
    set<ListNode* > s;
    while(curr){
        n++;
        s.insert(curr);
        curr = curr->next;
    }
    
    curr= B;
    while(curr){
        
        if(s.find(curr) != s.end())
            return curr ;
        
        curr = curr->next;
    }
    
    
    return NULL;
    
}
