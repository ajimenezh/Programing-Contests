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

int n,m;
int w[100051];

int main() {

	//freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n>>m;
	for (int i=0; i<m; i++) {
        int a,b;
        scanf("%d%d", &a,&b);
        w[i] = b;
	}
    sort(w, w+m);
    reverse(w, w+m);

    int x = 1;
    for (int i=1;; i++) {
        int tot = 0;
        if (i&1) tot = (i*(i-1)/2) + 1;
        else tot = (i*(i-1)/2) + 1 + (i/2-1);
        if (tot>n) {
            x = i-1;
            break;
        }
    }

    int res = 0;
    for (int i=1; i<=x; i++) res += w[i-1];

    cout<<res<<endl;

	return 0;
}
