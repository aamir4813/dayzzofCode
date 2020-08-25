int Solution::maxSubArray(const vector<int> &A) {
    
    int max_sum = INT_MIN ;
    int curr_sum =  0;
    
    for(auto x : A){
        curr_sum += x;
        
        max_sum = max(max_sum , curr_sum);
        if(curr_sum < 0){
            // max_sum = max(max_sum , curr_sum);
            curr_sum = 0;
        }
        
    }
    
    return max_sum ;
}
