int Solution::solve(vector<vector<int> > &A, int B) {

    int n = A.size();
    for(int i = 0 ; i <n ; ++i ){
        for(int j = 1 ; j < n ; ++j){
            A[i][j] += A[i][j-1];
        }
    }
    
    for(int i = 0 ; i < n ; ++i){
        for(int j = 1 ; j < n ; ++j){
            A[j][i] += A[j-1][i];
        }
    }
    
    
    int ans = INT_MIN;
    for(int i = B-1 ; i < n ; ++i){
        for(int j = B-1 ; j < n ; ++j){
            int curr_sum = A[i][j];
            int cnt = 0 ;
            if(i != B-1){
                cnt++;
                curr_sum -= A[i-B][j];
            }
            if(j != B-1){
                cnt++;
                curr_sum -= A[i][j-B];
            }
            
            if(cnt == 2){
                curr_sum += A[i-B][j-B];
            }
            
            ans = max(curr_sum , ans);
        }
    }
    
    return ans;
}
