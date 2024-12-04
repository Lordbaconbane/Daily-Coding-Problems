/*Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

For example, given[10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass ? */

#include "problems.h"
#include <iostream>
#include <unordered_set>

bool problem1() {
	std::cout << "Problem #1 takes a list of numbers and a number k and  ";
	std::cout << "returns whether any two numbers from the list add up to k. " << std::endl;
	std::cout << "For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17. " << std::endl;
	int k = 17;
	int arr[5] = { 10, 15, 3, 7 };
	int length = sizeof(arr);
	std::unordered_set<int> seenNumbers;

	// We're using seenNumbers as a storagee for numbers we have seen in the loop.
	// As we iterate through the provided array, we store values in seenNumbers.
	for (int i = 0; i < length; i++) {
		int numToCheck = k - arr[i];
		if (seenNumbers.find(numToCheck) != seenNumbers.end()) {
			std::cout << numToCheck << " and " << arr[i] << " are equal to " << k << std::endl;
			return true;
		}
		seenNumbers.insert(arr[i]);
	}
	std::cout << "No matching values were found to equal to " << k << std::endl;
	return false;
}