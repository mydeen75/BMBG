#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

//problem
//•	Given an array of real numbers, find the average of all the numbers except the minimum and maximum

//questions to ask
//is the array going to be static? or will there be additions/deletions in the future

//special case int arr[] = {1.2, 1.2, 1.2, 1.3, 1.3, 1.3}
//then it is better to traverse the array skipping the min and the max
int main() {
	vector<float> realNums;
	realNums.push_back(1.2);
	realNums.push_back(0.2);
	realNums.push_back(2.5);
	realNums.push_back(4.22);
	realNums.push_back(3.1);

	std::sort(std::begin(realNums), std::end(realNums));
	long double sum = std::accumulate(std::begin(realNums)+1, std::end(realNums)-1, 0.0);
	long double avg = sum / (realNums.size()-2);
	cout << "sum:" << sum << " Avg:" <<   avg << "\n";

}

