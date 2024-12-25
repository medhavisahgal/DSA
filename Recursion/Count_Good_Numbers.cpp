class Solution
{
public:
    int M=1e9+7;
    //power function to calculate x^p in log(p) time
    //x^p=(x^2)^(p/2) if p is even
    //x^p=x*(x^2)^((p-1)/2) if p is odd
    //this is recursive implementation of power function
    long long power(long long x,long long p)
    {
        if(p==0)return 1;
        else if(!(p%2))
        {
            return power((x*x)%M,p/2);
        }
        else
        {
            return (x*power((x*x)%M,(p-1)/2))%M ;
        }
    }
    //Iterative approach
    long long power2(int x,int p){
        long long ans=1;
        int x=x%M;
        if(x==0)return 0;
        while(p>0){
            if(p&1){
                ans=(ans*x)%M;
            }
            p=p>>1;//p=p/2
            x=(x*x)%M;
        }
        return ans;
    }
    int countGoodNumbers(long long n)
    {
        //evens={0,2,4,6,8}(5)
        //primes={2,3,5,7}(4)
        long long no_of_4s=n/2;
        long long no_of_5s=n-no_of_4s;
        long long ans =((power2(4LL,no_of_4s)%M*power2(5LL,no_of_5s)%M)%M);
        return (int)ans;
    }
};
