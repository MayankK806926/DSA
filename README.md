Here, I'm adding some of the special and good level problems which were either difficult for me or attracted me for the logic used in the problem statement.

Some more things:

-> The digital root of a non-negative integer is the single digit value obtained by an iterative process of summing digits, on each iteration using the result from the previous iteration to compute a digit sum. The process continues until a single-digit number is reached.

-> To handle the case of odd and even(int and float):
 int k=n/2+n%2;

-> To avoid using both the cases of n%m==0 and m%n==0: if(m>n){ swap(s,t); swap(n,m); }

-> To take input in C++, if we don't know the length of vector: int main()
{
    ll t;
    cin >> t;
    cin.ignore();
    int cnt = 0;
    bool ans = true;
    while (t--)
    {
        ans = true;
        vector<int> v;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number){
            v.push_back(number);
        }
        if (isSafe(v) || isOneRemovalSafe(v))
            cnt++;
    }
    cout << cnt << endl;
}

