#include "headers/sense.h"

using namespace std;

// OPTIMIZATION: Pass larger variables by reference
vector< vector <float> > sense(char color, vector< vector <char> > &grid, vector< vector <float> > &beliefs,  float p_hit, float p_miss) 
{
	long i, j;
    bool isColor = false;
    for (i=0; i<grid.size(); i++) {
        for (j=0; j<grid[0].size(); j++) {
            isColor = (grid[i][j] == color);
            beliefs[i][j] = beliefs[i][j] * p_hit * isColor + beliefs[i][j] * p_miss * (1 - isColor);
        }
    }
    return beliefs;
}
