vector<int> Solution::solve(vector<int> &A) {
    int n = A.size();
    
    vector<int> right(n) , ans;
    
    if(n <=1)
        return A;
    right[n-1] = A[n-1];
    
    for(int i = n-2 ; i >=0 ; --i){
        right[i] = max(A[i] , right[i+1]);
    }
    
    for(int i = 0 ; i < n-1 ; ++i){
        if(A[i] > right[i+1])
            ans.push_back(A[i]);
    }
    
    ans.push_back(A[n-1]);
    
    return ans;
}
