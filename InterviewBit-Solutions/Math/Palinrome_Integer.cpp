int Solution::isPalindrome(int A) {
    
    int ans = 0 ;
    
    int temp = A;
    if(A < 0)
        return 0;
    while(temp){
        
        int m = temp % 10;
        
        ans = ans*10 + m;
        temp /= 10;
    }
    
    return ans == A ;
}
