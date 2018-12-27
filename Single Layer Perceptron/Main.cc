#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
#include "Perceptron.hpp"


void HabermanSurvivalTest()
{
    cout << "Haberman Training ..." << endl;

     ifstream inFile;
     inFile.open("haberman_train.txt");
     if (!inFile) 
	 {
    	cerr << "Unable to open file datafile.txt";
    	exit(1);   // call system to stop
	 }
	
	 
	 double a,b,c,d;
	 vector<TrainingItem> training_set;
	 while(!inFile.eof())
	 {
	 	inFile>>a>>b>>c>>d;
	 	vector<double> input={a,b,c};
	 	TrainingItem temp(d,input);
	 	training_set.push_back(temp);
	 }
	 inFile.close();


    Perceptron perceptron(3);

    perceptron.train(training_set,1000);
    printf("\nTraining done");

     inFile.open("haberman_test.txt");
     if (!inFile) 
	 {
    	cerr << "Unable to open file datafile.txt";
    	exit(1);   // call system to stop
	 }
	 while(!inFile.eof())
	 {
	 	inFile>>a>>b>>c>>d;
	 	
		if(perceptron.get_result({a,b,c})==d)
	 		printf("\nClassified  correct");
	 	else
	 		printf("\nClassified incorrect");
	 }
	 inFile.close();
	 

    cout << "\n\nSuccessfully trained!" << endl;
    cout << endl;
}

int main(int argc, char **argv)
{

    HabermanSurvivalTest();

    return 0;
}
