string Solution::longestCommonPrefix(vector<string> &A) {
    
    string mn = A[0];
    int n = A.size();
    for(int i = 1 ; i < n ; ++i){
        
        if(mn.size() > A[i].size()){
            mn = A[i];
        }
        else if(mn.size() == A[i].size()){
            mn = min(mn , A[i]);
        }
    }
    
    string ans ="";
    n = mn.size();
    
    for(int i = 0 ;i < n ; ++i){
        for(auto x : A){
            if(mn[i] != x[i])
                return ans;
        }
        ans += mn[i];
    }
    
    return ans;
}
