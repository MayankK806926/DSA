void countingSort(int arr[],int n,int exp){
    vector<int> op(n);
    vector<int> cnt(10);
    for(int i=0;i<n;++i) cnt[(arr[i]/exp) % 10]++;
    for(int i=1;i<10;++i) cnt[i]+=cnt[i-1];
    
    for(int i=n-1;i>=0;--i){
        op[cnt[(arr[i]/exp) % 10] - 1]=arr[i];
        cnt[(arr[i]/exp)%10]--;
    }
    for(int i=0;i<n;++i) arr[i]=op[i];
}

void radixSort(int arr[], int n) {
    int mx=*max_element(arr,arr+n);
    for(int i=1;mx/i > 0;i*=10)
        countingSort(arr,n,i);
    return ;
}
