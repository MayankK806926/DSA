//C++

#include<bits/stdc++.h>
using namespace std;

long long maxSum(int arr[], int n, int k)
{
    long long res = 0;
    for (int i=0; i<k; i++)
       res += arr[i];
    long long curr_sum = res;
    for (int i=k; i<n; i++)
    {
       curr_sum += arr[i] - arr[i-k];
       res = max(res, curr_sum);
    }
    return res;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;++i){
            cin>>a[i];
        }
        long long max_choco=maxSum(a,n,k);
        cout<<max_choco<<endl;
    }
}

// Python
/*
def s_del(s):
    stack = []
    for char in s:
        if stack and ((stack[-1] == '0' and char == '1') or (stack[-1] == '1' and char == '0')):
            stack.pop()
        else:
            stack.append(char)
    return len(stack)
n=int(input())
s=str(input())
print(s_del(s))
*/
