int Solution::titleToNumber(string A) {
    
    int n = A.size();
    
    int ans = 0 ;
    int l = 0;
    for(int i = n-1 ; i >= 0 ; --i){
        int num = A[i] - 64 ;
        ans = ans + num*pow(26 , l);
        ++l;
    }
    
    return ans ;
}

