#include <Eigen/Dense>

void readPointsFromCsv(const char* csv_path, Eigen::MatrixX2d &points);
void writePointsToCsv(const char* csv_path, Eigen::MatrixX2d &points);