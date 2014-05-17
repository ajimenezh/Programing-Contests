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

int t;
string s;
int n;
int m;
long long res;
char v[5] = {'a','e','i','o','u'};
bool voc(char c) {for (int i=0; i<5; i++) if(c==v[i])return true; return false;}

int main() {

    freopen("C:\\Users\\Alex\\Downloads\\A-large(2).in","r",stdin);
    freopen("output.txt","w",stdout);

    cin>>t;
    for (int tt=0; tt<t; tt++) {
        cin>>s;
        cin>>n;
        m = s.length();
        int c = 0;
        res = 0;
        int last = -1;
        for (int i=0; i<m; i++) {
            if (voc(s[i])) {
                if (c>=n) {
                    res += (long long)((i)-last-c)*(long long)(m-((i-1)));
                    res += (long long)(c-n)*(long long)(((i)-last-c) + (m-((i-1))));
                    res += (long long)(c-n)*(long long)(c-n-1)/2;
                    //cout<<last<<" "<<((i)-last-c)<<endl;
                    last = i-n;
                }
                c = 0;
            }
            else c++;
        }
        if (c>=n) {
            res += (m-last-c);
            res += (long long)(c-n)*(long long)((m-last-c) + 1);
            res += (long long)(c-n)*(long long)(c-n-1)/2;
        }

        printf("Case #%d: %I64d\n",tt+1,res);
    }

    return 0;

}
