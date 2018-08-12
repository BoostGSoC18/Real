#ifndef BOOST_REAL_INTERVAL_HPP
#define BOOST_REAL_INTERVAL_HPP

#include <vector>

#include <real/boundary.hpp>
#include <real/boundary_helper.hpp>

namespace boost {
    namespace real {

        /**
         * @author Laouen Mayal Louan Belloli
         *
         * @brief Represent an interval composed by two boundaries, a lower boundary and an upper boundary.
         * The boundaries are boost::real::boundary structs that represent fully represented numbers.
         */
        struct interval {
            boost::real::boundary lower_bound;
            boost::real::boundary upper_bound;

            /**
            * @brief *default constructor*: It construct a representation of the interval [0,0].
            */
            interval() = default;

            /**
             * @brief Generates a string representation of the boost::real::interval.
             * The string represent the interval with the format [lower boundary, upper boundary]
             *
             * @return a string that represent the state of the boost::real::interval.
             */
            std::string as_sting() const {

                std::string result = "";
                std::string lb = this->lower_bound.as_string();
                std::string ub = this->upper_bound.as_string();

                if (lb == ub) {
                    result = lb;
                } else {
                    result = '[' + lb + ", " + ub + ']';
                }

                return result;
            }

            /**
             * @brief Swaps the lower boundary with the upper boundary. After this method is called
             * the boost::real::interval boundaries are swaped.
             */
            void swap_bounds() {
                this->lower_bound.swap(this->upper_bound);
            }

            /**
             * @brief Compares two boost::real::interval to determine if *this is a lower interval
             * than other according to the interval arithmetic. *this is lower than other if and
             * only if the upper boundary of this is lower than the lower boundary of other.
             *
             * @param other - a boost::real::interval to compare with *this.
             * @return a bool that is true if and only if *this is lower than other.
             */
            bool operator<(const boost::real::interval& other) const {
                return this->upper_bound < other.lower_bound;
            }

            /**
             * @brief Determine if the interval is fully contained in the positive real number line.
             *
             * @return a bool that is true if and only if both boundaries are positives.
             */
            bool positive() const {
                // If the lower bound of a approximation_interval is positive, then the upper bound is also positive
                // and the approximation_interval is fully contained in the positive number line
                return this->lower_bound.positive;
            }

            /**
             * @brief Determine if the interval is fully contained in the negative real number line.
             *
             * @return a bool that is true if and only if both boundaries are negatives.
             */
            bool negative() const {
                // If the upper bound of a approximation_interval is negative, then the lower bound is also negative
                // and the approximation_interval is fully contained in the negative number line
                return !this->upper_bound.positive;
            }

            /**
             * @brief Equality comparator. Determines if *this is equal or not to other.
             *
             * @param other - a boost::real::interval to compare to *this.
             * @return a bool that is true if and only if *this and equal boundaries are equals.
             */
            bool operator==(const boost::real::interval& other) const {
                return this->lower_bound == other.lower_bound && this->upper_bound == other.upper_bound;
            }

            /**
             * @brief Determines if the interval represent a single number. i.e. the lower and upper
             * boundaries are equals.
             *
             * @return a bool that is true if and only if the interval represent a single number.
             */
            bool is_a_number() const {
                return this->lower_bound == this->upper_bound;
            }
        };
    }
}

std::ostream& operator<<(std::ostream& os, const boost::real::interval& interval) {
    return os << interval.as_sting();
}

#endif //BOOST_REAL_INTERVAL_HPP
