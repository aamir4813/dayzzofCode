
// https://practice.geeksforgeeks.org/problems/third-largest-element/1/?track=amazon-arrays&batchId=192
class GfG
{
    int thirdLargest(int a[], int n)
    {
	    // Your code here
	   int first =  Integer.MIN_VALUE ;
	   int second =  Integer.MIN_VALUE ;
	   int third =  Integer.MIN_VALUE ;
	   
	   int len = a.length ;
	   
	   for(int i = 0; i < n ; ++i){
	       
	       if(a[i] > first){
	           third = second;
	           second = first;
	           first = a[i];
	       }
	       else if(a[i] > second){
	           third = second ;
	           second = a[i];
	       }
	       else if(a[i] > third){
	           third = a[i];
	       }
	   }
	   
	   return third == Integer.MIN_VALUE ? -1 : third ;
    }
}