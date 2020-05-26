#include <iostream>
#include <Eigen/Dense>

using namespace std;

int main(int argc, char const *argv[])
{
    Eigen::Vector2d a(5.0, 6.0);
    Eigen::Vector2d b(2.0, 8.0);
    cout << (a + b).transpose() << endl;
    return 0;
}