int Solution::solve(vector<int> &A, int B) {
    int i=0 , j=0 , cnt=0 ,ans=0;
     int n = A.size();
     for(int j =0; j<n; j++){
         if(A[j]==0){
             cnt++;
         }
         while(cnt>B){
             if(A[i]==0){
             cnt--;
            }
            i++;
        }
        if(j-i+1>ans){
            ans=j-i+1;
        }
    }
     return ans;
}
