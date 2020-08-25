int Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    
    int slow = A[0];
    int fast = A[0];
    
    do{
        slow = A[slow];
        fast = A[A[fast]];
    }while(slow != fast);
    
    slow = A[0];
    
    while(slow != fast){
        slow = A[slow];
        fast = A[fast];
    }
    
    return fast;
    
    /*
    we can also do using array as hashmap itself becuase elements are in ranged 1 to n
    and mark the index of that value negative one...
    and if we get negative once again then this might lead to dublicated
    but readonly... 
    */
    
}
