#include <iostream>


class Energy
{
public:
	Energy(double out_Joules) :Joules(out_Joules) {}
	//{
	//	Joules = out_Joules;
		//add_Joules(out_Joules)
	//}
	double get_Joules()
	{
		return Joules;
	}
	double get_Electron_Volts()
	{
		return Joules * EV;
	}
	double get_Ergs()
	{
		return Joules * E;
	}
	//void add_Joules(double out_Joules)
	//{
	//	Joules = out_Joules;
	//}
	void add_Electron_Volts(double out_Electron_Volts)
	{
		Joules = out_Electron_Volts / EV;
	}
	void add_Ergs(double out_Ergs)
	{
		Joules = out_Ergs / E;
	}


private:
	double Joules;
	static inline const double EV = 6.24e18;
	static inline const double E = 1e7;
};





int main() {
	Energy w = 10;
	std::cout << w.get_Joules() << '\n';
	std::cout << w.get_Ergs() << '\n';
	std::cout << w.get_Electron_Volts() << '\n';

	return 0;
}