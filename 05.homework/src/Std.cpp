#include "statistics.hpp"
#include <cmath>

Std::Std() : m_mean{Mean()}, m_doubles{0}, m_n {0}{}

void Std::update(double next) {
	m_mean.update(next);
    m_doubles.push_back(next);
    m_n++;
    next++;
}

double Std::eval() const {

    if (m_n == 0) {
        return 0;
    }

	double mean = m_mean.eval();
    double summary = 0;
    for(int i = 0; i < m_doubles.size(); i++) {
        summary += std::pow(m_doubles.at(i) - mean, 2);
    }

    return std::sqrt(summary / m_n);
}

const char * Std::name() const {
	return "std";
}