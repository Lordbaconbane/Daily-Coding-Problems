/*
Compute the running median of a sequence of numbers. 
That is, given a stream of numbers, print out the median of the list so far on each new element.

Recall that the median of an even-numbered list is the average of the two middle numbers.

For example, given the sequence [2, 1, 5, 7, 2, 0, 5], your algorithm should print out:

2
1.5
2
3.5
2
2
2
*/
#include <iostream>
#include <vector>
#include "problems.h"
#include <algorithm>
#include <stdlib.h>
#include <fstream>

void problem33() {
	std::cout << "Problem #33 takes a stream of numbers and ";
	std::cout << "prints out the median of the list so far on each new element. " << std::endl;
	std::cout << "The default provided list is: [2, 1, 5, 7, 2, 0, 5] " << std::endl;
	std::vector<int> arr = { 2, 1, 5, 7, 2, 0, 5};
	auto n = arr.size();

	// As per the instructions, we have to print for the incoming stream
	// We'll need to have a loop that goes through the array
	for (int i = 0; i < n; i++) {

		// Now that we have a new temp vector, we loop through it to determine the median. 
		std::vector<int> tempVector(arr.begin(), arr.begin()+i+1);
		auto tempSize = tempVector.size();

		// Begin bubble sort
		for (int i = 0; i < tempSize - 1; i++) {
			for (int j = i + 1; j < tempSize; j++) {
				if (tempVector[j] < tempVector[i]) {
					int temp = tempVector[i];
					tempVector[i] = tempVector[j];
					tempVector[j] = temp;
				}
			}
		}
		if (tempSize % 2) {
			//std::cout << "List size is odd\n";
			auto middleIndex = tempVector.size() / 2;
			float median = tempVector[middleIndex];
			std::cout << median << std::endl;
		}
		else if (tempSize % 2 == 0) {
			auto middleIndex = tempVector.size() / 2;
			float middleValue = tempVector[middleIndex - 1];
			float middlePlusOne = tempVector[middleIndex];
			float median = (middleValue + middlePlusOne) / 2;
			std::cout  << median << std::endl;
		}
	}
}
