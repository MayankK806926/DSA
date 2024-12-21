class Solution {
public:
    int candy(vector<int>& ratings) {
        /*
        int n=ratings.size();
        int total=0;
        vector<int> v(n,1);
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i-1]) {
                v[i] = v[i-1] + 1;
            }
        }
        for (int i = n-2; i >= 0; --i) {
            if (ratings[i] > ratings[i+1]) {
                v[i] = max(v[i], v[i+1] + 1);
            }
        }
        for(int i=0;i<n;++i) total+=v[i];
        return total;
        */
        //SLope Approach
        int total=1;int i=1;
        int n=ratings.size();
        while(i<n){
            if(ratings[i]==ratings[i-1]){
                i++;total++;
                continue;
            }
            int peak=1;
            while(i<n && ratings[i-1]<ratings[i]){
                peak++;total+=peak;i++;
            }
            int down=1;
            while(i<n && ratings[i-1]>ratings[i]){
                total+=down;down++;i++;
            }
            if(down>peak) total+=(down-peak);
            // if(down==peak) total+=(down+1);
        }
        return total;
    }
};
