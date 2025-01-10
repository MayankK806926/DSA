//Majority Element(>n/2)

//TC-> O(2n) & SC-> O(1)
int majorityelement(vector<int>& v,int n){
  int cnt=0;
  int ele;
  for(int i=0;i<n;++i){
    if(cnt==0){
      cnt=1;
      ele=v[i];
    }
    else if(v[i]==ele) cnt++;
    else cnt--;
  }
  cnt=0;
  for(int i-0;i<n;++i){
    if(v[i]==ele) cnt++;
  }
  if(cnt>(n/2)) return ele;
  return -1;
}
