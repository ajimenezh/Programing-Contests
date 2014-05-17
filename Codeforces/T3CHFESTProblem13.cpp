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

int min_count_of_knight_moves ( int A,int B ) {
    int x = A, y = B;
    int res = 100000100;
    bool possible = false;

    int now;
    for (int i=-1; i<=1; i+=2) {
        for (int j=-1; j<=1; j+=2) {
            for (int k=-1; k<=1; k+=2) {
                for (int l=-1; l<=1; l+=2) {

                    int b = 2*x - k/j*y;
                    int a = -1;
                    if (b%(4*i-k*j/l)!=0 || b<0) now = -1;
                    else {
                        b = b/(4*i-k*j/l);
                        a = (x - 2*i*b)/k;
                        if (b<0 || a<0) now = -1;
                        else now = (a+b);
                    }
                    //cout<<a<<" "<<b<<" ";
                    if (now!=-1) possible = true;
                    if (now!=-1) res = min(res,now);
                    //cout<<now<<endl;

                }
            }

        }
    }

    if (!possible) return -1;
    return res<=100000000 ? res : -2;
}



int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    while (true) {
        int a,b;
        cin>>a>>b;
        cout<<min_count_of_knight_moves (a,b)<<endl;
    }

    return 0;

}
