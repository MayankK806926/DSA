#include<bits/stdc++.h>
using namespace std;
#define ll long long

void heap_permutations(vector<int>& v,int n){
    if(n==1){
        for(auto& it:v) cout<<it<<" ";
        cout<<endl;
        return;
    }

    for(int i=0;i<n;++i){
        heap_permutations(v,n-1);
        if(i%2==0) swap(v[i],v[n-1]);
        else swap(v[0],v[n-1]);
    }
}

int main(){
    vector<int> v = {1,2,3,4,5};
    heap_permutations(v,v.size());
}
