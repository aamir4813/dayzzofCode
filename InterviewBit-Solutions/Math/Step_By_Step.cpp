#define ll long long int
int Solution::solve(int A) {
     int temp =abs(A);
        
        // i have just taken a roughtlu value of hight
        // that's represent that first nth sum will be more than 1e9
        ll low = 0 , high = 5e4;
        int nth_sum = 0 ;
        int index = 0 ;
        while(low <= high){
                ll mid = (low + (high- low) / 2 );

                ll sum = (mid +1)*mid / 2 ;

                if(temp == sum){
                        index = mid;
                        nth_sum = sum;
                        break;
                }
                else if(temp < sum){
                        index = mid;
                        nth_sum = sum;
                        high = mid-1;
                }
                else if(temp > sum){
                        low = mid+1;
                }
        } 
        
        // just upper_bound of index and sum
        ll left_over = nth_sum - temp;
        
        if(left_over & 1){
            if(index & 1) 
                return index+2;
                
            return index+1;
        }
        else{
            return index;
        }
        
        // return index + 2*left_over ;
}
