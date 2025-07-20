//Uses monotonic stack
#include<bits/stdc++.h>
using namespace std;

vector<int> NSE(vector<int>& arr,int n){
    stack<int> st;
    vector<int> ans(n,-1);
    for(int i=n-1;i>=0;--i){
        while(!st.empty() && arr[i] < st.top()) st.pop();
        if(!st.empty()) ans[i]=st.top();
        st.push(arr[i]);
    }

    return ans;
}
vector<int> NGE(vector<int>& arr,int n){
    stack<int> st;
    vector<int> ans(n,-1);
    for(int i=n-1;i>=0;--i){
        while(!st.empty() && arr[i] >= st.top()) st.pop();
        if(!st.empty()) ans[i]=st.top();
        st.push(arr[i]);
    }

    return ans;
}

vector<int> PSE(vector<int>& arr,int n){
    stack<int> st;
    vector<int> ans(n,-1);
    for(int i=0;i<n;++i){
        while(!st.empty() && arr[i] < st.top()) st.pop();
        if(!st.empty()) ans[i]=st.top();
        st.push(arr[i]);
    }

    return ans;
}
vector<int> PGE(vector<int>& arr,int n){
    stack<int> st;
    vector<int> ans(n,-1);
    for(int i=0;i<n;++i){
        while(!st.empty() && arr[i] >= st.top()) st.pop();
        if(!st.empty()) ans[i]=st.top();
        st.push(arr[i]);
    }

    return ans;
}

int main(){
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;++i) cin>>arr[i];
    vector<int> nse=NSE(arr,n);

    for(auto& it:nse) cout<<it<<" ";
    cout<<endl;
    vector<int> pse=PSE(arr,n);

    for(auto& it:pse) cout<<it<<" ";
    cout<<endl;

    vector<int> nge=NGE(arr,n);

    for(auto& it:nge) cout<<it<<" ";
    cout<<endl;
    vector<int> pge=PGE(arr,n);

    for(auto& it:pge) cout<<it<<" ";
    cout<<endl;
}
