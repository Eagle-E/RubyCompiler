#ifndef LITERAL_H
#define LITERAL_H

/*
	Represents an integer or boolean value
*/
class Literal
{
public:
	static bool sameType(Literal& l1, Literal& l2);

	virtual ~Literal();

private:
};


#endif //LITERAL_H