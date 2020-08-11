// https://practice.geeksforgeeks.org/problems/minimum-distance-between-two-numbers/1/?track=amazon-arrays&batchId=192
class Solution {
    
    int minDist(int a[], int n, int x, int y) {
    int i=0,p=-1, min_dist=Integer.MAX_VALUE; 
      
    for(i=0 ; i<n ; i++) 
    { 
        if(a[i] ==x || a[i] == y) 
        { 
            if(p != -1 && a[i] != a[p]) 
                min_dist = Math.min(min_dist,i-p); 
               
            p=i; 
        } 
    } 
    if(min_dist==Integer.MAX_VALUE) 
       return -1; 
    return min_dist; 
        
    }
}