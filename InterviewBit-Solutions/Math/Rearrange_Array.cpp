void Solution::arrange(vector<int> &A) {

    // Actually i have already gone through this question
    // At first sight it was very tricky
    int n = A.size();
    
    for(auto &x : A){
        int y = A[x];
        
        int val = n * (y % n) + x;
        
        x = val;
    }
    
    for(auto &x : A){
        x /= n;
    }
    
}
