#include "headers/blur.h"
#include "headers/zeros.h"
using namespace std;

// OPTIMIZATION: Pass large variable by reference
vector < vector <float> > blur(vector < vector < float> > &grid, float blurring) {
int height, width, ii, jj;
    height = grid.size();
    width = grid[0].size();
    
    static float center = 1.0 - blurring;
    static float corner = blurring / 12.0;
    static float adjacent = blurring / 6.0;
    static vector < vector <float> > window =  {
        {corner,  adjacent,  center},
        {adjacent, center,  adjacent},
        {corner,  adjacent,  corner}
    };
    static vector <int> DD = {-1, 0, 1};
    vector < vector <float> > newGrid = zeros(height, width);
    
    for (long i=0; i< height; i++ ) {
        for (long j=0; j<width; j++ ) {
            for (ii=0; ii<3; ii++) {
                for (jj=0; jj<3; jj++) {
                    newGrid[(i + DD[ii] + height) % height][(j + DD[jj] + width) % width] += grid[i][j] * window[ii][jj];
                }
            }
        }
    }
    
    return newGrid;
}
