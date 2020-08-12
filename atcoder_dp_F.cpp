#include<bits/stdc++.h>
using namespace std;
#define vi vector<int> 
#define vll vector<ll> 
#define vpll vector<pair<ll ,ll>>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define map map<ll ,ll>
#define umap unordered_map<ll , ll>
#define endl "\n"
#define set set<ll> 
#define setC set<char>
#define fast ios::sync_with_stdio(0); cin.tie(0);
#define fastcout ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define testcases int tt = 1 ; cin >> tt ; for(int i = 1 ; i <= tt ; ++i)
#define codejam cout << "Case #"<<i <<": "; 
#define FOR(i,a,n) for(int i = a ; i <= n ; ++i)
#define FORback(i,a,n) for(int i = n ; i >= a ; --i)
 
typedef long long int ll;
vvi dp ;

int doSome(string &a , string &b , int i , int j){

    int n = a.size();
    int m = b.size();

    if( i == n or j == m){
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    if(a[i] == b[j]){
        return dp[i][j] = 1 + doSome(a , b , i+1 , j+1);
    }
    else{
        return dp[i][j] = max(doSome(a ,b , i+1 , j ) , doSome(a , b , i, j+1));
    }
}

string findString(string&a , string &b ,int len){

    string ans = "";

    int i = 0 , j = 0 ;
    // len--;
    while(len){
        if(a[i] == b[j]){
            ans += b[j];
            ++i , ++j , --len;
        }
        else{
            if(dp[i][j+1] > dp[i+1][j]){
                ++j;
            }
            else{
                i++;
            }
        }
    }

    return ans;
}
 
void solv(){
    string a , b;
    cin >> a >>b;
    int n = a.size();
    int m = b.size();
 
    dp.assign(n+1 , vi(m+1 ,-1));
    // vvi dp(n+1 , vi(m+1 , 0 ));
 
    ll len = doSome(a , b , 0 , 0);
    // cout << len << endl;
    cout << findString(a , b , len) << endl ;
}
 
int main(){
    fast ;    
    // testcases{
        // codejam ;
        solv();
    // } 
}
 