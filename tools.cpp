#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
  TODO:
    * Calculate the RMSE here.
  */
  
	int eSize=estimations.size(),gSize=ground_truth.size();
   // printf("%d\n",eSize);	
	VectorXd rmse(4); //x,y,x',y'
	rmse << 0,0,0,0;

	// TODO: YOUR CODE HERE

	// check the validity of the following inputs:
	//  * the estimation vector size should not be zero
	//  * the estimation vector size should equal ground truth vector size
	// ... your code here
	
	if((eSize != gSize )|| eSize == 0){
		cout << "Invalid estimation or ground_truth data" << endl;
		return rmse;
	}



	//accumulate squared residuals
	for(unsigned int i=0; i < eSize; ++i){

		VectorXd residual = estimations[i] - ground_truth[i];

		//coefficient-wise multiplication
		residual = residual.array()*residual.array();
		rmse += residual;
	}

	//calculate the mean
	rmse = rmse/eSize;

	//calculate the squared root
	rmse = rmse.array().sqrt();

	//return the result
	return rmse;
}