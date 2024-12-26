// https://chatgpt.com/c/676d7e02-dd74-8010-a515-b49fe32730a0
// Didn't understad the BS code.
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;++i){
        cin>>v[i];
    }
    vector<int> group_sizes;
    int current_type = v[0];
    int current_count = 0; 
    for (int i = 0; i < n; ++i) {
        if (v[i] == current_type) {
            ++current_count;
        } else {
            group_sizes.push_back(current_count);
            current_type = v[i];
            current_count = 1;
        }
    }
    group_sizes.push_back(current_count); 
    int max_length = 0;
    for (int i = 0; i < group_sizes.size() - 1; ++i) {
        max_length = max(max_length, 2 * min(group_sizes[i], group_sizes[i + 1]));
    }
    cout << max_length << endl;

    /*
    vector<int> pref1(n+1),pref2(n+1);
    for(int i=1;i<=n;++i){
        pref1[i]=pref1[i-1];
        pref2[i]=pref2[i-1];
        if(v[i]==1) pref1[i]++;
        else pref2[i]++;
    }
    // for(auto& c:pref1) cout<<c<<" ";
    // cout<<endl;
    // for(auto& c:pref2) cout<<c<<" ";
    // cout<<endl;
    ll l=1,r=n/2;
    ll ans=0;
    while(l<=r){
        ll mid=l+(r-l)/2;
        ll ok=0;ll len=2*mid;
        for(int i=len;i<=n;++i){
            if((pref1[i-mid]-pref1[i-len])==mid && (pref2[i]-pref2[i-mid]) ==mid) ok=1;
            if((pref2[i-mid]-pref2[i-len])==mid && (pref1[i]-pref1[i-mid]) ==mid) ok=1;
        }
        if(ok==1){
            l=mid+1;
            ans=max(ans,mid);
        }
        else r=mid-1;
    }
    cout<<2*ans<<endl;
    */
}
