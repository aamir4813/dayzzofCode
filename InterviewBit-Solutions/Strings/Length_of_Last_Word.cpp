int Solution::lengthOfLastWord(const string A) {
    
    int len = 0 ;
    int n = A.size();
    int ans = 0;
    for( int i = 0 ; i < n ; ++i){
       if(A[i] == ' '){
          if(len)
            ans = len;
           len = 0;
       } 
       else
            len++;
    }
    
    if(len)
        ans = len;
    
    return ans;
}
