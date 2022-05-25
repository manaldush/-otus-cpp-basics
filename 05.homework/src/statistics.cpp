#include <iostream>
#include <limits>
#include <vector>
#include "statistics.hpp"
#include <algorithm>
#include <chrono>
#include <random>

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& values) {
	for (auto iter = values.cbegin(); iter != values.cend(); ++iter) {
		if (iter != values.cbegin())
			os << ' ';
		os << *iter;
	}
	return os;
}

template<typename T>
void make_random_shuffle(std::vector<T>& values) {
	// 1. Take current time (count of seconds since `epoch begining`) as a seed
	auto seconds_count = std::chrono::system_clock::now().time_since_epoch().count();
	unsigned int seed = static_cast<unsigned int>(seconds_count);
	// 2. Initialize random engine
	std::default_random_engine engine{seed};
	// 3. Shuffle values
	std::shuffle(values.begin(), values.end(), engine);
}

void deleteStatistics(std::vector<IStatistics*>& stats)
{
    for (int i = 0; i < stats.size(); i++) {
        delete stats.at(i);
    }
}

int main() {
	std::vector<IStatistics*> stats;
	stats.push_back(new Min());
	stats.push_back(new Max());
	stats.push_back(new Mean());
	stats.push_back(new Std());

	std::vector<double> doubles;

	double data;
	while (std::cin >> data) {
		doubles.push_back(data);
	}

	// Handle invalid input data
	if (!std::cin.eof() && !std::cin.good()) {
		std::cerr << "Invalid input data\n";
		return 1;
	}

	make_random_shuffle(doubles);
	std::cout << "Randomized data = {" << doubles << "}" <<std::endl;

	for (int i = 0; i < doubles.size(); i++) {
		double d = doubles.at(i);
		for (int i = 0; i < stats.size(); i++) {
			stats.at(i)->update(d);
		}
	}

	for (int i = 0; i < stats.size(); i++) {
		IStatistics* stat = stats.at(i);
		std::cout << stat->name() << "  =  " << stat->eval() << std::endl;
	}

	deleteStatistics(stats);

	return 0;
}