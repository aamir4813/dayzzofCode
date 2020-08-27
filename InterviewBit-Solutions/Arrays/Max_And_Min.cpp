int Solution::solve(vector<int> &A) {
    
    int mx = *max_element(A.begin() , A.end());
    int mn = *min_element(A.begin() , A.end());
    
    return mx+mn ;
}
//Will Update it as soon as possible
