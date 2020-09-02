

void Solution::sortColors(vector<int> &A) {
   
   int n = A.size();
//   merge_sort(A , 0 , n-1);
    // sort(A.begin() , A.end());
    int count0 = 0 , count1 = 0 , count2 = 0 ;
    
    for(auto x : A){
        if(x == 1){
            count1++;
        }
        else if( x == 2)
            count2++;
        else
            count0++;
    }
    
    int index =  0 ;
    for(int i = 0 ; i <count0 ; ++i ){
        A[index++] = 0;
    }for(int i = 0 ; i <count1 ; ++i ){
        A[index++] = 1;
    }for(int i = 0 ; i <count2 ; ++i ){
        A[index++] = 2;
    }
}

