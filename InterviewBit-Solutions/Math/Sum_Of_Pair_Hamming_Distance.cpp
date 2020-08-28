#define ll long long int
const int mod = 1e9+7;
int Solution::hammingDistance(const vector<int> &A) {

    int n = A.size();
    ll ans = 0 ;
    for(int i = 0 ; i <= 31 ; ++i){
        
        ll count1 = 0;
        for( int x : A){
            bool val = (1 << i) & x ;
        if(val) count1++; 
        }
        
        ans += ((n-count1) * 1LL*count1)%mod;
    }
    
    return (ans*2LL)%mod;
}
