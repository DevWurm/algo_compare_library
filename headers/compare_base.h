/*
 * compare_base.h
 *
 *  Created on: 14.04.2015
 *      Author: leo
 */

#ifndef HEADERS_COMPARE_BASE_H_
#define HEADERS_COMPARE_BASE_H_

#include <string>
#include <chrono>
#include <istream>

using std::string;
using std::chrono::steady_clock;
using std::istream;

namespace compare {


template<typename T>
class compare_base {
private:
	T data;
	T result_algorithm_1;
	T result_algorithm_2;
	string type;
	steady_clock::duration operation_time_algorithm_1;
	steady_clock::duration operation_time_algorithm_2;
public:
	compare_base(); //standard constructor
	compare_base(const T& input); //copy constructor from type

	compare_base<T>& operator=(const T& input); //assign operator from type

	virtual void algorithm_1 (const T& input, T& result) = 0; //interface for implementing algorithm 1
	virtual void algorithm_2 (const T& input, T& result) = 0; //interface for implementing algorithm 2

	void compare_algorithms(); //compare algorithms
	void compare_algorithms_verbose(istream& output); //compare algorithms and write status information into output

	void set_data(const T& input); //set data from type

	T get_data() const; //get data as type
	T get_result_algorithm_1() const; //get result of algorithm 1
	T get_result_algorithm_2() const; //get result of algorithm 2
	string get_type() const; //get type
	steady_clock::duration get_operation_time_algorithm_1(string unit) const; //get operation time as duration
	steady_clock::duration get_operation_time_algorithm_1() const; //get operation time as duration (milliseconds)
	steady_clock::duration get_operation_time_algorithm_2(string unit) const; //get operation time as duration
	steady_clock::duration get_operation_time_algorithm_2() const; //get operation time as duration (milliseconds)
	string get_operation_time_algorithm_1_string(string unit) const; //get operation time as string
	string get_operation_time_algorithm_1_string() const; //get operation time as string (milliseconds)
	string get_operation_time_algorithm_2_string(string unit) const; //get operation time as string
	string get_operation_time_algorithm_2_string() const; //get operation time as string (milliseconds)

	bool vaildate_results(); //check if results of the algorithms are equal

	virtual ~compare_base();

};


}
#endif /* HEADERS_COMPARE_BASE_H_ */
