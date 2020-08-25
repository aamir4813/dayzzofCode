map<int , string> mp;

string doMultiply(string &s ,  int num){
    
    string ans = "";
    int n = s.size();
    
    int carry =  0;
    for(int i = n-1 ; i >= 0 ; --i){
        
        int dig = (s[i] - '0');
    
        int number = dig * num + carry;
        int val = number % 10;
        carry = number / 10;
        
        ans = to_string(val) + ans ;
    }
    
    if(carry != 0)
        ans = to_string(carry) + ans ;
        
    return ans;
}


string Solution::solve(int A) {
    
    if(mp.find(A) != mp.end()){
        return mp[A];
    }
    
    // factorial(n);
    string s = "1";
    mp[1] = s;
    for(int i = 2 ; i <= 100 ; ++i){
        mp[i] = doMultiply(mp[i-1] , i);
    }
    
    return mp[A];
}
