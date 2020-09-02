int Solution::removeElement(vector<int> &A, int B) {
    int i = 0 , j = 0 ;
    
    int n = A.size();
    
    while(i < n ){
        
        if(A[i] == B){
            ++i;
            continue;
        }
        else{
            A[j] = A[i];
            ++j;
            ++i;
        }
    }
    // A.resize(j+1);
    return j;
}
