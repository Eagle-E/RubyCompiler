#ifndef BOOLEANLITERAL_H
#define BOOLEANLITERAL_H

#include "Literal.h"

class BooleanLiteral : public Literal
{
public:
	BooleanLiteral();
	BooleanLiteral(bool val);
	~BooleanLiteral();

	void set(bool val);
	bool val() const;
	void print();

	Type getType() const;

private:
	bool mVal;
};


#endif // !NUMERICLITERAL_H
