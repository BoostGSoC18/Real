#ifndef BOOST_REAL_TEST_HELPERS_HPP
#define BOOST_REAL_TEST_HELPERS_HPP

#include <real/interval.hpp>
#include <real/real.hpp>
#include <real/real_algorithm.hpp>
#include <sstream>

unsigned int boost::real::real::maximum_precision = 10;
unsigned int boost::real::real_algorithm::maximum_precision = 10;

namespace Catch {
    template<>
    struct StringMaker<boost::real::interval> {
        static std::string convert( boost::real::interval const& value ) {
            return value.as_string();

        }
    };
}

namespace Catch {
    template<>
    struct StringMaker<boost::real::real> {
        static std::string convert( boost::real::real const& value ) {
            return value.cend().approximation_interval.as_string();

        }
    };
}

int one_and_nines(unsigned int n) {
    if (n == 0) {
        return 1;
    }
    return 9;
}

int ones(unsigned int n) {
    return 1;
}

int one_one_one(unsigned int n) {
    if (n < 3) {
        return 1;
    }

    return 0;
}

#endif //BOOST_REAL_TEST_HELPERS_HPP
