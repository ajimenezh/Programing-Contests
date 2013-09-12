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

int b,d;
string a,c;
int next[101];
int cnt[101];
int s[101];
int cnt1[101];
int next1[101];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>b>>d;
    cin>>a>>c;

    for (int i=0; i<a.length();i++) {
        int now = i;
        int t = 0;
        int last;
        for (int j=0; j<c.length(); j++) {
            bool good = 0;
            for (int k=now; k<a.length(); k++) {
                if (a[(k)%a.length()]==c[j]) {
                    good = 1;
                    j++;
                    last = (k+1)%a.length();
                    if (j==c.length()) break;
                }
                if (k==a.length()-1) j--;
            }
            t++;
            if (last!=0 && j==c.length()) t--;
            if (!good && now==0) {
                cout<<0<<endl;
                return 0;
            }
            now = 0;
        }
        cnt[i] = t;
        next[i] = last;
    }

    for (int i=0; i<a.length(); i++) s[i] = 1;
    for (int i=0; i<a.length(); i++) next1[i] = next[i];
    for (int i=0; i<a.length(); i++) cnt1[i] = cnt[i];

    for (int i=0; i<a.length(); i++) {
        while (true) {
            if (cnt[i]==0) {
                cnt[i] = cnt[next[i]];
                s[i] += s[next[i]];
                next[i] = next[next[i]];
                if (cnt[i]!=0) break;
            }
            else break;
        }
    }

    //for (int i=0; i<a.length(); i++) cout<<next[i]<<" "<<cnt[i]<<endl;

    int k = 0;
    int now = 0;
    int tot = 0;
    while (k<=b) {
        k += cnt[now];
        int tmp = s[now];
        int old = now;
        now = next[now];

        if (k<b) {
            tot += tmp;
        }
        else {
            now = old;
            k -= cnt[old];
            break;
        }
    }

    while (k<=b) {
        k += cnt1[now];
        int tmp = 1;
        now = next1[now];

        if (k<b || (k==b && now ==0)) tot += tmp;
    }

    cout<<tot/d<<endl;

    return 0;

}
