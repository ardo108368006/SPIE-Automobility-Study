#include <iostream>
#include <Eigen/Dense>
#include <scan_matching/csv_reader.hpp>

int main(int argc, char const *argv[]){
    Eigen::MatrixX2d input_points;
    readPointsFromCsv("../data/rectangle_points10.csv", input_points);
    // std::cout << input_points << std::endl;
    Eigen::MatrixX2d rot_points;
    //write code for rotating points

    writePointsToCsv("../data/rectangle_points10_rotated.csv", rot_points);
    return 0;    
}