#include <iostream>
#include <cmath>
using namespace std;



double get_number(){
        double num;
        cout << "Enter num, n1, p1, k1, n2, p2, k2, n3, p3, k3"<< endl;
        cin >> num;
        return num;
}




int main() {
	double n1 = get_number();
	double p1 = get_number();
	double k1 = get_number();
	double n2 = get_number();
	double p2 = get_number();
	double k2 = get_number();
	double n3 = get_number();
	double p3 = get_number();
	double k3 = get_number();

	double m1num = k3-n3+((n3-n2+k2-k3)*((p3-n3)/(n2-n3+p3-p2)));
	double m1dem = k3-n3+n1-k1+((n3-n2+k2-k3)*((n1-n3+p3-p1)/(n2-n3+p3-p2)));

	double m1 = (m1num/m1dem);

	double m2num = p3-n3-m1*(n1-n3+p3-p1);
	double m2 = (m2num)/(n2-n3+p3-p2);	

	double m3 = (1-m1-m2);

	double pni = (m1*n1+m2*n2+m3*n3);
	double pph = (m1*p1+m2*p2+m3*p3);
	double ppo = (m1*k1+m2*k2+m3*k3);
	cout << m1 << ", " << m2 << ", " << m3 << endl;
	cout << pni << ", " << pph << ", " << ppo << endl;

	return 0;
}
