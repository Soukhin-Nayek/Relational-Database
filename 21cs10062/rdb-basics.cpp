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

vector<Attr *>Record:: get_arr(void)
{
    return attrptr;
}
Record::Record(vector<Attr *> schema)
{
    for (int i = 0; i < schema.size(); i++)
        attrptr.push_back(schema[i]->clone());
}
Record::Record(const Record &s)
{
    for (int i = 0; i < s.attrptr.size(); i++)
        attrptr.push_back(s.attrptr[i]->clone());
}
Record& Record::operator=(const Record &s)
{
    if (this != &s)
    {
        this->attrptr.clear();
        for (int i = 0; i < s.attrptr.size(); i++)
            this->attrptr[i] = s.attrptr[i]->clone();
    }
    return *this;
}
void Record::print()
{
    printf("|");
    for (int i = 0; i < attrptr.size(); i++)
    {
        attrptr[i]->print();
    }
    printf("\n");
}
void Record::addAttr(Attr *ptr)
{
    attrptr.push_back(ptr->clone());
    return;
}
void Record::addAttr(vector<Attr *> ptr)
{
    for (int i = 0; i < ptr.size(); i++)
    {
        attrptr.push_back(ptr[i]->clone());
    }
    return;
}
bool Record::operator==(const Record &right)
{
    if (this->attrptr.size() != right.attrptr.size())
        return false;
    for (int i = 0; i < right.attrptr.size(); i++)
    {
        if (*(this->attrptr[i]) == *(right.attrptr[i]))
            continue;
        return false;
    }
    return true;
}
int Relation::getindex(string &str)
{
    for (int i = 0; i < attrnames.size(); i++)
        if (attrnames[i] == str)
            return i;
    return -1;
}
Relation::Relation(vector<string> schema) : nattr(schema.size()), nrecs(0)
{
    attrnames.resize(nattr);
    for (int i = 0; i < attrnames.size(); i++)
    {
        attrnames[i] = schema[i];
    }
}
void Relation::addRecord(Record *ptr)
{
    recs.push_back(new Record(*ptr));
    nrecs++;
    return;
}
void Relation::addRecord(Relation *ptr)
{
    for (list<Record *>::iterator it = ptr->recs.begin(); it != ptr->recs.end(); it++)
    {
        this->addRecord(*it);
    }
}
bool Relation::find(Record *ptr)
{
    for (list<Record *>::iterator it = this->recs.begin(); it != this->recs.end(); it++)
    {
        if (ptr[0] == (**it))
            return true;
    }
    return false;
}
void Relation::print()
{
    cout<<endl;
    for (int i = 0; i < nattr * 16 + 1; i++)
        printf("_");
    printf("\n");
    printf("|");
    for (int i = 0; i < nattr; i++)
        printf("%15s|", attrnames[i].c_str());
    printf("\n");
    for (int i = 0; i < nattr * 16 + 1; i++)
        printf("_");
    printf("\n");
    for (list<Record *>::iterator it = this->recs.begin(); it != this->recs.end(); it++)
        (*it)->print();
    for (int i = 0; i < nattr * 16 + 1; i++)
        printf("_");
    printf("\n");
}

Relation *_union(Relation *R1, Relation *R2)
{
Relation *R3 = new Relation(R1->attrnames);
R3->addRecord(R1);
R3->print();
R3->addRecord(R2);
R3->print();
return R3;
}

Relation *_difference(Relation *R1, Relation *R2)
{
Relation *R3 = new Relation(R1->attrnames);
for (list<Record *>::iterator it = R1->recs.begin(); it != R1->recs.end(); it++)
{
    if (R2->find(*it) == 0)
        R3->addRecord(*it);
}
return R3;
}
