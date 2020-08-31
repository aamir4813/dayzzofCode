int Solution::singleNumber(const vector<int> &A) {
    
    
    int ans = 0 ;
    for(int i = 31 ; i >= 0 ; --i){
        int count = 0 ;
        for(auto x : A){
            bool bit = (1 << i) & x;
            
            if(bit)
                count++;
        }
        
        if(count % 3 != 0)
            ans |= (1 << i);
    }
    
    return ans;
}
