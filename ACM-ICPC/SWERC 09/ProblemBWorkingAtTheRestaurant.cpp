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
int cnt1;
int cnt2;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    while (cin>>n && n!=0) {
        cnt1 = 0;
        cnt2 = 0;
        for (int i=0; i<n; i++) {
            string s;
            int m;
            cin>>s>>m;
            if (s[0]=='D') {
                cnt1 += m;
                printf("DROP 1 %d\n",m);
            }
            else {
                if (cnt2>=m) {
                    printf("TAKE 2 %d\n",m);
                    cnt2 -= m;
                }
                else {
                    if (cnt2>0) {
                        printf("TAKE 2 %d\n",cnt2);
                        m -= cnt2;
                    }
                    printf("MOVE 1->2 %d\n",cnt1);
                    cnt2 += cnt1;
                    cnt1 = 0;
                    printf("TAKE 2 %d\n",m);
                    cnt2 -= m;
                }
            }
        }
        printf("\n");
    }

    return 0;

}
