#line 2 "BigO.cpp"
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

int n,m,k;
string f[2010];
int sum[2010];

int main() {

	//freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m>>k;
    for (int i=0; i<n; i++) cin>>f[i];

    for (int i=0; i<n; i++) for (int j=0; j<m; j++) if (f[i][j]!='.') {
        if (f[i][j]=='R') {
            if (j+i<m) sum[j+i]++;
        }
        if (f[i][j]=='L') {
            if (j-i>=0) sum[j-i]++;
        }
        if (f[i][j]=='U' && i%2==0) {
            sum[j]++;
        }
    }

    for (int i=0; i<m; i++) cout<<sum[i]<<" ";

	return 0;
}
