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

int n;
int a[5005];

int main() {

	//freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>a[i];
    }

    int best = 0;
    int cnt = 0;
    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            int t = max(j-a[i], 0) + max(i-a[j], 0);
            int p = max(i-a[i], 0) + max(j-a[j], 0);
            if (t<p) {
                cout<<i<<" "<<j<<" "<<p<<" "<<t<<" "<<best<<endl;
                if (p-t>best) {
                    best = p-t;
                    cnt = 0;
                }
                if (p-t==best) cnt++;
            }
        }
    }

    long long tot = 0;
    for (int i=0; i<n; i++) {
        if (a[i]>i) tot += abs(a[i]-i);
    }

    cout<<tot-best<<" "<<cnt<<endl;

	return 0;
}
