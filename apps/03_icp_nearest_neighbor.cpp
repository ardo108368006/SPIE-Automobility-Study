#include <scan_matching/csv_reader.hpp>
#include <scan_matching/icp.hpp>

int main(int argc, char const *argv[])
{
    Eigen::MatrixXd P;
    readPointsFromCsv(argv[1], P);
    Eigen::MatrixXd Q;
    readPointsFromCsv(argv[2], Q);

    vector<array<int, 2>> points_couple;
    points_couple = nearestNeighborIndics(P, Q);
    
    for(auto couple:points_couple){
        cout << "(" << couple[0] << ", " << couple[1] << ")" << endl;
    }
    
    return 0;
}