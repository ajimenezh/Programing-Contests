#include <iostream>
#include <map>
using namespace std;

const long long mod = 3211123;

long long calc(int n) {
  long long ret = 0,a,b,c,d,e,f,g,M = 3211123;

  for(a = 1; a < n; a++)
    for(b = 1; a+b < n && 2*a*b<n*n; b++)
      for(c = 1; a+b+c < n && 2*a*b + 2*a*c + 2*b*c<n*n; c++)
        for(d = 1; a+b+c+d < n && 2*a*b + 2*a*c + 2*b*c + 2*(a*d+b*d+c*d)<n*n; d++)
          for(e=1; a+b+c+d+e < n && 2*a*b + 2*a*c + 2*b*c + 2*(a*d+b*d+c*d) + 2*(a*e+b*e+c*e+d*e)<n*n; e++)
            for(f=1; a+b+c+d+e+f < n && 2*a*b + 2*a*c + 2*b*c + 2*(a*d+b*d+c*d) + 2*(a*e+b*e+c*e+d*e) + 2*(a*f+b*f+c*f+e*f+d*f)<n*n; f++) {
              g = n-a-b-c-d-e-f;
                if(a + b + c + d + e + f + g == n) {
                  ret = (ret + a*a + b*b + c*c + d*d + e*e + f*f + g*g)%M;
                  //cnt[(a*a + b*b + c*c + d*d + e*e + f*f + g*g)]++;
                 }
                }
  return ret;
}

long long fpow(long long a, long long b) {
	if (b==1) return a;
	if (b==0) return 1;
	long long tmp = fpow(a, b/2);
	tmp = (tmp*tmp)%mod;
	if (b%2==0) return tmp;
	return (a*tmp)%mod;
}

long long f(long long n) {
	if (n<=0) return 0;
	
	long long t = fpow(n, 8);
	t = ( t + (fpow(n,7)*24)%mod)%mod;  
	t = ( t + (fpow(n,6)*238)%mod)%mod; 
	t = ( t + (fpow(n,5)*1260)%mod)%mod; 
	t = ( t + (fpow(n,4)*3829)%mod)%mod; 
	t = ( t + (fpow(n,3)*6636)%mod)%mod; 
	t = ( t + (fpow(n,2)*6012)%mod)%mod; 
	t = ( t + (fpow(n,1)*2160)%mod)%mod; 
	
	t = t*fpow(2880, mod-2)%mod;
	
	return t;
}

int main() {
	
	long long n, sum = 0;
	
	while (cin>>n) {
		sum = (sum + f(n-6))%mod;
		//cout<<f(n-6)<<" "<<calc(n)<<endl;
		//cout<<sum<<endl;
	}
	
	cout<<sum<<endl;
	
}
