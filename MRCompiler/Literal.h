#ifndef LITERAL_H
#define LITERAL_H

#include <string>
using std::string;

/*
	Represents an integer or boolean value
*/
class Literal
{
public:
	enum class Type {INT, BOOL, NIL};

	static bool sameType(Literal* l1, Literal* l2);

	virtual ~Literal();

	virtual Type getType() const;

	// function for debugging
	virtual void print(string prepend);

private:
};



#endif //LITERAL_H