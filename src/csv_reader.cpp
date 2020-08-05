#include <scan_matching/csv_reader.hpp>

void readPointsFromCsv(const char* csv_path, Eigen::MatrixXd &points){
    string value;
    ifstream infile(csv_path);

    while(infile.good()){
        getline(infile, value, '\n');

        int cammaTemp = 0;
        vector<double> row_data;
        bool num_checker = 0;

        for(int camma = 0; camma < value.length(); camma++){
            if(int(value[camma]) == 44 || int(value[camma]) == 13){
                
                for(int num_check = cammaTemp; num_check < camma; num_check++){
                    
                    if(!((int(value[num_check]) > 47 && int(value[num_check] < 58)) || int(value[num_check]) == 46 || int(value[num_check]) == 45)){
                        num_checker = 1;
                        break;
                    }
                }
                if(num_checker)
                    break;
                
                row_data.push_back(atof(value.substr(cammaTemp, camma-cammaTemp+1).c_str()));
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

void writePointsToCsv(const char* csv_path, Eigen::MatrixXd &points, vector<string> label){
    ofstream outfile;
    outfile.open(csv_path, ios::out);

    int colsLength = label.size();
    for(int col = 0; col < colsLength; col++){
        outfile << label[col];
        if(col == colsLength-1){
            outfile << char(13) << char(10);
        }else{
            outfile << char(44);
        }
    }

    for(int row = 0; row < points.rows(); row++){
        for(int col = 0; col < points.cols(); col++){
            outfile << points(row, col);
            if(col == points.cols()-1){
                outfile << char(13) << char(10);
            }else{
                outfile << char(44);
            }
        }
    }
    outfile.close();
}  