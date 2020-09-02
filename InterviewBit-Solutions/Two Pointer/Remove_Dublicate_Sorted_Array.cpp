int Solution::removeDuplicates(vector<int> &A) {

    int n = A.size();
    
    int i=1,j=1;
    for(; i<A.size() && j<A.size();i++){
        if(A[i]!=A[j]){
            A[j]=A[i];
        }
        if(A[j-1]!=A[j]){
            j++;
        }
    }
    return j;
}
