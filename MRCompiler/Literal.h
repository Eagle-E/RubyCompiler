#ifndef LITERAL_H
#define LITERAL_H

/*
	Represents an integer or boolean value
*/
class Literal
{
public:
	Literal();
	Literal(int val);
	Literal(const Literal& val);

	void set(int val);
	int value() const;

private:
	int mVal;
};


#endif //LITERAL_H