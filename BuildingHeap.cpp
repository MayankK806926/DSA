#include<bits/stdc++.h>
using namespace std;

class heap{
    int arr[100];
    int size;
public:
    heap(){
        arr[0]=-1;
        size=0;
    }    

    void insert(int num){//TC->O(logN)
        size++;
        int ind=size;
        arr[ind]=num;
        //Taking the num to its correct position as per max heap;
        while(ind>1){
            int parent=ind/2;
            if(arr[parent]<arr[ind]){
                swap(arr[parent],arr[ind]);
                ind=parent;
            }else{
                return ;
            }
        }
    }

    void deletionOfRoot(){//TC->O(logN)
        //step1: Swap root with last node;
        arr[1]=arr[size];
        arr[size]=0;
        //Step2: Delete last node;
        size--;

        //Step3: Take the node to its correct position;
        int ind=1;
        while(ind<size){
            int leftChild=2*ind;
            int rightChild=2*ind+1;

            if(arr[ind] < arr[leftChild]){
                swap(arr[ind],arr[leftChild]);
                ind=leftChild;
            }else if(arr[ind] < arr[rightChild]){
                swap(arr[ind],arr[rightChild]);
                ind=rightChild;
            }else{
                return;
            }
        }
    }

    
    void print(){
        for(int i=1;i<=size;++i) cout<<arr[i]<<" ";
        cout<<endl;
    }
};

void heapify(int arr[],int n,int i){//TC->O(n);
    int largest=i;
    int leftInd=2*i;
    int rightInd=2*i+1;

    if(leftInd<=n && arr[largest] < arr[leftInd]){
        largest=leftInd;
    }
    if(rightInd<=n && arr[largest] < arr[rightInd]){
        largest=rightInd;
    }

    if(largest != i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}

void heap_sort(int arr[],int n){
    int t=n;
    while(t>1){
        //step1 : swap root and last element;
        swap(arr[1],arr[t]);
        //step2: reduce the size of arr;
        t--;

        //step3 : heapify the left array;
        heapify(arr,t,1);
    }
}

int main(){
    heap h;
    h.insert(43);
    h.insert(57);
    h.insert(32);
    h.insert(46);
    h.insert(24);
    h.print();

    h.deletionOfRoot();
    h.print();

    int arr[6]={-1, 54, 53, 55, 52, 50};
    int n=5;
    for(int i=n/2;i>0;--i){
        heapify(arr,n,i);
    }
    for(int i=1;i<=n;++i) cout<<arr[i]<<" ";
    cout<<endl;
    
    heap_sort(arr,n);
    for(int i=1;i<=n;++i) cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}
