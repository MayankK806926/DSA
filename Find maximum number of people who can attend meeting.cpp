#include<bits/stdc++.h>
using namespace std;

int maxPeople(vector<vector<int>>& mat,int n){
    sort(mat.begin(),mat.end(),[&](auto a,auto b){
        if(a[1]==b[1]) return a[0]<b[0];
        return a[1]<b[1];
    });

    vector<int> dp(n,0);
    dp[0]=mat[0][2];
    // Need a map to store the highest possible value, for same end timed intervals
    map<int,int> mpp;
    mpp[mat[0][1]]=dp[0];
    for(int i=1;i<n;++i){
        int start=mat[i][0];
        int end=end;
        int people=mat[i][2];

        if(start <= mat[i-1][1]){
            //Perform BS to find the nearest meeting which doesnot overlap;
            int l=0,r=i;
            while(l<r){
                int mid=l+(r-l)/2;
                if(mat[mid][1] < start){
                    l=mid;
                }else r=mid-1;
            }
            dp[i]= max(dp[i-1], mpp[mat[l][1]] + people);
            mpp[end]=max(dp[i],mpp[end]);
        }else{
            dp[i]=dp[i-1]+people;
            mpp[end]=max(mpp[end],dp[i]);
        }
    }

    return dp[n-1];
}

int main(){
    vector<vector<int>> meetings={ {1, 5, 20}, {3, 8, 50},{6, 10, 70} };
    int n=meetings.size();
    int mx_people=maxPeople(meetings,n);
    cout<<mx_people<<endl;
    return 0;
}
