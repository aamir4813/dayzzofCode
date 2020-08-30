bool isGood(vector<int>&arr , int target , int cutter){
    
    int sum = 0 ;
    
    for(auto x : arr){
        
        if( x > cutter){
            sum += x - cutter;
        }
        
        if(sum >= target)
            return 1;
    }
    
    return 0;
}

int Solution::solve(vector<int> &A, int B) {

    int n = A.size();
    int high = *max_element(A.begin() , A.end());
    
    int low = 1;
    
    int ans = 0 ;
    while(low <= high){
        
        int mid  = low + (high-low)/2;
        // cout << low << " " << mid <<" "<< high << " -  "<< isGood(A , B , mid)<<endl;
        if(isGood(A , B , mid)){
            ans = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    
    return ans;
}
