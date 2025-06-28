//Warnsdorff's Algorithm
#include<bits/stdc++.h>
using namespace std;

int cntOptions(vector<vector<int>>& ans,int i,int j,vector<pair<int,int>>& paths){
    int cnt=0;
    int n=ans.size();
    for(int k=0;k<8;++k){
        int r=i+paths[k].first;
        int c=j+paths[k].second;
        if(r>=0 && c>=0 && r<n && c<n && ans[r][c]==-1) ++cnt;
    }
    return cnt;
}

vector<pair<int,int>> getSortedMoves(vector<vector<int>>& ans,int i,int j,vector<pair<int,int>>& paths){
    vector<pair<int,int>> movesList;//{optionsCount,directionIndex}
    for(int k=0;k<8;++k){
        int r=i+paths[k].first;
        int c=j+paths[k].second;

        if(r>=0 && c>=0 && r<ans.size() && c<ans.size() && ans[r][c]==-1){
            int options=cntOptions(ans,r,c,paths);
            movesList.emplace_back(options,k);
        }
    }
    //Warndorff's Rule
    sort(movesList.begin(),movesList.end());
    return movesList;
}

bool traversal(int i,int j,int n,int ind,vector<vector<int>>& ans,vector<pair<int,int>>& paths){
    if(ind==n*n) return true;
    auto moves=getSortedMoves(ans,i,j,paths);
    for(auto& it:moves){
        int k=it.second;
        int r=i+paths[k].first;
        int c=j+paths[k].second;
        if(r>=0 && c>=0 && r<n && c<n && ans[r][c]==-1){
            ans[r][c]=ind;
            if(traversal(r,c,n,ind+1,ans,paths)) return true;
            ans[r][c]=-1;
        }
    }
    return false;
}

int main(){
    int n;cin>>n;
    vector<vector<int>> ans(n,vector<int>(n,-1));
    ans[0][0]=0;
    vector<pair<int,int>> paths={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
    if(traversal(0,0,n,1,ans,paths)){
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
    }else cout<<-1<<endl;
    return 0;
}
