int Solution::romanToInt(string A) {
    map<char , int> roman;
    roman['I']  = 1;
    roman['V']  = 5;
    roman['X']  = 10;
    roman['L']  = 50;
    roman['C']  = 100;
    roman['D']  = 500;
    roman['M']  = 1000;
    
    int n = A.size();
    
    int ans = roman[A[n-1]];
    for(int i = n-2 ; i >= 0 ; --i){
        if(roman[A[i]] < roman[A[i+1]]){
            ans -= roman[A[i]];
        }
        else{
            ans += roman[A[i]];
        }
        // cout << ans << " ";
    }
    
    return ans;
}
