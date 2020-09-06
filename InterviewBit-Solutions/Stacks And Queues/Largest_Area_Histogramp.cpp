int Solution::largestRectangleArea(vector<int> &A) {
    
   int n = A.size();
   
   /*
        5 3 7 8 2 1
   */
   
   int i = 0 ;
   int ans = 0 ;
   stack<int> s;
   for( ;  i < n ; ){
       int x = A[i];
       if(s.empty()  or A[s.top()] <= x){
           s.push(i);
           ++i;
       }
       else{
           int top = s.top();
           s.pop();
           int temp = A[top] ;
           
           if(s.empty()) {
            //    6 5 4 3 2 1
                temp *= i;
           }
           else{
            //   2 1 3 4 2 1
               temp *= ( i - top -1 );
           }
           ans = max(ans , temp);
       }
   }
   
   while(!s.empty()){
           int top = s.top();
           s.pop();
           int temp = A[top] ;
           
           if(s.empty()) {
            //    6 5 4 3 2 1
                temp *= i;
           }
           else{
            //   2 1 3 4 2 1
               temp *= ( i - top -1 );
           }
           ans = max(ans , temp);
   }
   
   return ans;
}
