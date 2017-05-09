/*
You want to write a set of classes that simulate different kinds of residences—specifically coops, condos, and houses.
Each instance of a residence should be able to calculate its annual property tax, essentially a product of the residence
 type’s tax rate and the specific residence’s valuation (a function of its price).
You have the following specifications:

• Different residence types have different tax rates.
  - By default, all residence types have a 10% tax rate.
  - Condos have an 18% tax rate.
• Different residence types come up with the valuation differently. 
  - The valuation of a coop is half of the coop’s price, plus another $20,000.
  - The valuation of a condo is 120% of the condo’s price.
  - The valuation of a house is the house’s price, plus another $50,000.

You come up with the following superclass:

class Residence {
 public: 
  static double taxRate() { return 0.10; }
  virtual double annualPropertyTax() { return taxRate()*valuation(); }
  virtual double valuation() = 0;
  double getPrice() { return price; }
  void setPrice(double newPrice) { price = newPrice; }

 protected:
  double price;
};

Please note that static functions—which are class wide, rather than instance specific—cannot also be virtual.
This is because the virtual keyword uses the type of an instance to determine the proper function to call.
However, static functions are not bound to instances, but to the class instead. Nevertheless, static methods can be “redefined.”

1. Is making Residence an abstract base class a reasonable decision? Why or why not?

2. Implement all three subclasses. Do not worry about constructors. You may implement your functions directly
  inside of the class definition.
*/

#include <iostream>
using namespace std;

class Residence {
 public:
  virtual double taxRate() { return 0.10; };

  virtual double annualPropertyTax() { return taxRate() * valuation(); };
  virtual double valuation() = 0;

  double getPrice() { return price; };
  void setPrice(double newPrice) { price = newPrice; };
 
 protected:
  double price;
};

class Coop : public Residence {
 public:
  virtual double valuation() { return price * 0.5 + 20000; };
};

class Condo : public Residence {
 public:
  virtual double taxRate() { return 0.18; };
  virtual double valuation() { return price * 1.2; };
};

class House : public Residence {
 public:
  virtual double valuation() { return price + 50000; };
};

int main() {
  Residence* rptr = new Condo();
  cout << rptr->taxRate() << endl;

  return 0;
}
