vector<int> Solution::subUnsort(vector<int> &A) {
    
    int n=A.size();
    int s=-1,e=-1;
    for(int i=0;i<n-1;i++){
        if(A[i]>A[i+1]){
            s=i;
            break;
        }
    }
    if(s==-1){
        return {-1};
    }
    for(int i=n-1;i>0;i--){
        if(A[i]<A[i-1]){
            e=i;
            break;
        }
    }
    int mn=A[s],mx=A[s];
    for(int i=s+1;i<=e;i++){
        if(A[i]<mn)
         mn=A[i];
        else if(A[i]>mx)
         mx=A[i];
    }
    for(int i=0;i<s;i++){
        if(A[i]>mn){
         s=i;
         break;
        }
    }
    for(int i=n-1;i>e;i--){
        if(A[i]<mx){
         e=i;
         break;
        }
    }
    return {s , e};
}
