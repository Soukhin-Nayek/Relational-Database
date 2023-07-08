#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <cmath>
#include <tuple>
#include <set>
using namespace std;
#include "rdb.h"
Attr::Attr(string type) : type(type) {}
integerAttr& integerAttr:: operator=(const integerAttr &s)
{
    if (this != &s)
    {
        this->val_int = s.val_int;
    }
    return *this;
}
integerAttr:: integerAttr(int val) : val_int(val), Attr("integer") {}
Attr* integerAttr::clone(void)
{

    integerAttr *res = dynamic_cast<integerAttr *>(this);
    return res;
}
void integerAttr::print() { printf("%15d|", this->val_int); };
bool integerAttr::operator==(const Attr &right)
{
    if (this->val_int == dynamic_cast<const integerAttr &>(right).val_int)
        return true;
    else
        return false;
}
bool integerAttr::operator!=(const Attr &right)
{
    if (this->val_int != dynamic_cast<const integerAttr &>(right).val_int)
        return true;
    else
        return false;
}
bool integerAttr::operator<(const Attr &right)
{
    if (this->val_int < dynamic_cast<const integerAttr &>(right).val_int)
        return true;
    else
        return false;
}
bool integerAttr::operator<=(const Attr &right)
{
    if (this->val_int <= dynamic_cast<const integerAttr &>(right).val_int)
        return true;
    else
        return false;
}
bool integerAttr::operator>(const Attr &right)
{
    if (this->val_int > dynamic_cast<const integerAttr &>(right).val_int)
        return true;
    else
        return false;
}
bool integerAttr::operator>=(const Attr &right)
{
    if (this->val_int >= dynamic_cast<const integerAttr &>(right).val_int)
        return true;
    else
        return false;
}
floatAttr& floatAttr ::operator=(const floatAttr &s)
{
    if (this != &s)
    {
        this->val_float = s.val_float;
    }
    return *this;
}
floatAttr ::floatAttr(float val) : val_float(val), Attr("float") {}
void floatAttr ::print() { printf("%15f|", this->val_float); };
Attr* floatAttr ::clone(void)
{

    floatAttr *res = dynamic_cast<floatAttr *>(this);
    return res;
}
bool floatAttr ::operator==(const Attr &right)
{
    if (this->val_float == dynamic_cast<const floatAttr &>(right).val_float)
        return true;
    else
        return false;
}
bool floatAttr ::operator!=(const Attr &right)
{
    if (this->val_float != dynamic_cast<const floatAttr &>(right).val_float)
        return true;
    else
        return false;
}
bool floatAttr ::operator<(const Attr &right)
{
    if (this->val_float < dynamic_cast<const floatAttr &>(right).val_float)
        return true;
    else
        return false;
}
bool floatAttr ::operator<=(const Attr &right)
{
    if (this->val_float <= dynamic_cast<const floatAttr &>(right).val_float)
        return true;
    else
        return false;
}
bool floatAttr ::operator>(const Attr &right)
{
    if (this->val_float > dynamic_cast<const floatAttr &>(right).val_float)
        return true;
    else
        return false;
}
bool floatAttr ::operator>=(const Attr &right)
{
    if (this->val_float >= dynamic_cast<const floatAttr &>(right).val_float)
        return true;
    else
        return false;
}

stringAttr& stringAttr ::operator=(const stringAttr &s)
{
    if (this != &s)
    {
        this->val_string = s.val_string;
    }
    return *this;
}
stringAttr::stringAttr(string str) : val_string(str), Attr("string") {}
void stringAttr::print() { printf("%15s|", this->val_string.c_str()); };
Attr* stringAttr::clone(void)
{

    stringAttr *res = dynamic_cast<stringAttr *>(this);
    return res;
}
bool stringAttr ::operator==(const Attr &right)
{
    if (this->val_string == dynamic_cast<const stringAttr &>(right).val_string)
        return true;
    else
        return false;
}
bool stringAttr ::operator!=(const Attr &right)
{
    if (this->val_string != dynamic_cast<const stringAttr &>(right).val_string)
        return true;
    else
        return false;
}
bool stringAttr ::operator<(const Attr &right)
{
    if (this->val_string < dynamic_cast<const stringAttr &>(right).val_string)
        return true;
    else
        return false;
}
bool stringAttr ::operator<=(const Attr &right)
{
    if (this->val_string <= dynamic_cast<const stringAttr &>(right).val_string)
        return true;
    else
        return false;
}
bool stringAttr ::operator>(const Attr &right)
{
    if (this->val_string > dynamic_cast<const stringAttr &>(right).val_string)
        return true;
    else
        return false;
}
bool stringAttr ::operator>=(const Attr &right)
{
    if (this->val_string >= dynamic_cast<const stringAttr &>(right).val_string)
        return true;
    else
        return false;
}
