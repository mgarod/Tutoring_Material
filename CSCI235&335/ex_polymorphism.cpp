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