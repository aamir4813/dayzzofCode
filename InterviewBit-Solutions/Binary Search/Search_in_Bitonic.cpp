int pivot(vector<int> & A ){
    
    int l = 0, r = A.size()-1 ;
    
    while(l<r){
        
        int mid = l + (r-l)/2;
        
        if(( mid==0 && A[mid]> A[mid+1] )|| (mid == A.size()-1 && A[mid]<A[mid-1])||(A[mid]>A[mid-1]&&A[mid]<A[mid+1]) )
            return mid;
        else if(A[mid]<A[mid-1]){
            r = mid-1;
        }    
        else{
            l = mid;
        }
    }
    return l;
}

int binary_search(vector<int>&arr , int low , int high , int target){
    int n = arr.size();

    while(low <= high){
        int mid = (low+high)/2;
        if( arr[mid] == target)
            return mid;
        else if(arr[mid] < target){
            low = mid+1;
        }
        else
            high = mid-1;
    }
    
    return -1;
}

int binary_search2(vector<int>&arr , int low , int high , int target){
    int n = arr.size();

    while(low <= high){
        int mid = (low+high)/2;
        if( arr[mid] == target)
            return mid;
        else if(arr[mid] > target){
            low = mid+1;
        }
        else
            high = mid-1;
    }
    
    return -1;
}


int Solution::solve(vector<int> &A, int B) {
    
    int index = pivot(A);
    // cout << index << endl;
    int val = binary_search(A , 0 , index , B);
    
    if(val != -1)
        return val;
    
    int val2 = binary_search2(A , index+1 , A.size()-1 , B);
    
    
    return val2;
    
}
