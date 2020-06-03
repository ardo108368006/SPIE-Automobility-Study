#include <scan_matching/csv_reader.hpp>
#include<iostream>
#include<fstream>
#include <vector>
using namespace std;

void readPointsFromCsv(const char* csv_path, Eigen::MatrixX2d &points){
    string value;
    ifstream infile(csv_path);

    while(infile.good()){
        getline(infile, value, '\n');
        int cammaTemp = 0;
        vector<double> row_data;
        bool num_checker = 0;
        
        for(int camma = 0; camma < value.length(); camma++){
            if(int(value[camma]) == 44 || int(value[camma])==13){
                for(int num_check = cammaTemp; num_check < camma; num_check++){
                    if((int(value[num_check]) < 48 || int(value[num_check] > 57)) && int(value[num_check]) != 46){
                        num_checker = 1;
                        break;
                    }
                }
                if(num_checker)
                    break;
                row_data.push_back(atof(value.substr(cammaTemp, camma).c_str()));
                cammaTemp = camma + 1;
            }
        }
        if(!num_checker && row_data.size() > 0){
            int pt_size;
            pt_size = points.rows();

            points.conservativeResize(pt_size + 1, row_data.size());
            for(int element = 0; element < row_data.size(); element++){
                points(pt_size, element) = row_data[element];
            }
        }
    }
    infile.close();
}

void writePointsToCsv(const char* csv_path, Eigen::MatrixX2d &points){
    //  FILE *outfile;
    //  outfile = fopen(csv_path, "a");

}  