#include <iostream>

using namespace std;

enum signType {positive, negative};

class currency {
  friend ostream& operator<<(ostream&, const currency&);
  public:
    //constructor
    currency(signType theSign = positive, 
             unsigned long theDollers = 0,
             unsigned int theCents = 0);

    // destructor
    ~currency() {}
    void setValue(signType, unsigned long, unsigned int);
    void setValue(double);
    signType getSign() const { return sign; } 
    unsigned long getDollers() const { return dollers; }
    unsigned int getCents() const { return cents; }
    currency operator+(const currency& x) const;
    currency& operator+=(const currency&);
    void output(ostream& out) const;
  private:
    signType sign;         // sign of object
    unsigned long dollers; // number of dollers
    unsigned int cents;    // numbers of cents
};

currency::currency(signType theSign, unsigned long theDollers, unsigned int theCells) {
  // Create a currency object
  setValue(theSign, theDollers, theCells);
}

void currency::setValue(signType theSign, unsigned long theDollers, unsigned int theCents) {
  //Set currency value
  if(theCents > 99) {
    // too many cents
    //throw IllegalParameterValue("Cents should be < 100");
  }
  sign = theSign;
  dollers = theDollers;
  cents = theCents;
}

void currency::setValue(double theAmount) {
  // set currency value
  if(theAmount < 0) {
    sign = negative;
    theAmount = -theAmount;
  }else {
    sign = positive;
  }

  dollers = (unsigned long) theAmount;
  cents = (unsigned int) ((theAmount + 0.001 - dollers) * 100); // get two decimal digits.
}

currency currency::operator+(const currency& x) const {
  // add x to *this.
  long a1, a2, a3;
  currency result;

  // convert invoking object to signed integers
  a1 = dollers * 100 + cents;
  if (sign == negative) a1 = -a1;

  // convert x into signed integer
  a2  = x.dollers * 100 + x.cents;
  if (x.sign == negative) a2 = -a2;

  a3 = a1 + a2;

  // convert to currency representation
  if(a3 < 0) {
    result.sign = negative;
    a3 = -a3;
  }else {
    result.sign = positive;
  }

  result.dollers = a3/100;
  result.cents = a3 - result.dollers*100;

  return result;
}

currency& currency::operator+=(const currency& x) {
  // increment by x
  *this = *this + x;
  return *this;
}

void currency::output(ostream& out) const {
  // Output the currency value
  if(sign == negative) out << "-";
  out << "$" << dollers << ".";
  if(cents < 10) out << "0";
  out << cents << endl;
}

ostream& operator<<(ostream& out, const currency& x) {
  x.output(out);
  return out;
}