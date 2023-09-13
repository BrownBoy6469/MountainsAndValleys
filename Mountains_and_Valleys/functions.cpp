#include <iostream>
#include "functions.h"

using std::cout, std::endl;

bool is_valid_range(int a, int b) {
	if(10 <= a and a <= b and b < 10000) {
		return true;
	}
	else {
		return false;
	}
}

char classify_mv_range_type(int number) {
	// TODO(student): return 'M' if number has /\/\... pattern,
	// return 'V' if number has \/\/ pattern, and return 'N' otherwise

	char temp_type = 'N'; 
	if(number / 10 == 0) {
		return 'N';
	}
	int digit3 = number % 10; // Note, digit3 is intialized as the digit furthest to the right
	number /= 10;
	int digit2 = number % 10; //Note, digit2 is the digit to the left of digit3
	number /= 10;

	if(digit2 < digit3) {
		temp_type = 'M';
	}
	else if(digit2 > digit3) {
		temp_type = 'V';
	}
	else {
		return 'N';
	}

	while(number != 0) {
		int digit1 = number % 10; // Note, digit1 is the digit to the left of digit2
		if(digit1 < digit2 and digit2 > digit3) {
			temp_type = 'M';
		}
		else if(digit1 > digit2 and digit2 < digit3) {
			temp_type = 'V';
		}
		else {
			return 'N';
		}
		digit3 = digit2;
		digit2 = digit1;
		number /= 10;
	}
	return temp_type;
}

void count_valid_mv_numbers(int a, int b) {
	int m_count = 0;
	int v_count = 0;
	for(int i = a; i <= b; i++) {
		char type = classify_mv_range_type(i);
		if(type == 'M') {
			m_count += 1;
		}
		else if(type == 'V') {
			v_count += 1;
		}
	}
	cout << "There are " << m_count << " mountain ranges and " << v_count << 
	" valley ranges between " << a << " and " << b << "." << endl;
}