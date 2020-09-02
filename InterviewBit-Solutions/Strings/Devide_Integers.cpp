#define ll long long int
int Solution::divide(int A, int B) {
    
    if(B == 0)
        return INT_MAX;
    if(A == 0)
        return 0;
    
    
    ll a = abs(1LL* A);
    ll b = abs(1LL* B);
    bool isNeg = false;
    if(A < 0 and B < 0){
        ;
    }
    else if(A < 0 or B < 0)
        isNeg = true;
    
    ll ans = 0 ;
    ll curr = 0;
    // cout << a << " " << b << endl;
    for(int i = 31 ; i >=0 ; --i){
        
        if(curr + (b << i) <= a){
            // cout << (b << i) << endl;
            curr += (b << i);
            ans |= (1LL << i);
        }
    }
    
    if(isNeg)
        return -1 * ans ;
    
    if(ans < INT_MIN or ans >= INT_MAX)
        return INT_MAX;
    return ans;
}
