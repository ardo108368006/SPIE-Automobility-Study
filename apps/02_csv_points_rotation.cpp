#include <iostream>
#include <Eigen/Dense>
#include <scan_matching/csv_reader.hpp>

int main(int argc, char const *argv[]){
    Eigen::Matrix2Xd input_points;
    readPointsFromCsv("../data/retangle_points10.csv", input_points);
    Eigen::Matrix2Xd rot_points;
    //write code for rotating points

    writePointsToCsv("../data/rectangle_points10_rotated.csv", rot_points);
    return 0;    
}