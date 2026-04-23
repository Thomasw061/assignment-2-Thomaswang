#include <iostream>
#include <cmath>
using namespace std;

double get_number(){
	double num;
	cout << "Enter number one by one cost per, base cost, revenue per" << endl;
	cin >> num;
	return num;
}


int main() {
	double costp = get_number();
	double b = get_number();
	double revp = get_number();
	double N = (b/(revp-costp));


	cout << N << endl;

	return 0;

}
