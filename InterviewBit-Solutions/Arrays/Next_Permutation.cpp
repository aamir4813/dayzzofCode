void next_permu(vector<int>&arr){
    int n = arr.size();
    
    int i = n-1;
    int j = n-2;
    /*
                1 2 5 4 3
    step 1:     1 3 5 4 2
    step 2:     1 3 4 5 2
        
    */
    
    while(j >= 0 ){
        if(arr[j] < arr[j+1])
            break;
        
        --j;
    }
    
    if(j == -1){
        reverse(arr.begin() , arr.end());
        return ;
    }
    
    while( i > j){
        if(arr[i] > arr[j])
            break;
        
        --i;
    }
    
    swap(arr[i] , arr[j]);
    ++j;
    
    i = n-1;
    while(j < i){
        swap(arr[i--] , arr[j++]);
    }
    
    
}

vector<int> Solution::nextPermutation(vector<int> &A) {
        
    // int n = A.size();
    
    next_permu(A);
    
    return A;
}
