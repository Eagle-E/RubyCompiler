#include "UnaryNumericNegation.h"

UnaryNumericNegation::UnaryNumericNegation()
    : UnaryNumericOperation()
{

}

UnaryNumericNegation::UnaryNumericNegation(Literal l)
    : UnaryNumericOperation(l)
{

}


/*
Literal UnaryNumericNegation::execute() const
{
    return Literal(-mLiteral.value());
}
*/