#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class ParkedCar
{
private:
	string make;
	string model;
	string color;
	string Number;
	int minute;
public:
	ParkedCar()
	{
		make = "toyota";
		model = "Figo";
		color = "black";
		Number = "12345678";
		minute = 10;
	}
	ParkedCar(string make, string model, string color, string Number, int minute);
	void setMake(string);
	void setModel(string);
	void setColor(string);
	void setLicenseNumber(string);
	void setMinutesParked(int);
	string getMake()const;
	string getModel()const;
	string getColor()const;
	string getLicenseNumber()const;
	int getMinutesParked()const;
};
ParkedCar::ParkedCar(string make1, string model1, string color1, string Number1, int minute1)
{
	make = make1;
	model = model1;
	color = color1;
	Number = Number1;
	minute = minute1;
}
void ParkedCar::setMake(string make1) {
	make = make1;
}
void ParkedCar::setModel(string model1) {
	model = model1;
}
void ParkedCar::setColor(string color1) {
	color = color1;
}
void ParkedCar::setLicenseNumber(string Number1) {
	Number = Number1;
}
void ParkedCar::setMinutesParked(int minute1) {
	minute = minute1;
}
string ParkedCar::getMake()const {
	return make;
}
string ParkedCar::getModel()const {
	return model;
}
string ParkedCar::getColor()const {
	return color;
}
string ParkedCar::getLicenseNumber() const {
	return Number;
}
int ParkedCar::getMinutesParked()const {
	return minute;
}
class ParkingMeter
{
	ParkedCar pc;
	int minutesPurchased;

public:
	ParkingMeter(ParkedCar car, int minutes);
	void setMinutesPurchased(int m) { minutesPurchased = m; }
	int getMinutesPurchased() { return minutesPurchased; }
	void setParkedCar(ParkedCar p) { pc = p; }
	ParkedCar getParkedCar() { return pc; }
};
ParkingMeter::ParkingMeter(ParkedCar car1, int minutes1) {
	pc = car1;
	minutesPurchased = minutes1;
}
class PoliceOfficer
{
	string policeName;
	string badgeNumber;
	int min3;
	int min4;

public:
	PoliceOfficer() {
		policeName = "fiveStar";
		badgeNumber = "12345678";
		min3 = 0;
		min4 = 0;
	}
	PoliceOfficer(string name, string num, ParkingMeter  min, ParkedCar min1)
	{
		policeName = name;
		badgeNumber = num;
		min3 = min1.getMinutesParked();
		min4 = min.getMinutesPurchased();

	}
	void setPoliceName(string name) { policeName = name; }
	void setBadgeNumber(int num) { badgeNumber = num; }
	string getPoliceName() { return policeName; }
	string getBadgeNumber() { return badgeNumber; }
	int jisuan() {

		int x = min4 - min3;
		if (x > 0)
		{
			cout << "this car illegally parked" << endl;
			return x;
		}
		else
		{
			cout << "Parking Ticket not required." << endl;
			return x;
		}
	}

};
class ParkingTicket
{
	ParkedCar car;
	PoliceOfficer police;
	int fineMinutes;
public:
	ParkingTicket(ParkedCar pc, PoliceOfficer po, int min)
	{
		car = pc;
		police = po;
		fineMinutes = min;
	}
	int calculateFineAmount()
	{
		if (fineMinutes <= 60)
			return 25;
		else
		{
			return 25 + ceil((fineMinutes - 60) / 60.0) * 10;
		}
	}
};
int main() {
	string make;
	string model;
	string color;
	string license;
	string name;
	int min;
	string number;
	int parkedminutes;
	int puchasedminutes;

	cout << " what is car make ?" << endl;
	cin >> make;
	cout << " what is car make ?" << endl;
	cin >> make;
	cout << " what is car model ?" << endl;
	cin >> model;
	cout << " what is car color ?" << endl;
	cin >> color;
	cout << " what is car license ?" << endl;
	cin >> license;
	cout << " what is car parked minutes ?" << endl;
	cin >> parkedminutes;
	cout << " Enter the name of police officer" << endl;
	cin >> name;
	cout << " what is police officer number ?" << endl;
	cin >> number;
	cout << " Enter the no of minutes puchased for parking" << endl;
	cin >> puchasedminutes;

	ParkedCar car1(make, model, color, license, parkedminutes);
	ParkingMeter car2(car1, puchasedminutes);
	PoliceOfficer po(name, number, car2, car1);
	ParkingTicket car3(car1, po, puchasedminutes - parkedminutes);
	cout << "car make:  ";
	cout << car1.getMake() << endl;
	cout << "car model:  ";
	cout << car1.getModel() << endl;
	cout << "car color:  ";
	cout << car1.getColor() << endl;
	cout << "car license:  ";
	cout << car1.getLicenseNumber() << endl;
	cout << "car parked minutes:  ";
	cout << car1.getMinutesParked() << endl;
	cout << "police officer :  ";
	cout << po.getPoliceName() << endl;
	cout << "police officer number:  ";
	cout << po.getBadgeNumber() << endl;
	cout << " minutes puchased for parking:  ";
	cout << car2.getMinutesPurchased() << endl;
	if (po.jisuan() > 0) {
		//cout << "this car illegally parked" << endl;
		return 0;
	}
	if (po.jisuan() < 0) {
		//cout << "Parking Ticket not required." << endl;
		cout << " should take money:  ";
		cout << car3.calculateFineAmount() << endl;
		return 0;
	}


}

