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

int n;
int v[30];
unsigned long long m;
string s;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    for (int cas=1; cas<=t; cas++) {
        cin>>s>>m;
        n = s.length();

        if (n==1) {
            string str = "";
            for (int i=0; i<m; i++) {
                str += s[0];
            }
            printf("Case #%d: ", cas);
            cout<<str<<"\n";
        }
        else {
            vector<int> w;
            unsigned long long tmp = n;
            int l = 1;
            while (m>0) {
               if (m<=tmp) break;
               m -= tmp;
               tmp = tmp*n;
               l++;
            }

            cout<<tmp<<" "<<m<<endl;

            string str = "";
            tmp /= n;

            while (tmp>0) {
                if (tmp!=1) str += s[(m-1)/tmp];
                else str += s[m/tmp-1];
                cout<<tmp<<" "<<m<<endl;
                if (m%tmp!=0) m = m%tmp;
                else m = tmp;
                tmp /= n;
                cout<<m<<endl;
            }

            printf("Case #%d: ", cas);
            cout<<str<<"\n";
        }
    }

    return 0;

}
