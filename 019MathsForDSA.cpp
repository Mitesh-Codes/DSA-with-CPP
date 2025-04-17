#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

bool isPrime(int number){
    if(number<=1){
        return 0;
    }
    else{
        for(int i=2;i<number;i++){
            if((number%i)==0){
                return 0;
            }
            
        }
        return 1;
    }
    //Timecomplexity: O(n) & Spacecomplexity: O(1).
    //This is a brute force approach.

}

int countPrime(int n){
    int count=0;
    vector<bool>prime(n+1,true);
    for(int i=2;i<n;i++){
        if(prime[i]){
            count++;
            for(int j=2*i;j<n;j=j+i){
                prime[j]=0;
            }
        }
    }
    return count;

//Better Approach --> Sieve of Eratosthenes
//Timecomplexity: O(nlog(logn)) & Spacecomplexity: O(n).
}

vector<int> generateBasePrimes(int limit) {
    vector<bool> isPrime(limit + 1, true);
    vector<int> primes;
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i <= limit; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= limit; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return primes;
}


//Just write ,didn't understand the code of Segmented Sieve of Eratosthenes

void segmentedSieve(int l, int h) {
    int n = h - l + 1;
    vector<bool> prime(n, true);

    // Step 1: Get base primes up to sqrt(h)
    vector<int> basePrimes = generateBasePrimes(sqrt(h));

    // Step 2: Mark non-primes in range [l, h]
    for (int p : basePrimes) {
        int start = max(p * p, ((l + p - 1) / p) * p); // First multiple of p in [l, h]
        for (int j = start; j <= h; j += p) {
            prime[j - l] = false;
        }
    }

    // Step 3: Print primes in range
    for (int i = 0; i < n; i++) {
        int num = i + l;
        if (prime[i] && num >= 2) {
            cout << num << " ";
        }
    }
    cout << endl;
}

int GCD(int a,int b){
    if(a==0){
        return b;
    }
    if(b==0){
        return a;
    }

    while(a!=b){
        if(a>b){
            a=a-b;
        }
        else{
            b=b-a;
        }
    }
    return a;
    //Timecomplexity: O(max(a,b)) & Spacecomplexity: O(1).
}

int modularExponentiation(int x, int n, int m) {
	int res =1;
	while(n>0){
		if(n&1){
            //odd number
			res=(1LL*(res)*(x)%m)%m;
		}
		x=(1LL*(x)%m*(x)%m)%m;
		n=n>>1;
	}
	return res;
// Timecomplexity: O(logn) & Spacecomplexity: O(1).
    //This is a better approach than brute force.
    //Brute force approach will take O(n) time.
}

int main(){

    //    int number=1;
    //    if(isPrime(number)==0){
    //     cout<<"NOT Prime";
    //    }
    //    else{
    //     cout<<"Prime";
    //    }

    //    cout<<endl;
    int n=100;
    cout<<"Count of prime numbers from 1 to "<<n<<" is: "<<countPrime(n)<<endl;

    cout<<endl;
    int l=2,h=100;
    cout<<"Prime numbers between "<<l<<" and "<<h<<" are: ";
    segmentedSieve(l,h);
    cout<<endl;

    int a=10,b=20;
    cout<<"GCD of "<<a<<" and "<<b<<" is: "<<GCD(a,b)<<endl;
    cout<<endl;

    int x=2,n1=5,m=1000;
    cout<<"Modular Exponentiation of "<<x<<"^"<<n1<<" % "<<m<<" is: "<<modularExponentiation(x,n1,m)<<endl;
    cout<<endl;





    return 0;
}