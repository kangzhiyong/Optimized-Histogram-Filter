#include "headers/normalize.h"
#include <numeric>
using namespace std;
vector< vector<float> > normalize(vector< vector <float> > &grid) {
    float total = 0.0;
    int i;
    int j;
    long height = grid.size();
    for (i = 0; i < height; i++)
    {
        total += accumulate(grid[i].begin(), grid[i].end(), 0.0);
    }
    
    for (i = 0; i < height; i++) {
        for (j=0; j< grid[0].size(); j++) {
            grid[i][j] /= total;
        }
    }
    return grid;
}
