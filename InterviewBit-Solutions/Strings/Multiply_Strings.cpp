string addTwoString(string &A  , string &B){
    int n = A.size();
    int m = B.size();
    if(n == 0)
        return B;
        
    if(m == 0)
        return A;
    int i = n-1;
    int j = m-1;
    
    int carry = 0 ;
    string ans = "";
    for(; i >=0 and j >= 0 ; --i , --j ){
        int dig = (A[i] - '0') + (B[j] - '0') + carry;
        carry = dig / 10;
        dig %= 10;
        
        ans = to_string(dig) + ans;
    }
    
    
    while(i >= 0){
        int dig = (A[i] - '0') + carry;
        carry = dig / 10;
        dig %= 10;
        ans = to_string(dig) + ans;
        
        --i;
    }
    
    while(j >= 0){
        int dig = (B[j] - '0') + carry;
        carry = dig / 10;
        dig %= 10;
        ans = to_string(dig) + ans;
        --j;
    }
    
    
    if(carry)
        ans = to_string(carry) + ans;
        
    return ans;
}

string Solution::multiply(string A, string B) {
    
    int n = A.size();
    int m = B.size();
    
    string ans = "" , shift = "";
    
    for(int i = m-1 ; i >=0  ; --i){
        int carry = 0;
        string temp = "";
        for(int j = n-1 ; j >=0 ; --j){
            int dig = (A[j] - '0') * (B[i] - '0') + carry;
            
            carry = dig /10;
            dig %= 10;
            temp = to_string(dig) + temp;
        }
        if(carry){
            temp = to_string(carry) + temp;
        }
        
        temp += shift;
        shift += "0";
        ans = addTwoString(ans , temp);
    }
    int sz = ans.size();
    
    int i = 0;
    for( ; i < sz ; ++i){
        if(ans[i] != '0')
            break;
    }
    
    if(ans == string(sz , '0'))
        return "0";
    return ans.substr(i);
}
