#include <scan_matching/csv_reader.hpp>
#include<iostream>
#include<fstream>
using namespace std;

void readPointsFromCsv(const char* csv_path, Eigen::MatrixX2d &points){
    string value;
    ifstream infile(csv_path);
    
    double x, y;
    while(infile.good()){
        //.csv檔案用","作為分隔符
        getline(infile,value,'\n');
        for(int txt = 0; txt < value.length(); txt++){
            if(value[txt] == ','){
                if(value.substr(0, txt) != "x" && value.substr(txt+1, value.length()) != "y"){
                    x = ::atof(value.substr(0, txt).c_str());
                    y = ::atof(value.substr(txt+1, value.length()).c_str());
                    cout << value.substr(0, txt) <<endl;
                    
                }
                break;
            }
        }
    }
}

void writePointsToCsv(const char* csv_path, Eigen::MatrixX2d &points){

}