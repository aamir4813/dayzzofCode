int Solution::findMinXor(vector<int> &A) {
    sort(A.begin() , A.end());
    
    int ans = 1e9 +1 ;
    int n = A.size();
    for(int i = 0 ; i < n-1 ; ++i){
        int val = A[i] ^ A[i+1];
        ans = min(ans , val);
    }
    
    return ans;
}
