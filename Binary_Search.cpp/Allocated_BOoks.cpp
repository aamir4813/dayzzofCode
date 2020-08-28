#define ll long long int

bool isValidBook(vector<int> & A , int students , int pages){
    
    int n = A.size();
    int curr_sum = 0;
    for(int i = 0 ; i < n ; ++i){
        curr_sum += A[i];
        if(A[i] > pages) return false;
        if(curr_sum > pages){
            curr_sum = A[i];
            students--;
        }
        // else if(curr_sum == pages){
        //      curr_sum = 0 ;
        //      students--;
        // }
        if(students == 0)
            return false;
    }
    return true;
}
int Solution::books(vector<int> &A, int B) {
    
      
    int n = A.size();
    int low = *max_element(A.begin() , A.end());
    if(B > n)
        return -1;
    if( B == n)
        return low;
    
    ll high = 0 ;
    
    for(auto x : A)
        high +=x ;
    ll ans  = -1;
    while(low <= high){
        int mid = low + (high -low)/2;
        
        if(isValidBook(A , B , mid)){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
    
}
