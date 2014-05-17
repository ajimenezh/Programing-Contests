#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <stdio.h>

using namespace std;

#define fo(i,n) for(int i=0; i<(int)n; i++)
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

vector<int> pr;
int p[] = {2,3,5,7,11,13,17,19,23,29,31,37}; //12
vector<int> m;
vector<bool> sp;
int n,K;
int a[21];
int dp[20][150][33000];

int solve(int i, int k, int mask) {
    if (k>=pr.size()) return 100000000;
    if (i==n) return 0;
    if (dp[i][k][mask]>=0) return dp[i][k][mask];

    int tmp = 100000000;

    for (int j=k; j<pr.size(); j++) {
        if (K>=a[i]) tmp = min(tmp, solve(i+1,k,mask) + K-a[i]);
        else {
            if (!sp[j]) {
                int mask2 = m[j];
                if (mask2&mask) continue;
                if (pr[j]*K>=a[i]) {
                    tmp = min(tmp, solve(i+1,j+1,mask2|mask) + pr[j]*K - a[i]);
                }
            }
            else {
                if (pr[j]*K>=a[i]) {
                    tmp = min(tmp, solve(i+1,j+1,mask) + pr[j]*K - a[i]);
                }
            }
        }
    }

    //cout<<i<<" "<<k<<" "<<pr[(k==0?0:k-1)]<<" "<<mask<<" "<<tmp<<endl;
    dp[i][k][mask] = tmp;
    return tmp;
}

int gcd(int x, int y){
    if (y>x) return gcd(y,x);
    if (y==0) return x;
    return gcd(y,x%y);
}

int solve2() {
    int tmp = 1000000;
    for (int i=a[0]; i<100; i++) {
        for (int j=a[1]; j<100; j++) {
            for (int k=a[2]; k<100; k++) {
                for (int t=a[3]; t<100; t++) {
                    if (gcd(i,j)==K && gcd(i,k)==K && gcd(j,k)==K && gcd(i,t)==K && gcd(j,t)==K && gcd(k,t)==K) {
                        if (i-a[0] + j-a[1] + k-a[2] + t-a[3]< tmp) {
                            tmp = i-a[0] + j-a[1] + k-a[2] + t-a[3];
                            cout<<i<<" "<<j<<" "<<k<<" "<<t<<endl;
                        }
                    }
                }
            }
        }
    }
    return tmp;
}

bool isprime(int x) {
    for (int i=2; i*i<=x; i++) if (x%i==0) return false;
    return true;
}

int main() {

    //freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int k = 2;
    while (pr.size()<60) {
        while (!isprime(k)) k++;
        pr.push_back(k);
        k++;
    }
    for (int i=2; i<=80; i++) {
        if (!isprime(i)) pr.push_back(i);
    }
    sort(pr.begin(),pr.end());

    for (int i=0; i<pr.size(); i++) {
        bool est = 1;
        for (int j=0; j<12; j++) if (pr[i]%p[j]==0) {
            est = 0;
            break;
        }
        sp.push_back(est);
        int mask = 0;
        if (!sp[i]) {
            for (int j=0; j<12; j++) if (pr[i]%p[j]==0) {
                mask |= (1<<j);
            }
        }
        m.push_back(mask);

        //cout<<pr[i]<<" "<<sp[i]<<" "<<m[i]<<endl;
    }

    int t;
    cin>>t;
    for (int cas=1; cas<=t; cas++) {
        cin>>n>>K;
        for (int i=0; i<n; i++) {
            cin>>a[i];
        }
        sort(a,a+n);
        int k = 0;
        while (n>0 && a[0]==0) {
            swap(a[0],a[n-1]);
            n--;
            k++;
            sort(a,a+n);
        }
        int ans = 0;
        if (k!=0) ans += (k-1)*K;
        if (n==0) ans += 0;
        else {
            for (int i=0; i<n; i++) for (int j=0; j<pr.size(); j++) for (int k=0; k<(1<<12); k++) dp[i][j][k] = -1;
            ans += solve(0,0,0);
            //cout<<solve2()<<endl;
        }

        printf("Case #%d: %d\n",cas, ans);
    }

    return 0;

}
