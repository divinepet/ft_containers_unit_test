#pragma once
#include "../system/lib.hpp"

template <class T>
void run_vector_unit_test(std::string test_name, std::vector<int> (func1)(std::vector<T>), std::vector<int> (func2)(_vector<T>)) {
    time_t t1;
    time_t t2;
    std::vector<int > res1;
    std::vector<int > res2;
    std::vector<int> vector;
    _vector<int> my_vector;

	printElement(test_name);
	res1 = func1(vector);
	res2 = func2(my_vector);
	(res1 == res2) ? printElement("OK") : printElement("FAILED");
	t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;
	(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);
	(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);
	leaks_test(getpid());
	cout << endl;
}

template <class T, class A>
void run_vector_allocator_unit_test(std::string test_name, void (func)(_vector<T, A>)) {
    time_t t1;
    time_t t2;
    _vector<T, A> my_vector;

    printElement(test_name);
    func(my_vector);
    (_allocator_used) ? printElement("OK") : printElement("FAILED");
    cout << endl;
}