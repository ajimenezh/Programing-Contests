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

long long f[20];

long long solve(long long x) {
    long long t = 0;
    f[0] = 1;
    for (int i=1; i<18; i++) f[i] = 10LL*f[i-1];
    for (int i=1; i<10; i++) if (x>=i) t++;
    string s;
    long long tmp = x;
    while (tmp>0) {
        s += char('0'+tmp%10);
        tmp /= 10;
    }
    reverse(s.begin(),s.end());
    for (int i=1; i<10; i++) {
        //cout<<i<<" "<<t<<endl;
        for (int j=0; j<17; j++) {
            if (s.length()>=2+j) {
                if (s.length()>2+j) {
                    t += f[j];
                }
                else {
                    if (s[0]-'0'>i) {
                        t += f[j];
                    }
                    else if (s[0]-'0'==i) {
                        string str = s.substr(1,s.length()-2);
                        long long p = atoll(str.c_str()) + 1;
                        if ((s[s.length()-1]-'0')>=i) t += p;
                        else t += p-1;
                    }
                }
            }
            else break;
        }
    }
    return t;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    long long l,r;
    cin>>l>>r;

    cout<<solve(r)-solve(l-1);

    return 0;

}
