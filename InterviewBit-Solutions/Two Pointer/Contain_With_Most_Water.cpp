int Solution::maxArea(vector<int> &A) {
    
    int n = A.size();
    int i = 0 , j = n-1;
    
    int ans = 0;
    while(i < j){
        int mx ;
        mx = min(A[i] , A[j]);
        if(A[i] > A[j]){
            ans = max(ans , mx * (j-i));
            --j;
        }
        else{
            ans = max(ans , mx * (j-i));
            ++i;
        }
    }
    
    return ans;
}
