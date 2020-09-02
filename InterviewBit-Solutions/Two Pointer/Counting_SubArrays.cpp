#define ll long long int 
int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    
    int i = 0 , j = i;
    
    ll ans = 0 ;
    ll curr_sum = 0;
    while(j < n){
       
        curr_sum += A[j];
       
        while(curr_sum >= B)
            curr_sum -= A[i++];
        
        ans += (j-i+1);
        
        ++j;
    }
    
    // 2 3 4 5 6 7 and B = 9
    /*
    */
    
    // if(curr_sum == 0)
    
    return ans;
}
