//Optimal in case of both +ves and -ves
int lenOfLongSubarr(int A[],  int N, int K) 
{ 
    map<long long, int> prefixSumap;
    long long sum=0;
    int maxLen=0;
    for(int i=0;i<N;++i){
        sum+=A[i];
        if(sum==K) maxLen=i+1;
        int rem=sum-K;
        if(prefixSumap.find(rem)!=prefixSumap.end()){
            int len=i-prefixSumap[rem];
            maxLen=max(maxLen,len);
        }
        if(prefixSumap.find(sum)==prefixSumap.end()){
            prefixSumap[sum]=i;
        }
    }
    return maxLen;
}
