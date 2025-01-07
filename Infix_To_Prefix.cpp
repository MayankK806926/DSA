int priority(char a){
    if(a=='^') return 3;
    else if(a=='*' || a=='/') return 2;
    else if(a=='+' || a=='-') return 1;
    else return -1;
}
//TC->O(n/2) + O(n/2) + O(n+n) & SC-> O(n) + O(n)
string infixToPrefix(string& s) {
    // Your code here
    reverse(s.begin(),s.end());
    int n=s.size();
    for(int i=0;i<n;++i){
        if(s[i]=='(') s[i]=')';
        if(s[i]==')') s[i]='(';
    }
    int i=0;
    stack<char> st;string ans="";
    while(i<n){
        if((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9')){
            ans+=s[i];
        }else if(s[i]=='(') st.push('(');
        else if(s[i]==')'){
            while(st.empty() && st.top()!='('){
                ans+=st.top();
                st.pop();
            }st.pop();
        }else{
            if(s[i]=='^'){
              while(st.empty() && priority(s[i])<=priority(st.top())){
                  ans+=st.top();
                  st.pop();
              }
            }  
            else{
              while(st.empty() && priority(s[i])<priority(st.top())){ //Important change compared to the InfixToPostfix
                  ans+=st.top();
                  st.pop();
              }
            }  
            st.push(s[i]);
        }
        i++;
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
