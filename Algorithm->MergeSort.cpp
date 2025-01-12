//TC-> O(nlogn) & SC-> O(n)

void merge(vector<int>& arr,int low, int mid, int high){
    vector<int> temp;
    int l=low;int r=mid+1;
    while(l<=mid && r<=high){
        if(arr[l]>arr[r]){
            temp.push_back(arr[r]);
            r++;
        }
        else{
            temp.push_back(arr[l]);
            l++;
        }
    }
    while(l<=mid){
        temp.push_back(arr[l]);
        l++;
    }
    while(r<=high){
        temp.push_back(arr[r]);
        r++;
    }
    for(int i=low;i<=high;++i){
        arr[i]=temp[i-low];
    }
}

void mergeSort(vector<int>& arr, int l, int r) {
    // code here
    if(l==r) return;
    int mid=l+(r-l)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    merge(arr,l,mid,r);
}
