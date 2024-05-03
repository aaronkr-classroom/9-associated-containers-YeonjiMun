//fibonacci.cpp
#include <iostream>

using namespace std;

int fibonacci(int n) {

	//±âº» »ç·Ê
	if (n <= 1)
		return 1;
	else
		return fibonacci(n - 1) + fibonacci(n - 2);

}

int main() {
	int num;
	cout << "Enter for a Fibonacci series: ";
	cin >> num;
	cout << "Fibonacci at " << num << " is "
		<< fibonacci(num) << endl;
	return 0;
}