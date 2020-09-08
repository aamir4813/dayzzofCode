/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A, int B) {
    
     vector<int> arr;
     
     ListNode* curr = A;
     
     while(curr){
         arr.push_back(curr->val);
         curr = curr->next ;
     }
     
    //  for(auto x : arr){
    //      cout << x << " ";
    //  }
    //  cout << endl;
     
    curr = A;
    int i = 0 ;
    while(curr){
        if((i / B) % 2 == 0){
            // cout << i << " ";
            int n = i / B;
            int index  = (n+(i/B)+1)*B - i - 1 ;
            curr->val = arr[index];
        }
        curr=  curr->next;
        ++i;
    }
     
    return A;
}

