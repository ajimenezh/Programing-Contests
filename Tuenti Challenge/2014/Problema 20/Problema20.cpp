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

double v[8], m[8][8], p[8];
int w[8];

int main() {

	long long n, sum = 0;

	for (int i=7; i<15; i++) {
        v[i-7] = calc(i);
        m[i-7][0] = i-7+1;
        for (int j=1; j<8; j++) {
            m[i-7][j] = m[i-7][j-1]*(i-7+1);
        }
	}

	for (int i=1; i<8; i++) {
        for (int j=i; j<8; j++) {
            double tmp = -m[j][i-1]/m[i-1][i-1];
            for (int k=i-1; k<8; k++) m[j][k] += tmp*m[i-1][k];
            v[j] += tmp*v[i-1];
        }
	}

	for (int i=7; i>=0; i--) {
        double s = 0;
        for (int j=i+1; j<8; j++) s += m[i][j]*p[j];
        p[i] = (v[i] - s) / m[i][i];
	}

    long long den = (1.0/p[7]+0.01);
	for (int i=0; i<8; i++) w[i] = p[i]/p[7] + 0.01;

    while (cin>>n) {
		long long tmp = n-6;
		long long t = 0;
		for (int i=0; i<8; i++) {
            t += (tmp*w[i])%mod;
            t %= mod;
            tmp *= (n-6);
            tmp %= mod;
		}
		sum = (sum + (t*fpow(den, mod-2))%mod)%mod;
	}


	cout<<sum<<endl;

}
