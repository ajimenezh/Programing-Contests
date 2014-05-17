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

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int best = 0;

    for (int i=2; i<1000; i++) {
        int r = 10;
        string s;
        map<int,int> last;
        int k = 0;
        while (true) {
            s += (char)(r/i+'0');
            r = r%i;
            r *= 10;
            if (last.find(r)!=last.end()) {
                best = max(best,k-last[r]);
                if (best==982) cout<<i<<endl;
                break;
            }
            last[r] = k-1;
            k++;
            //cout<<r<<endl;
        }
        //cout<<k-last[r]<<endl;
        //cout<<s<<endl;
    }

    cout<<best<<endl;

    return 0;

}
