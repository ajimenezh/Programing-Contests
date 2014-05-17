#include <iostream>
#include <sstream>
#include <vector>
#include <string>
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


int gcd(int a, int b) {
    if (a<b) return gcd(b,a);
    return (b==0?a:gcd(b,a%b));
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    vector<pair<int,int> > v;
    for (int i=10; i<100; i++) {
        for (int j=i+1; j<100; j++) {
            pair<int,int> p = make_pair(i/gcd(i,j),j/gcd(i,j));
            int t1 = i/10;
            int t2 = i%10;
            int t3 = j/10;
            int t4 = j%10;

            pair<int,int> q = make_pair(0,0);
            if (t2==t4 && t2!=0) {
                q = make_pair(t1/gcd(t1,t3),t3/gcd(t1,t3));
                if (q==p) v.push_back(p);
            }
            if (t2==t3 && t2!=0) {
                q = make_pair(t1/gcd(t1,t4),t4/gcd(t1,t4));
                if (q==p) v.push_back(p);
            }
            if (t1==t4 && t1!=0) {
                q = make_pair(t2/gcd(t2,t3),t3/gcd(t2,t3));
                if (q==p) v.push_back(p);
            }
            if (t1==t3 && t2!=0) {
                q = make_pair(t2/gcd(t2,t4),t4/gcd(t2,t4));
                if (q==p) v.push_back(p);
            }

        }
    }

    for (int i=0; i<v.size(); i++) cout<<v[i].first<<" "<<v[i].second<<endl;

    int num = 1, den = 1;
    for (int i=0; i<v.size(); i++) {num *= v[i].first; den *= v[i].first;}

    den /= gcd(num,den);

    cout<<den;

    return 0;

}
