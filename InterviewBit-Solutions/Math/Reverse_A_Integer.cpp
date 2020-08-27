int Solution::reverse(int A) {
    bool isNegative = false;
    
    if(A < 0){
        isNegative = true;
        A *= -1;
    }
    
    long num = 0 ;
    while(A){
        
        num = num*10 + A%10;
        A /= 10;
    }
    
    if(num < INT_MIN or num > INT_MAX)
        return 0;
    
    if(isNegative)
        num *= -1;
        
    
    return num ;
}
