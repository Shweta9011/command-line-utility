/*
 * compute.cpp
 *
 *  Created on: Jul 31, 2024
 *      Author: Shweta Rajput
 */

#include <iostream>
#include <iomanip>
#include <algorithm>

const int MAX_INPUTS = 100; // Maximum number of lines of input=100 as provided in the problem statement

// Function to parse command-line arguments
//Return true if parsing is successful, false otherwise
bool parseArguments(int argc, char *argv[], double &threshold, double &limit) {
	if (argc != 3) {
		std::cerr << "Error: Incorrect number of arguments. Usage: " << argv[0]
				<< " <threshold> <limit>" << std::endl;
		return false;
	}
	threshold = std::stod(argv[1]);
	limit = std::stod(argv[2]);
	return true;
}

// Function to read input values from standard input
// Returns the number of input values read
int readInputValues(double inputValues[], int maxInputs) {
	int count = 0;
	while (std::cin >> inputValues[count] && count < maxInputs) {
		count++;
	}
	return count;
}

// Function to process input values and produce output
// Applies threshold and limit constraints to each input value
void processValues(const double inputValues[], int count, double threshold,
		double limit) {
	double cumulativeSum = 0.0;
	for (int i = 0; i < count; ++i) {
		double output = std::max(0.0, inputValues[i] - threshold);
		if (cumulativeSum + output > limit) {
			output = limit - cumulativeSum;
		}
		std::cout << std::fixed << std::setprecision(1) << output << std::endl;
		cumulativeSum += output;
	}
	// Output the cumulative sum of all values
	std::cout << std::fixed << std::setprecision(1) << cumulativeSum
			<< std::endl;
}

int main(int argc, char *argv[]) {
	double threshold, limit;
	if (!parseArguments(argc, argv, threshold, limit)) {
		return 1;
	}

	double inputValues[MAX_INPUTS];
	int count = readInputValues(inputValues, MAX_INPUTS);

	processValues(inputValues, count, threshold, limit);

	return 0;
}
