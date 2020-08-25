int Solution::repeatedNumber(const vector<int> &A) {
      int cnt1 = 0 , cnt2 = 0;
    int temp1 = INT_MAX , temp2 = INT_MAX;
    int n = A.size();
    for(int i= 0 ; i < n ; ++i){
        if(A[i] == temp1){
            cnt1++;
        }
        else if(A[i] == temp2){
            cnt2++;
        }
        else if(cnt1 == 0){
            cnt1++;
            temp1 = A[i];
        }
        else if(cnt2 == 0){
            cnt2++;
            temp2 = A[i];
        }
        else{
            cnt1--;
            cnt2--;
        }
    }
    cnt1 = 0 ; cnt2 = 0;
    for(int i = 0 ; i < n ; ++i){
        if(temp1 == A[i])
            cnt1++;
        if(temp2 == A[i])
            cnt2++;
    }
    if(cnt1 > n/3)
        return temp1;
    if(cnt2 > n/3)
        return temp2;
        
    return -1;
    
}
