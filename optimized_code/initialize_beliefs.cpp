#include "headers/initialize_beliefs.h"

using namespace std;

// OPTIMIZATION: pass large variables by reference
vector< vector <float> > initialize_beliefs(vector< vector <char> > &grid) {
    long height = 0, width = 0;
    height = grid.size();
    if (height > 0 && (width = grid[0].size()) > 0) {
        return vector< vector<float> >(height, vector<float>(width, 1.0 / (height * width)));
    }
    else
    {
        return vector< vector<float> >(height, vector<float>(width, 0.0));
    }
}