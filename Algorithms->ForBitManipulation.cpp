//The simple codes for the bit manipulation.

//To swap two numbers without using any third vairable.
a=a^b;
b=a^b;
a=a^b;

//To check if ith bit is set or not.-> O(n)
if((N & (1<<i)) !=0) return true;
else return false;
or
if(1 & (N>>i)!=0) return true;
else return false;

//To set the ith bit.
return N | (i<<i);

//To clear the ith bit.
return (N & ~(1<<i));

//To toggle or switch the ith bit.
return (N ^ (1<<i));

//Remove the last set bit(rightmost).
return (N & N-1);

//Check if the number is a power of 2.
if(N & N-1 == 0) return true;
else return false;

//To count the number of set bits.
// Convert_to_binary & check the number of 1's(by if(n&1==1) cnt++;)
or
int n=__builtin_popcount()
or
while(N!=0){//T.C. =>O(No. of set bits)
    cnt++;
    N=N&N-1;
}

n/2 <==> n>>1;

//To get the number with only rightmost set digit is left.
n=(n&n-1)^n;
