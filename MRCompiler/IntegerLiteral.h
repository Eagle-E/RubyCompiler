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
	void print(string prepend);

private:
	int mVal;
};


#endif // !NUMERICLITERAL_H
