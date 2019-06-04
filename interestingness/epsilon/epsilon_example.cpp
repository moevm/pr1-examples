#include <iostream>
#include <eigen3/Eigen/Geometry>

int main(){
	Eigen::Quaterniond q(-0.999978, 0.0, 0.0, -0.00666627);
	auto euler = q.toRotationMatrix().eulerAngles(0, 1, 2);
        std::cout << "Euler from quaternion in roll, pitch, yaw"<< std::endl << euler << std::endl;
        std::cout<< euler[2] * 180 / M_PI<<std::endl<<std::endl;

	q = Eigen::Quaterniond(-0.999978, 7.68307e-08, 7.68307e-08, -0.00666627);
	euler = q.toRotationMatrix().eulerAngles(0, 1, 2);
	std::cout << "Euler from quaternion in roll, pitch, yaw"<< std::endl << euler << std::endl;
	std::cout<< euler[2] * 180 / M_PI;	




	
	return 0;
}
