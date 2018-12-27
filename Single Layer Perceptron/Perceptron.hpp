#ifndef PERCEPTRON_HPP
#define PERCEPTRON_HPP
#include <vector>
#include <numeric>
#include <fstream>
#include<iostream>
#include <stdexcept>
using namespace std;
#include "TrainingItem.hpp"

class Perceptron
{
	
  private:
  double learning_rate_;
  double threshold_;
  vector<double> weights_;
  
  
  
  public:
  Perceptron (int input_count, const double learning_rate = 1.0, const double threshold = 0.5): weights_(input_count)  {
    learning_rate_ = learning_rate;
    threshold_ = threshold;
  }


  void train(vector<TrainingItem> & training_set, unsigned int max_iterations)
  {

    unsigned int iterations(0);
    while (true) {
        if (iterations > max_iterations)
            break;
        else
            iterations++;

        int error_count = 0;
    
			
        for (auto& item : training_set) {
            int output = learn(item.output(), item.inputs());

            if (output != item.output())
                error_count++;
        }

        if (error_count == 0)
            break;
    }
  }

  int get_result(const vector<double> &inputs)
  {

    return ((dot_product(inputs, weights_) > threshold_)+1);
  }

  int learn(int expected_result, const vector<double> &inputs)
  {
//  	 ofstream outFile;
//     outFile.open("F:\\Soft computing\\weight.txt",ios_base::app);
//     if (!outFile) 
//	 {
//    	cerr << "Unable to open file datafile.txt";
//    	exit(1);   // call system to stop
//	 }
	 
    int result = get_result(inputs);
    if (result != expected_result) 
	{
    	
        double error = (expected_result) -(result );
        for (int i = 0; i < weights_.size(); i++) 
		{
            weights_[i] += learning_rate_ * error * inputs[i];
            //outFile<<weights_[i];
        }
        //outFile<<"\n";
    }
    //outFile.close();

    return result;
  }

  double dot_product(const vector<double> &v1,const vector<double> &v2)
  {
      return inner_product(v1.begin(), v1.end(), v2.begin(), 0);
  }

};

#endif // PERCEPTRON_HPP
