#include "statistics.hpp"

Mean::Mean() : m_summary{0}, m_n {0}{}

void Mean::update(double next) {
	m_summary += next;
    m_n++;
}

double Mean::eval() const {
	if (m_n == 0) {
        return 0;
    } else {
        return m_summary / m_n;
    }
}

const char * Mean::name() const {
	return "mean";
}