int Solution::removeDuplicates(vector<int> &A) {
    
    int n = A.size();
    
    if(n == 2)
        return n;
    int i = 1 , j = 1;
    // this k for atmost 2 thing
    int k = 2;
    
    int cnt = 1 ;
    while(i < n){
        
        if(A[i] == A[i-1]){
            cnt++;
        }
        else{
            cnt = 1;
        }
        if(cnt <= 2){
            A[j++] = A[i];
        }
        ++i;
    }
    return j;
}
