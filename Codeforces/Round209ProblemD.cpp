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
int a[300010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) scanf("%d", a+i);

    for (int i=0; i<n; i++) {
        if (a[i]==1) {
            cout<<"1 "<<n-1<<endl;
            cout<<1<<endl;
            return 0;
        }
    }

    vector<int> ans;
    int best = 0;
    for (int i=0; i<n;) {
        int l = i, r = i;
        for (int j=i+1; j<n; j++) {
            if (a[j]%a[i]==0) r++;
            else break;
        }
        for (int j=i-1; j>=0; j--) {
            if (a[j]%a[i]==0) l--;
            else break;
        }
        if (r-l>best) {
            best = r-l;
            ans.clear();
        }
        if (r-l==best) {
            ans.push_back(l+1);
        }
        i = r+1;
    }

    if (best==-1) {
        cout<<n<<" "<<0<<endl;
        for (int i=0; i<n; i++) cout<<i+1<<" ";
    }
    else {
        cout<<ans.size()<<" "<<best<<endl;
        for (int i=0; i<ans.size(); i++) cout<<ans[i]<<" ";
    }

    return 0;
}
