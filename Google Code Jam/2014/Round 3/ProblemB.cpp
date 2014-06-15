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

int p,q,n;
int h[101], g[101];
int res;
map<vector<int>, int> dp;

int rec(vector<int> &v) {
    int tot = 0;
    for (int i=0; i<n; i++) if (v[i]>0) tot += g[i];

    if (tot==0) {
        return 0;
    }
    if (dp.find(v)!=dp.end()) return dp[v];

    tot = 0;

    for (int i=0; i<n; i++) if (v[i]>0) {
        v[i] -= p;
        int tmp = 0;
        if (v[i]<=0) tmp += g[i];
        bool done = 0;
        for (int j=0; j<n; j++) if (v[j]>0) {
            v[j] -= q;
            tot = max(rec(v)+tmp, tot);
            v[j] += q;
            done = 1;
            break;
        }
        if (!done) tot = max(tot, tmp);
        v[i] += p;
    }
    for (int j=0; j<n; j++) if (v[j]>0) {
        v[j] -= q;
        tot = max(tot, rec(v));
        v[j] += q;
        break;
    }

    dp[v] = tot;
    return tot;
}

int dp2[101][1010][2];

int solve(int i, int left, int turn) {
    if (i==n) return 0;
    //cout<<i<<" "<<left<<" "<<turn<<" "<<dp2[i][turn][turn]<<endl;
    if (dp2[i][left][turn]>=0) return dp2[i][turn][turn];

    //cout<<i<<" "<<left<<" "<<turn<<endl;

    int tmp = 0;
    int hh = h[i];
    if (left==0 && turn==1) {
        hh -= q;
        if (hh<=0) {
            tmp = solve(i+1, left, 0);
            dp2[i][left][turn] = tmp;
            return tmp;
        }
    }

    for (int k=0; k*p<=h[i]+200; k++) {
        for (int j=0; j*q+k*p<=h[i]+200; j++) {
            if (turn==0) {
                if (max(j-1, 0)+left+1>=k) {
                    if (h[i]<=k*p+j*q && h[i]>max(k-1, 0)*p+j*q) {

                        int t = 0;
                        t = max(j-1, 0)-k+1;
                        t += left;

                        if (t<0) continue;

                        if (t>0) tmp = max(tmp, solve(i+1, t-1, 0) + g[i]);
                        tmp = max(tmp, solve(i+1, t+1, 1) + g[i]);
                    }
                }
            }
            else {
                if (j<1) continue;
                if (max(j-1, 0)+left+1>=k) {
                    if (h[i]<=k*p+j*q && h[i]>max(k-1, 0)*p+j*q) {
                        int t = 0;
                        t = max(j-1, 0)-k+1;
                        t += left;

                        if (t<0) continue;

                        tmp = max(tmp, solve(i+1, t, 1) + g[i]);
                        if (t>0) tmp = max(tmp, solve(i+1, t-1, 0) + g[i]);
                    }
                }
            }
        }
    }

    //cout<<i<<" "<<left<<" "<<turn<<" "<<tmp<<endl;

//    for (int j=0; j*p<=h[i]; j++) {
//        if (turn==0) {
//            if (hh-p*j>0 && (hh-p*j)%q<=p) {
//                int t = (hh-p*j)/q;
//                if (max(t-1)+left)
//                if (j==left) {
//                    tmp = max(tmp, solve(i+1, t, 1) + g[i]);
//                }
//                else {
//                    tmp = max(tmp, solve(i+1, left-j-1+t, 0) + g[i]);
//                }
//            }
//        }
//        else {
//            if (j!=left && hh-p*j>0 && (hh-p*j)%q<=p) {
//                int t = (hh-p*j)/q;
//                tmp = max(tmp, solve(i+1, left-j-1+t, 0) + g[i]);
//            }
//            else if (j==left) {
//                if (hh-p*j-q>0 && (hh-p*j-q)%q<=p) {
//                    int t = (hh-p*j-q)/q;
//                    tmp = max(tmp, solve(i+1, t, 1) + g[i]);
//                }
//            }
//        }
//        if (hh-p*j<=0) break;
//    }
    int t = (hh-1)/q + 1;
    //if (turn) t--;
    tmp = max(tmp, solve(i+1, left+t, 0));
    dp2[i][left][turn] = tmp;
    return tmp;
}

int main() {

	freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int tt;
    cin>>tt;
    for (int t=1; t<=tt; t++) {
        cin>>p>>q>>n;
        for (int i=0; i<n; i++) cin>>h[i]>>g[i];

        vector<int> v(n,0);
        for (int i=0; i<n; i++) v[i] = h[i];
        for (int i=0; i<n; i++) for (int j=0; j<=10*n; j++) {
            dp2[i][j][0] = -1;
            dp2[i][j][1] = -1;
        }
        res = 0;
        dp.clear();
        if (n<4) res = rec(v);
        else res = solve(0, 0, 0);
        printf("Case #%d: %d\n", t, res);
    }

	return 0;
}



