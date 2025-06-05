class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
        int n=dist.size();
        //Initialization
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(i==j) dist[i][j]=0;
                if(dist[i][j]==-1){
                    dist[i][j]=1e8;
                }
            }
        }

        for(int via=0;via<n;++via){
            for(int i=0;i<n;++i){
                for(int j=0;j<n;++j){
                    if(dist[i][via]!=1e8 && dist[via][j]!=1e8)
                        dist[i][j]=min(dist[i][j],dist[i][via]+dist[via][j]);
                }
            }
        }
        
        //TO detect negative cycle
        // for(int i=0;i<n;++i){
        //     if(dist[i][i]<0) return {-1};
        // }
        
        return ;
    }
};
