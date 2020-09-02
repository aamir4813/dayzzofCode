int Solution::threeSumClosest(vector<int> &A, int B) {
    
    int n = A.size();
    sort(A.begin() , A.end());
    
    int ans = 0;
    int mn = INT_MAX;
    for(int i =  0 ; i < n-2 ; ++i){
        int s = A[i] ;
        // map<int , int > mp;
        int j = i+1 , k = n-1;
        
        while( j < k){
            int sum =A[i] + A[j] + A[k];
            if( abs(B - sum) < mn){
                mn = abs(B - sum);
                ans = sum;
            }
            
            if(sum < B){
                ++j;
            }
            else if(sum > B){
                --k;
            }
            else{
                return B;
            }
        }
    }
    return ans;
}
