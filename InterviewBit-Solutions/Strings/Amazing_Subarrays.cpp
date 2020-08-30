#define ll long long int
const int mod = 1e4+3;
int Solution::solve(string A) {
    int n = A.size();
    ll ans = 0 ;
    set<char> s;
    s.insert('a');
    s.insert('e');
    s.insert('i');
    s.insert('o');
    s.insert('u');
    for(int i = 0 ;i < n ; ++i){
        if(s.find(tolower(A[i])) != s.end()){
            ans += (n-i);
            ans %= mod;
        }
    }
    
    return ans;
}
