//Binary Search
#include<bits/stdc++.h>
using namespace std;
int b=0,s=0,c=0;
int nb,ns,nc;
int pb,ps,pc;
long long r;

bool check(long long mid){
     long long n=0;
     if(mid*b>nb) n+=(mid*b-nb)*pb;
     if(mid*s>ns) n+=(mid*s-ns)*ps;
     if(mid*c>nc) n+=(mid*c-nc)*pc;
     return n<=r;
}

int main(){
     string st;
     cin>>st;
     cin>>nb>>ns>>nc;
     cin>>pb>>ps>>pc;
     cin>>r;
     for(int i=0;i<st.size();i++)
	{
		if(st[i]=='B') b++;
		else if(st[i]=='S') s++;
		else c++;
	}
     long long start=0,end=r+max(nb,max(ns,nc));
     while(start<=end){
          long long mid=(start+end)/2;
          if(check(mid)) start=mid+1;
          else end=mid-1;
     }
     cout<<end<<endl;
}
