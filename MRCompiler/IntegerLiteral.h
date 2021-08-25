#ifndef NUMERICLITERAL_H
#define NUMERICLITERAL_H

#include "Literal.h"

class IntegerLiteral : public Literal
{
public:
	IntegerLiteral();
	IntegerLiteral(int val);
	~IntegerLiteral();

	void set(int val);
	int val() const;
	void print();

	Type getType() const;
	Literal* copy() const;
	void print(string prepend);
	bool equals(Literal* other) const;

private:
	int mVal;
};


#endif // !NUMERICLITERAL_H
