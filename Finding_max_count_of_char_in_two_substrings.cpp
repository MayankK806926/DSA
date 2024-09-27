#include<bits/stdc++.h>
using namespace std;

int f(string str){
    vector<int> hsh(26,0);
    for(int i=0;i<str.size();++i){
        hsh[str[i]-'a']++;
    }
    int max=0;
    for(int i=0;i<26;++i){
        if(hsh[i]>=1){
            max++;
        }
    }
    return max;
}

int maxSum(string s, int n)
{
    long long res=0;
    long long max_sum = 0;
    for (int i=0; i<n; i++){
        res = 0;
        res = (f(s.substr(0,i+1))+f(s.substr(i+1,(n-1-i))));
        if(res>max_sum){
            max_sum=res;
        }
    }
    return max_sum;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int prefix[n];
        int sufix[n];
        set<int> st;
        for (int i = 0; i < n; i++)
        {
            st.insert(s[i]);
            prefix[i] = st.size();
        }
        st.clear();
        for (int i = n - 1; i >= 0; i--)
        {
            st.insert(s[i]);
            sufix[i] = st.size();
        }
        int res = 0;
        for (int i = 0; i < n - 1; i++)
        {
            res = max(res, prefix[i] + sufix[i + 1]);
        }
        cout << res << endl;
    }
}
