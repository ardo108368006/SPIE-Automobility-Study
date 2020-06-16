#include <scan_matching/csv_reader.hpp>
#include <math.h>
#define PI 3.14159265

int main(int argc, char const *argv[]){
    Eigen::MatrixXd input_points;
    readPointsFromCsv(argv[1], input_points);
    std::cout << "Input\n" << input_points << std::endl;

    input_points.conservativeResize(input_points.rows(), 3);
    for(int i = 0; i < input_points.rows(); i++){
        input_points(i, 2) = 1;
    }
    
    Eigen::MatrixXd rot_points;
    //write code for rotating points

    Eigen::MatrixXd RT(3,3);
    double degrees = stod(argv[3])* PI / 180.0;
    double translate_x = stod(argv[4]);
    double translate_y = stod(argv[5]);

    RT << cos(degrees), -sin(degrees), translate_x,
          sin(degrees),  cos(degrees), translate_y,
                     0,            0,           1;
    
    rot_points = (RT*input_points.transpose()).transpose();
    rot_points.conservativeResize(rot_points.rows(), 2);
    std::cout << "Output\n" << rot_points << std::endl;

    vector<string> label = {"x", "y"};
    writePointsToCsv(argv[2], rot_points, label);
    return 0;    
}