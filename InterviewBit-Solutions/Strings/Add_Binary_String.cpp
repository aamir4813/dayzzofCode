string Solution::addBinary(string A, string B) {
    int n = A.size();
    int m = B.size();
    
    int i = n-1;
    int j = m-1;
    
    int carry = 0 ;
    string ans = "";
    for(; i >=0 and j >= 0 ; --i , --j ){
        int dig = (A[i] - '0') + (B[j] - '0') + carry;
        carry = dig / 2;
        dig %= 2;
        
        ans = to_string(dig) + ans;
    }
    
    
    while(i >= 0){
        int dig = (A[i] - '0') + carry;
        carry = dig / 2;
        dig %= 2;
        ans = to_string(dig) + ans;
        
        --i;
    }
    
    while(j >= 0){
        int dig = (B[j] - '0') + carry;
        carry = dig / 2;
        dig %= 2;
        ans = to_string(dig) + ans;
        --j;
    }
    
    
    if(carry)
        ans = to_string(carry) + ans;
        
    return ans;
}
