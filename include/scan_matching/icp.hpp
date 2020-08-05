#include <Eigen/Dense>
#include <vector>
#include <array>
#include <iostream>
using namespace std;

std::vector<std::array<int, 2>> nearestNeighborIndics(
    const Eigen::MatrixXd &P, const Eigen::MatrixXd &Q);