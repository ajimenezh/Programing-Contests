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

    int n;
    cin>>n;

    if (n<9) {
//        int k = 0;
//        int f = 1;
//        for (int i=1; i<n; i++) f *= 10;
//        for (int i=f; i<f*10; i++) if (((long long)i*(long long)i)%1000000000LL==987654321) k++;
//        cout<<k<<endl;
        cout<<0<<endl;
    }
    else if (n>9) {
        cout<<9*8;
        for (int i=1; i<(n-9); i++) printf("0");
    }
    else {
//        int k = 0;
//        for (int i=10000000; i<100000000; i++) {
//            if ((long long)i*(long long)i%100000000LL==87654321) {
//                for (int j=1; j<10; j++) {
//                    if ((((long long)i*(long long)i%1000000000LL)/100000000LL + 2*i*j%10)%10==9) {
//                        k++;
//                        //cout<<j*100000000LL + i<<endl;
//                    }
//                }
//            }
//        }
        cout<<8<<endl;
    }

    return 0;

}
