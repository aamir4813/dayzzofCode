int Solution::solve(vector<int> &A) {
    map<int , int> mp;
    
    for(auto x : A)
        mp[x]++;
        
    int ans = 0 ;
    
    int y = 0  ;
    
    for(auto it = mp.rbegin() ;  it != mp.rend();  ++it){
        int num = it->first ;
        int val = it->second;
        
        if(y == num)
            ans++;
        
        y += val;
    }
    
    return (ans == 0 ? -1 : ans);
}
