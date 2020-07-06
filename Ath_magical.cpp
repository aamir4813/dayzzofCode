public class Solution {
    public int solve(int A, int B, int C) {
        // BinarySearch Approach here 
        long  p = C / gcd(C ,B)  * B;
        long mod = 1000000007;
        long lo = 0 ;
        long hi = (long)A * Math.max(C , B);
        
        while(lo < hi){
            long mid = lo + (hi - lo)/2;
            if( mid / C + mid / B - mid / p  < A){
                lo = mid+1;
            }
            else{
                hi = mid;
            }
        }
        
        return (int)(lo % mod);
    }
    private int gcd(int x , int y){
        if( x == 0)
            return y;
        return gcd(y % x , x);
    }
}