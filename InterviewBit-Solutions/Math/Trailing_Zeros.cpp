int Solution::trailingZeroes(int A) {
    
    if(A <= 4)
        return 0;
    int n = (double(log(A))) / (double)(log(5));
    
    int pw = 5;
    int ans = 0 ;
    for(int i = 1 ; i <= n ; ++i){
        ans += A / pw;
        pw *= 5;
    }
    
    return ans;
}
