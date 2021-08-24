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

	virtual ~Literal();

	virtual Type getType() const;
	virtual Literal* copy() const;

	// function for debugging
	virtual void print(string prepend);

private:
};



#endif //LITERAL_H