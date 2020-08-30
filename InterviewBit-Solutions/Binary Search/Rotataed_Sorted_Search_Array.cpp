int pivotFinder(vector<int>&arr){
	int lo = 0 , hi = arr.size()-1;


	if(arr[0] < arr[hi] or n == 1)
		return 0;
	while(lo <= hi){
		int mid = (lo+ (hi - lo)/2);
		
		if(mid+1 <= hi && arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]){
			return mid;	
		}
		else if(A[lo] < A[mid]){
			lo = mid+1;
		}
		else{
			hi = mid-1;
		}
	}
}
