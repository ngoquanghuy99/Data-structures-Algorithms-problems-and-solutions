
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include <math.h>
using namespace std;
#define N 1000000
int output [8];
vector <int> validBoard [1000];
int vIndex = 0;

int column [8];
int diag1 [30];
int diag2 [30];

void bktk (int row){
    if ( row == 8 ){
        for ( int i = 0; i < 8; i++ ){
            validBoard [vIndex].push_back (output [i]);
        }
        vIndex++;
        return;
    }

    for ( int i = 0; i < 8; i++ ) {
        if ( column [i] == 0 && diag1 [row + i] == 0 && diag2 [row - i + 8] == 0 ){
            column [i] = diag1 [row + i] = diag2 [row - i + 8] = 1;
            output [row] = i;
            bktk (row + 1);
            column [i] = diag1 [row + i] = diag2 [row - i + 8] = 0;
        }
    }
}

int main (){
    bktk (0);
    int k;
    scanf ("%d", &k);
    int board [8] [8];
    while ( k-- ){
        for ( int i = 0; i < 8; i++ )
            for ( int j = 0; j < 8; j++ )
                scanf ("%d", &board [i] [j]);
        int max = 0;
        int count;
        for ( int i = 0; i < vIndex; i++ ){
            count = 0;
            for ( int j = 0; j < 8; j++ )
                count += board [j] [validBoard [i] [j]];
            if ( count > max )
                max = count;
        }
        printf ("%d\n", max);
    }
    return 0;
}
