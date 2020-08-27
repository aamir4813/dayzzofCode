int Solution::solve(vector<int> &A) {
    int n = A.size();
    
    vector<int> mx(n+1);
    mx[n] = 0;
    
    for(int i = n-1 ; i >= 0 ; --i){
        mx[i] = max(mx[i+1] , A[i]);
    }
    
    set<int> s;
    
    s.insert(A[0]);
    int ans = 0;
    
    // becuase n-1 will not give triplet and above this because we're left with less tha
    // three numbers 
    for(int i = 1 ; i < n-1 ; ++i){
        
        auto x = s.lower_bound(A[i]);
        --x;
        // if(x)
        int a = *x;
        int b = A[i];
        int c = mx[i+1];
        // cout << a <<" " << b << " " << c << " - " << (a+b+c) << endl;;
        if(a < A[i] and A[i] < c)
            ans = max(ans , a+b+c);
        s.insert(A[i]);
    }
    
    if(ans <= 0)
        return 0;
    
    return ans;
}
