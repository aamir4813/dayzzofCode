int Solution::solve(vector<int> &A) {
    
    int n = A.size();
    
    if(n == 1)
        return 1;
    int count = 0 ;
    int odd_size , even_size;
    
    even_size = n/2;
    odd_size = even_size;
    if(n&1){
        odd_size++;
    }
    
    vector<int> odd_prefix(odd_size , 0) , even_prefix(even_size ,0);
    
    odd_prefix[0] = A[0];
    even_prefix[0] = A[1];
    for(int i = 2 ; i < n ; ++i){
        int index = i/2;
        if(i&1){
            even_prefix[index] = even_prefix[index-1] + A[i];
        }
        else{
            odd_prefix[index] = odd_prefix[index-1] + A[i];
        }
    }
        
    int curr_even , curr_odd ;
    for(int i = 0 ; i < 2*even_size ; ++i){
        int index = i/2;
        if(i & 1){
            if(i == 1){
                curr_odd = odd_prefix[index] + (even_prefix[even_size-1] - even_prefix[index]);
                curr_even = (odd_prefix[odd_size-1] - odd_prefix[index]);
            }
            else{
                curr_odd = odd_prefix[index] + (even_prefix[even_size-1] - even_prefix[index]);
                curr_even = even_prefix[index-1] + (odd_prefix[odd_size-1] - odd_prefix[index]);
            }
        }
        else{
            if(i == 0){
                curr_odd = even_prefix[even_size-1] ;
                curr_even = (odd_prefix[odd_size-1] - odd_prefix[index]);
            }
            else{
                curr_odd = odd_prefix[index-1] + (even_prefix[even_size-1] - even_prefix[index-1]);
                curr_even = even_prefix[index-1] + (odd_prefix[odd_size-1] - odd_prefix[index]);
            }
        }
        // cout << curr_odd << " " << curr_even << endl;
        if(curr_odd == curr_even){
            count++;
        }
    }
    
    if(n&1){
        curr_odd = odd_prefix[odd_size-1] - A[n-1];
        curr_even = even_prefix[even_size-1];
        if(curr_odd == curr_even)
            count++;
    }
    
    return count;
}
