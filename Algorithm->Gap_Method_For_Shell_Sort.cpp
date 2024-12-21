class{
  private:
  void swapIfGreater(long long arr1[],long long arr2[],int ind1,int ind2){
    if(arr1[ind1]>arr2[ind2]){
      swap(arr1[ind1],arr2[ind2]);
    }
  }
  public:
  void merge(long long arr1[],long long arr2[],int n,int m){
    int len=n+m;
    int gap=len/2+len%2;
    while(gap>0){
      int left=0;int right=left+gap;
      while(right<len){
        if(left<n && right>=n){
          swapIfGreater(arr1,arr2,left,right-n);
        }
        else if(left>=n){
          swapIfGreater(arr1,arr2,left-n,right-n);          
        }
        else{
          swapIfGreater(arr1,arr2,left,right);          
        }
        left++;right++;
        if(gap==1) break;
        gap=gap/2+gap%2;
      }
    }
  }
}
