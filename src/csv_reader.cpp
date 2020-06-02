#include <scan_matching/csv_reader.hpp>
#include<iostream>
#include<fstream>
using namespace std;

void readPointsFromCsv(const char* csv_path, Eigen::MatrixX2d &points){
    string value;
    ifstream infile(csv_path);
    
    while(infile.good()){
        getline(infile,value,'\n');
        for(int txt = 0; txt < value.length(); txt++){
            if(value[txt] == ','){
                if(value.substr(0, txt) != "x" && value.substr(txt+1, value.length()) != "y"){
                    double x = ::atof(value.substr(0, txt).c_str());
                    double y = ::atof(value.substr(txt+1, value.length()).c_str());
                    
                    int pt_size;
                    pt_size = points.rows();
                    points.conservativeResize(pt_size+1, 2);
                    points.row(pt_size) << x, y;
                }
                break;
            }
        }
    }
    infile.close();
}

void writePointsToCsv(const char* csv_path, Eigen::MatrixX2d &points){

}