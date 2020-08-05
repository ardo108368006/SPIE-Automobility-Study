#include <scan_matching/icp.hpp>

vector<array<int, 2>> nearestNeighborIndics(const Eigen::MatrixXd &P, const Eigen::MatrixXd &Q){
    vector<array<int, 2>> point_couple;
    
    double x_p, y_p, x_q, y_q;

    for(int row_p = 0; row_p < P.rows(); row_p++){
        x_p = P(row_p, 0);
        y_p = P(row_p, 1);
        
        double distance_compare = (P(row_p, 0)-Q(0, 0))*(P(row_p, 0)-Q(0, 0)) + (P(row_p, 1)-Q(0, 1))*(P(row_p, 1)-Q(0, 1));
        int q_index_temp = 0;

        for(int row_q = 0; row_q < Q.rows(); row_q++){
            x_q = Q(row_q, 0);
            y_q = Q(row_q, 1);
            double distance_new = ((x_p-x_q)*(x_p-x_q) + (y_p-y_q)*(y_p-y_q));
            // cout<<distance_compare << " " << distance_new<<endl;

            if(distance_compare > distance_new){
                distance_compare = distance_new;
                q_index_temp = row_q;
            }
        }
        array<int, 2> couple_temp = {row_p, q_index_temp};
        point_couple.push_back(couple_temp);
    }
    // cout << point_couple[0][0] << endl;
    return point_couple;
}