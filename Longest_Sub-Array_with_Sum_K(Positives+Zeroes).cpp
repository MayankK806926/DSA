int lenOfLongSubarr(int A[],  int N, int K) 
{ 
    int l=0;
    int maxlen=0;
    long long sum=0;
    for(int r=0;r<N;++r){
        sum+=A[r];
        while(l<=r && sum>K){
            sum-=A[l];
            l++;
        }
        if(sum==K) maxlen=max(maxlen,r-l+1);
        
    }
    return maxlen;
}
