int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    
    int n = A.size();
    int m = B.size();
    int o = C.size();
    
    int i = 0 , j = 0 , k =  0;
    int ans = INT_MAX;
    
    while(i < n and j < m and k < o){
        int val = max({abs(A[i] - B[j]) , abs(B[j] - C[k]) , abs(A[i] - C[k])});
        
        ans = min(ans , val);
        
        int mn = min({A[i] , B[j] , C[k]});
        
        if(mn == A[i]){
            ++i;   
        }
        else if(mn == B[j]){
            ++j;
        }
        else if(mn == C[k]){
            ++k;
        }
        
    }
    
    return ans;
}
