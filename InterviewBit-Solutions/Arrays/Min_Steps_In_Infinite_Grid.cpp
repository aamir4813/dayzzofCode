int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    
    int n = A.size();
    
    int ans = 0 ;
    int x = A[0] , y = B[0];
    for(int i = 1 ; i < n ;  ++i){
        
        x = abs(A[i] - x);
        y = abs(B[i] - y);
        
        ans += max(x  , y);
        x  = A[i];
        y  = B[i];
    }
    
    return ans;
}
