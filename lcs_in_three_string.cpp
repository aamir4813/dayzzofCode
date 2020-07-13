int count2( string a, string b, string c, int m, 
							int n, int o) 
{ 
	int dp[101][101][101]= {0}; 
	for (int i=0; i<=m; i++) 
	{ 
		for (int j=0; j<=n; j++) 
		{ 
			for (int k=0; k<=o; k++) 
			{ 
				if (i == 0 || j == 0||k==0) 
					dp[i][j][k] = 0; 

				else if (a[i-1] == b[j-1] && a[i-1]==c[k-1]) {
					dp[i][j][k] = dp[i-1][j-1][k-1] + 1; 
                }
				else
					dp[i][j][k] = max(max(dp[i-1][j][k], dp[i][j-1][k]), dp[i][j][k-1]); 
			} 
		} 
	} 

	return dp[m][n][o]; 
} 


int Solution::solve(string a, string b, string c) {
      int n = a.size() , m = b.size() , o = c.size();

    // dp.assign(101 , vector<vector<int>>(101 , vector<int>(101 , -1)));
    return count2(a , b , c , n , m , o);
}
