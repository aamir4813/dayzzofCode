#define ll long long int
int fastPower(ll x , ll n , ll m){
    
    if(n == 0)
        return 1 % m;
    ll ans = 1;
    
    ll val = x;
    while(n){
        
        if(n & 1){
            ans = (ans * (m + x)%m)%m;
            
        }
        x = (1LL *x*x)%m;
        n >>= 1;
    }
    
    return (m + ans)%m;
}

int Solution::pow(int x, int n, int d) {

    return fastPower( x , n , d);
}
