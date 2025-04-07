#include <iostream>
using namespace std;

int main () {
	
	float consumption;
	const float kWh = 11.51;
	float previousElectricBill, currentElectricBill;
	float electricbill;

    cout << "Previous Electric Bill" << endl;
	cout << "Enter your previous electicity consumption in kWh: ";
	cin >> consumption; 
	
	previousElectricBill = consumption * kWh;
	
	cout << "Electricity Consumption: " << consumption << "kWh" << endl;
    cout << "kWh: " << kWh << "kWh" << endl;
	cout << "Total Previous Electric Bill: PHP. " << previousElectricBill << endl;

	
    cout << "Current Electric Bill" << endl;
	cout << "Enter your current electicity consumption in kWh: ";
	cin >> consumption; 
	
	currentElectricBill = consumption * kWh;
	
	
    cout << "Electricity Consumption: " << consumption << "kWh" << endl;
    cout << "kWh: " << kWh << "kWh" << endl;
	cout << "Total Current Electric Bill: PHP. " << currentElectricBill << endl;
	
	electricbill  =  previousElectricBill - currentElectricBill;
	
	cout << "The difference of you previous electrical bill and current electrical bill is PHP. " << electricbill << endl;
	
	if (previousElectricBill > currentElectricBill) {
		cout << "Your current electrical bill is lower than your previous electrical bill. There's a PHP." << electricbill << " difference. Congratulations your saving money and electricity!" << endl;
	} else if (previousElectricBill > currentElectricBill) {
		cout << "Your current electrical bill is higher than your previous electrical bill. There's a PHP." << electricbill << " difference. Please mind your energy usage to save money" << endl;	
	} else {
		cout << "Your current electrical bill is the same as your previous electric bill. There's no change in your electricital bill" << endl;
	}
	
	return 0;
}
