string Solution::solve(string A, int B) {
    
    int n = A.size();
    
    string ans = "";
    for(int i = 0; i < n ; ++i){
        
        int sz = 1 ;
        
        while(i+1 < n and A[i] == A[i+1]){
            ++sz;
            
            if(sz == B)
                sz = 0;
            
            ++i;
        }
        
        if(sz >0 and sz != B){
            ans += string(sz , A[i]);
        }
    }
    
    return ans;
}
