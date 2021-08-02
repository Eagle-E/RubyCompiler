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
	enum class Type {INT, BOOL};

	static bool sameType(Literal* l1, Literal* l2);

	virtual ~Literal();

	virtual Type getType() const = 0;

	// function for debugging
	virtual void print(string prepend) = 0;

private:
};


#endif //LITERAL_H