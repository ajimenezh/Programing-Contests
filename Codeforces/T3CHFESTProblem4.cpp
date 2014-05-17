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

struct tree {
   int x;
   tree * l;
   tree * r;
 };

int treeHeight ( tree * T ) {
    int t = 0;
    if (T->l==NULL) {
        if (T->r==NULL) {
            return 0;
        }
        return treeHeight(T->r) + 1;
    }
    else {
        if (T->r==NULL) {
            return treeHeight(T->l) + 1;;
        }
        return max(treeHeight(T->r),treeHeight(T->l)) + 1;
    }

    return 0;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);



    return 0;

}
