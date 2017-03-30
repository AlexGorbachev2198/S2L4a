#include <iostream>
#include <math.h>
using namespace std;
class Human_Parametrs
{
protected:
	double Weight;
	double Height;
public:
	Human_Parametrs(double W, double H);
	double Get_W() { return Weight; }
	double Get_H() { return Height; }
	virtual double Index() = 0;
	~Human_Parametrs()
	{
		delete &Weight , &Height;
	}
	Human_Parametrs & operator =(Human_Parametrs& v2)
	{
		Weight = v2.Get_W();;
		Height = v2.Get_H();
		return *this;
	}
};
Human_Parametrs::Human_Parametrs(double W, double H)
{
	Weight = W;
	Height = H;
}

class Do_Bois : public Human_Parametrs
{
public:
	Do_Bois(double W, double H);
	double Human_Parametrs::Index()
	{
		return 0.007184 * pow(Weight, 0.425)*pow(Height, 0.725);
	}
};
Do_Bois::Do_Bois(double W, double H) :
	Human_Parametrs(W, H) {}

class Mosteller : public Human_Parametrs
{
public:
	Mosteller(double W, double H);
	double Human_Parametrs::Index()
	{
		return sqrt(Weight*Height / 3600);
	}
};
Mosteller::Mosteller(double W, double H) : 
	Human_Parametrs(W, H) {}

class Heycock : public Human_Parametrs
{
public:
	Heycock(double W, double H);
	double Human_Parametrs::Index()
	{
		return 0.024265*pow(Weight, 0.5378)*pow(Height, 0.3964);
	}
};
Heycock::Heycock(double W, double H) :
	Human_Parametrs(W, H) {}

int main()
{
	unsigned int n;
	cout << "Input amount of objects:" << endl;
	
	if(cin) cin >> n;
	Human_Parametrs **Data = new Human_Parametrs*[n];
	for (unsigned int i = 0; i < n; ++i) {
		double Height, Weight;
		unsigned int formula = 4;
		cout << "Input height:" << endl;
		if (cin) cin >> Height;
		cout << "Input weight:" << endl;
		if (cin) cin >> Weight;
		cout << "Input type of formula:" << endl;
		if (cin) cin >> formula;
		while (formula > 3) {
			cout << "Please, type again:" << endl;
			if (cin) cin >> formula;
		}
		switch (formula) {
		case 1:
			Data[i] = new Do_Bois(Weight, Height);
			break;
		case 2:
			Data[i] = new Mosteller(Weight, Height);
			break;
		case 3:
			Data[i] = new Heycock(Weight, Height);
			break;
		}
	}
	for (unsigned i = 0; i < n; ++i) {
		cout << Data[i]->Index() << endl;
	}
	system("pause");
	return 0;
}
