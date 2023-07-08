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

Relation *_catersianproduct(Relation *R1, Relation *R2)
{
    vector<string> newschema(R1->attrnames);
    for (int i = 0; i < R2->attrnames.size(); i++)
        newschema.push_back(R2->attrnames[i]);

    Relation *R3 = new Relation(newschema);
    for (list<Record *>::iterator it1 = R1->recs.begin(); it1 != R1->recs.end(); it1++)
    {
        for (list<Record *>::iterator it2 = R2->recs.begin(); it2 != R2->recs.end(); it2++)
        {
            Record *r3record = new Record((*it1)->get_arr());
            r3record->addAttr((*it2)->get_arr());
            R3->addRecord(r3record);
        }
    }
    return R3;
}
Relation *_projection(Relation *R1, list<string> projectattrs)
{
    vector<string> newschema;
    vector<int> schemaidx;
    for (int i = 0; i < R1->attrnames.size(); i++)
    {
        list<string>::iterator it = find(projectattrs.begin(), projectattrs.end(), R1->attrnames[i]);
        if (it != projectattrs.end())
        {
            newschema.push_back(*it);
            schemaidx.push_back(i);
        }
    }
    Relation *R3 = new Relation(newschema);
    for (list<Record *>::iterator it1 = R1->recs.begin(); it1 != R1->recs.end(); it1++)
    {
        Record *r3record = new Record(vector<Attr *>{});
        for (int i = 0; i < schemaidx.size(); i++)
        {
            r3record->addAttr((*it1)->get_arr()[schemaidx[i]]);
        }
        R3->addRecord(r3record);
    }
    return R3;
}
bool check_tuple(Record *ptr, int i, tuple<string, char, Attr *> condition)
{
    Attr *tableattr = ptr->attrptr[i];
    char compare = get<1>(condition);
    Attr *compattr = get<2>(condition);
    switch (compare)
    {
    case '<':
        if ((tableattr[0] < compattr[0]))
            return true;
        return false;
        break;

    case '>':
        if ((tableattr[0] > compattr[0]))
            return true;
        return false;
        break;

    case '=':
        if ((tableattr[0] == compattr[0]))
            return true;
        return false;
        break;

    default:
        break;
    }

    cout << "please give a valid character !!!!" << endl;
}
bool check(Record *ptr, Relation *R1, DNFformula *f)
{
    for (list<list<tuple<string, char, Attr *>>>::iterator it = f->ops.begin(); it != f->ops.end(); it++)
    {
        int flag = 1;
        for (list<tuple<string, char, Attr *>>::iterator it1 = it->begin(); it1 != it->end(); it1++)
        {
            int index = -1;
            for (int i = 0; i < R1->attrnames.size(); i++)
            {
                if (R1->attrnames[i] == get<0>(*it1)){
                    index = i;
                }
            }

            if (check_tuple(ptr, index, (*it1))==0)
                flag = 0;
        }
        if (flag)
            return true;
    }
    return false;
}
Relation *selection(Relation *R1, DNFformula *f)
{
    Relation *res = new Relation(R1->attrnames);
    for (list<Record *>::iterator it = R1->recs.begin(); it != R1->recs.end(); it++)
    {
        if (check(*it, R1, f))
            res->addRecord(*it);
    }
    return res;
}
Relation *difference(Relation *R1, string s1, string s2)
{
    for (int i = 0; i < R1->attrnames.size(); i++)
    {
        if (R1->attrnames[i] == s1)
            R1->attrnames[i] = s2;
    }
    return R1;
}
Relation *naturaljoin(Relation *R1, Relation *R2, list<string> joinattr)
{
    DNFformula *f = new DNFformula;
    DNFformula *dnfformula = new DNFformula;
    for (list<Record *>::iterator it1 = R2->recs.begin(); it1 != R2->recs.end(); it1++)
    {
        list<tuple<string, char, Attr *>> andformula;
        for (list<string>::iterator it = joinattr.begin(); it != joinattr.end(); it++)
        {
            if(find(R1->attrnames.begin(),R1->attrnames.end(),*it)!=R1->attrnames.end()){
                string str = *it;
                char comp = '=';
                Attr *comp_para = (*it1)->get_arr()[(R2->getindex(str))];
                andformula.push_back((make_tuple(str, comp, comp_para)));
                andformula.push_back(make_tuple(str + str, comp, comp_para));
            }
        }
        dnfformula->ops.push_back(andformula);
    }
    for (list<string>::iterator it = joinattr.begin(); it != joinattr.end(); it++)
    {
        if(find(R1->attrnames.begin(),R1->attrnames.end(),*it)!=R1->attrnames.end())
            difference(R2, (*it), (*it) + (*it));
    }

    Relation *cartition_relation = _catersianproduct(R1, R2);
    cartition_relation->print();
    Relation *new_relation = selection(cartition_relation, dnfformula);
    new_relation->print();
    list<string> ls;
    for (int i = 0; i < R1->attrnames.size(); i++)
    {
        ls.push_back(R1->attrnames[i]);
    }
    for (int i = 0; i < R2->attrnames.size(); i++)
    {
        int flag = 1;
        for (list<string>::iterator it = joinattr.begin(); it != joinattr.end(); it++)
        {
            if (*it + *it == R2->attrnames[i]){
                difference(R2, (*it)+ (*it),(*it));
                flag = 0;
            }
        }
        if (flag)
            ls.push_back(R2->attrnames[i]);
    }
    Relation *response = _projection(new_relation, ls);
    return response;
}
