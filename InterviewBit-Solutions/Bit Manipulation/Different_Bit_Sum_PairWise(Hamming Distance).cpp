#define ll long long int
const ll mod = 1e9+7;

int Solution::cntBits(vector<int> &A) {
    
    // Hamming Distance You come here again.... xD
    
    ll ans = 0 ;
    int n = A.size();
    for(int i = 31 ; i >= 0 ; --i){
        ll count_one = 0 ;
        for(auto x : A){
            bool bit = (1 << i) & x;
            
            if(bit)
                count_one++;
        }
        
        ans += (1LL*count_one) * (n-count_one) ;
        ans %= mod;
    }
    
    return (ans*2) % mod;
}
