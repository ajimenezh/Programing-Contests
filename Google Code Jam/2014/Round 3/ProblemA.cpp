#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

typedef long long LL;
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)

int n, p, q, r, s;
int a[1000010];
long long all[1000010];

int main() {

	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int tt;
    cin>>tt;
    for (int t=1; t<=tt; t++) {
        cin>>n>>p>>q>>r>>s;

        for (int i=0; i<n; i++) {
            a[i] = ((long long)i*p+q)%r + s;
        }

        //all[0] = a[0];
        //double res2 = 0;
        //for (int i=1; i<n; i++) all[i] = all[i-1] + a[i];
//        for (int i=0; i<n; i++) {
//            for (int j=i; j<n; j++) {
//                long long t1 = all[i];
//                long long t2 = all[j] - all[i];
//                long long t3 = all[n-1] - all[j];
//                res2 = max(res2, (double)(t1+t2+t3-max(max(t1,t2),t3))/(t1+t2+t3));
//            }
//        }

        long long sum = 0;
        for (int i=0; i<n; i++) sum += a[i];

        long long s1 = 0;
        int j = 0;
        double res = 0.0;
        for (j=0; j<n; j++) {
            if (s1+a[j]>sum-a[j]) {
                res = max(res, (double)(sum-a[j])/(s1+sum));
                break;
            }
            else {
                sum -= a[j];
                s1 += a[j];
                res = max(res, (double)(min(s1,sum))/(s1+sum));
            }
        }

        //for (int i=0; i<n; i++) cout<<a[i]<<" "; cout<<endl;

        long long s2 = 0;
        for (int k=0; k<n; k++) {
            s2 += a[k];
            s1 -= a[k];
            if (j==k) {
                j++;
                s1 += a[k];
                sum -= a[k];
            }
            while (j<n && s1+a[j]<=sum-a[j]) {
                s1 += a[j];
                sum -= a[j];
                j++;
            }
            //if (j==k) break;
            res = max(res, (double)(s1+s2+sum-max(max(s1,s2),sum))/(s1+s2+sum));
            if (j!=n && j!=k) res = max(res, (double)(s1+s2+sum-max(max(s1+a[j],s2),sum-a[j]))/(s1+s2+sum));
            //cout<<k<<" "<<j<<" "<<res<<endl;
            //cout<<s1<<" "<<s2<<" "<<sum<<endl;
        }

//        if (abs(res-res2)>1.0e-9) {
//            cout<<"Error"<<endl;
//            cout<<res<<" "<<res2<<endl;
//        }
        printf("Case #%d: %.12lf\n", t, res);

    }

	return 0;
}
