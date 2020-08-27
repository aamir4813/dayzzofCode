const int mod = 1e9+7;
vector<vector<int>> dp;

int doSome(int i , int j , int A , int B){
    
    if(i > A || j > B)
        return 0;
    
    if(i == A  and j == B){
        return 1;
    }
    if(dp[i][j] != -1)
        return dp[i][j];
    
    long long int ans = 0 ;
    
    ans += doSome(i+1 , j , A , B);
    ans %= mod;
    ans += doSome(i , j+1 , A , B);
    
    ans %= mod;
    
    return dp[i][j] = ans;
}

// int doSome()
int Solution::uniquePaths(int A, int B) {

    dp.assign(A+1 , vector<int>(B+1 , -1));
    
    return doSome(0 , 0 , A-1 , B-1);
}
// Actually i have to apply maths here but i really did't get that at the time of submission

