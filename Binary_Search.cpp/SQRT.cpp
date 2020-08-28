#define ll long long int
int Solution::sqrt(int A) {
    ll low = 1 , high = (A /2) +1 ;
    
    int ans = 1;
    if(A <= 1)
        return A;
    
    
        
    while(low <= high){
        ll mid = (low + (high-low+1)/2);
        
       if(mid*mid > A)
            high = mid - 1;
        else
            low = mid;
    }
    
    return low;
    
}
