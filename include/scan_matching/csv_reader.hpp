#include <Eigen/Dense>
#include<iostream>
#include<fstream>
#include <vector>
using namespace std;

void readPointsFromCsv(const char* csv_path, Eigen::MatrixXd &points);
void writePointsToCsv(const char* csv_path, Eigen::MatrixXd &points, vector<string> label);