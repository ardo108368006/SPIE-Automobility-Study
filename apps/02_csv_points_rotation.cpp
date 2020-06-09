#include <iostream>
#include <Eigen/Dense>
#include <scan_matching/csv_reader.hpp>
#include <math.h>
#define PI 3.14159265

int main(int argc, char const *argv[]){
    Eigen::MatrixXd input_points;
    readPointsFromCsv(argv[1], input_points);
    std::cout << "Input\n" << input_points << std::endl;

    Eigen::MatrixXd rot_points;
    //write code for rotating points

    Eigen::MatrixXd rotation(2, 2);
    double degrees = stod(argv[3]);
    rotation << cos(degrees * PI / 180.0), -sin(degrees * PI / 180.0),
                sin(degrees * PI / 180.0), cos(degrees * PI / 180.0);
    
    Eigen::MatrixXd translate(2, 1);
    double translate_x = stod(argv[4]);
    double translate_y = stod(argv[5]);
    translate << translate_x,
                 translate_y;
    
    for(int i = 0; i < input_points.rows(); i++){
        rot_points.conservativeResize(i + 1, input_points.cols());
        rot_points.row(i) = (rotation * input_points.row(i).transpose() + translate).transpose();
    }
    std::cout << "Output\n" << rot_points << std::endl;

    vector<string> label = {"x", "y"};
    writePointsToCsv(argv[2], rot_points, label);
    return 0;    
}