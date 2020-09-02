int Solution::solve(vector<int> &A) {
  int res=0;
  int n = A.size();
    for(int i=0;i<n;i++)
        {
            int cnt = (i+1)*(n-i);
            if(cnt %2!=0)
                res ^=A[i];
        }
    return res;
}
