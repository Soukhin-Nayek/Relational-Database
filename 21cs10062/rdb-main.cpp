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
// #ifndef ONLINE_JUDGE
//     freopen("input.txt","r",stdin); 
//     freopen("output.txt","w",stdout);
// #endif
// class Attr;
// class Record;
// class Relation;
// struct DNFformula
// {
//     list<list<tuple<string, char, Attr *>>> ops;
// };
// class Attr
// {
// protected:
//     string type;
// public:
//     Attr(string type) : type(type) {}
//     virtual void print() = 0;
//     virtual Attr *clone(void) = 0;
//     virtual bool operator==(const Attr &right) = 0;
//     virtual bool operator!=(const Attr &right) = 0;
//     virtual bool operator<(const Attr &right) = 0;
//     virtual bool operator<=(const Attr &right) = 0;
//     virtual bool operator>(const Attr &right) = 0;
//     virtual bool operator>=(const Attr &right) = 0;
// };
// class integerAttr : public Attr
// {
// private:
//     int val_int;
//     integerAttr &operator=(const integerAttr &s)
//     {
//         if (this != &s)
//         {
//             this->val_int = s.val_int;
//         }
//         return *this;
//     }
// public:
//     integerAttr(int val) : val_int(val), Attr("integer") {}
//     Attr *clone(void)
//     {
//         integerAttr *res = dynamic_cast<integerAttr *>(this);
//         return res;
//     }
//     void print() { printf("%15d|", this->val_int); };
//     bool operator==(const Attr &right)
//     {
//         if (this->val_int == dynamic_cast<const integerAttr &>(right).val_int)
//             return true;
//         else
//             return false;
//     }
//     bool operator!=(const Attr &right)
//     {
//         if (this->val_int != dynamic_cast<const integerAttr &>(right).val_int)
//             return true;
//         else
//             return false;
//     }
//     bool operator<(const Attr &right)
//     {
//         if (this->val_int < dynamic_cast<const integerAttr &>(right).val_int)
//             return true;
//         else
//             return false;
//     }
//     bool operator<=(const Attr &right)
//     {
//         if (this->val_int <= dynamic_cast<const integerAttr &>(right).val_int)
//             return true;
//         else
//             return false;
//     }
//     bool operator>(const Attr &right)
//     {
//         if (this->val_int > dynamic_cast<const integerAttr &>(right).val_int)
//             return true;
//         else
//             return false;
//     }
//     bool operator>=(const Attr &right)
//     {
//         if (this->val_int >= dynamic_cast<const integerAttr &>(right).val_int)
//             return true;
//         else
//             return false;
//     }
// };
// class floatAttr : public Attr
// {
// private:
//     float val_float;
//     floatAttr &operator=(const floatAttr &s)
//     {
//         if (this != &s)
//         {
//             this->val_float = s.val_float;
//         }
//         return *this;
//     }
// public:
//     floatAttr(float val) : val_float(val), Attr("float") {}
//     void print() { printf("%15f|", this->val_float); };
//     Attr *clone(void)
//     {
//         floatAttr *res = dynamic_cast<floatAttr *>(this);
//         return res;
//     }
//     bool operator==(const Attr &right)
//     {
//         if (this->val_float == dynamic_cast<const floatAttr &>(right).val_float)
//             return true;
//         else
//             return false;
//     }
//     bool operator!=(const Attr &right)
//     {
//         if (this->val_float != dynamic_cast<const floatAttr &>(right).val_float)
//             return true;
//         else
//             return false;
//     }
//     bool operator<(const Attr &right)
//     {
//         if (this->val_float < dynamic_cast<const floatAttr &>(right).val_float)
//             return true;
//         else
//             return false;
//     }
//     bool operator<=(const Attr &right)
//     {
//         if (this->val_float <= dynamic_cast<const floatAttr &>(right).val_float)
//             return true;
//         else
//             return false;
//     }
//     bool operator>(const Attr &right)
//     {
//         if (this->val_float > dynamic_cast<const floatAttr &>(right).val_float)
//             return true;
//         else
//             return false;
//     }
//     bool operator>=(const Attr &right)
//     {
//         if (this->val_float >= dynamic_cast<const floatAttr &>(right).val_float)
//             return true;
//         else
//             return false;
//     }
// };
// class stringAttr : public Attr
// {
// private:
//     string val_string;
//     stringAttr &operator=(const stringAttr &s)
//     {
//         if (this != &s)
//         {
//             this->val_string = s.val_string;
//         }
//         return *this;
//     }
// public:
//     stringAttr(string str) : val_string(str), Attr("string") {}
//     void print() { printf("%15s|", this->val_string.c_str()); };
//     Attr *clone(void)
//     {
//         stringAttr *res = dynamic_cast<stringAttr *>(this);
//         return res;
//     }
//     bool operator==(const Attr &right)
//     {
//         if (this->val_string == dynamic_cast<const stringAttr &>(right).val_string)
//             return true;
//         else
//             return false;
//     }
//     bool operator!=(const Attr &right)
//     {
//         if (this->val_string != dynamic_cast<const stringAttr &>(right).val_string)
//             return true;
//         else
//             return false;
//     }
//     bool operator<(const Attr &right)
//     {
//         if (this->val_string < dynamic_cast<const stringAttr &>(right).val_string)
//             return true;
//         else
//             return false;
//     }
//     bool operator<=(const Attr &right)
//     {
//         if (this->val_string <= dynamic_cast<const stringAttr &>(right).val_string)
//             return true;
//         else
//             return false;
//     }
//     bool operator>(const Attr &right)
//     {
//         if (this->val_string > dynamic_cast<const stringAttr &>(right).val_string)
//             return true;
//         else
//             return false;
//     }
//     bool operator>=(const Attr &right)
//     {
//         if (this->val_string >= dynamic_cast<const stringAttr &>(right).val_string)
//             return true;
//         else
//             return false;
//     }
// };
// class Record
// {
// private:
//     vector<Attr *> attrptr;
// public:
//     vector<Attr *> get_arr(void)
//     {
//         return attrptr;
//     }
//     Record(vector<Attr *> schema)
//     {
//         for (int i = 0; i < schema.size(); i++)
//             attrptr.push_back(schema[i]->clone());
//     }
//     Record(const Record &s)
//     {
//         for (int i = 0; i < s.attrptr.size(); i++)
//             attrptr.push_back(s.attrptr[i]->clone());
//     }
//     Record &operator=(const Record &s)
//     {
//         if (this != &s)
//         {
//             this->attrptr.clear();
//             for (int i = 0; i < s.attrptr.size(); i++)
//                 this->attrptr[i] = s.attrptr[i]->clone();
//         }
//         return *this;
//     }
//     void print()
//     {
//         printf("|");
//         for (int i = 0; i < attrptr.size(); i++)
//         {
//             attrptr[i]->print();
//         }
//         printf("\n");
//     }
//     void addAttr(Attr *ptr)
//     {
//         attrptr.push_back(ptr->clone());
//         return;
//     }
//     void addAttr(vector<Attr *> ptr)
//     {
//         for (int i = 0; i < ptr.size(); i++)
//         {
//             attrptr.push_back(ptr[i]->clone());
//         }
//         return;
//     }
//     bool operator==(const Record &right)
//     {
//         if (this->attrptr.size() != right.attrptr.size())
//             return false;
//         for (int i = 0; i < right.attrptr.size(); i++)
//         {
//             if (*(this->attrptr[i]) == *(right.attrptr[i]))
//                 continue;
//             return false;
//         }
//         return true;
//     }
//     friend bool check_tuple(Record *ptr, int i, tuple<string, char, Attr *> condition);
//     friend Relation *naturaljoin(Relation *R1, Relation *R2, list<string> joinattr);
//     friend class Relation;
// };
// class Relation
// {
// private:
//     // storing a relation
//     int nattr, nrecs;         // number of attributes and records
//     vector<int> attrinds;     // mapping schema to indices
//     list<Record *> recs;      // list of records
//                               // methods
// public:
//     vector<string> attrnames; // schema
//     int getindex(string &str)
//     {
//         for (int i = 0; i < attrnames.size(); i++)
//             if (attrnames[i] == str)
//                 return i;
//         return -1;
//     }
//     Relation(vector<string> schema) : nattr(schema.size()), nrecs(0)
//     {
//         attrnames.resize(nattr);
//         for (int i = 0; i < attrnames.size(); i++)
//         {
//             attrnames[i] = schema[i];
//         }
//     }
//     void addRecord(Record *ptr)
//     {
//         recs.push_back(new Record(*ptr));
//         nrecs++;
//         return;
//     }
//     void addRecord(Relation *ptr)
//     {
//         for (list<Record *>::iterator it = ptr->recs.begin(); it != ptr->recs.end(); it++)
//         {
//             this->addRecord(*it);
//         }
//     }
//     bool find(Record *ptr)
//     {
//         for (list<Record *>::iterator it = this->recs.begin(); it != this->recs.end(); it++)
//         {
//             if (ptr[0] == (**it))
//                 return true;
//         }
//         return false;
//     }
//     void print()
//     {
//         cout<<endl;
//         for (int i = 0; i < nattr * 16 + 1; i++)
//             printf("_");
//         printf("\n");
//         printf("|");
//         for (int i = 0; i < nattr; i++)
//             printf("%15s|", attrnames[i].c_str());
//         printf("\n");
//         for (int i = 0; i < nattr * 16 + 1; i++)
//             printf("_");
//         printf("\n");
//         for (list<Record *>::iterator it = this->recs.begin(); it != this->recs.end(); it++)
//             (*it)->print();
//         for (int i = 0; i < nattr * 16 + 1; i++)
//             printf("_");
//         printf("\n");
//     }
//     friend Relation *_union(Relation *R1, Relation *R2);
//     friend Relation *_difference(Relation *R1, Relation *R2);
//     friend bool check(Record *ptr, Relation *R1, DNFformula *f);
//     friend Relation *_catersianproduct(Relation *R1, Relation *R2);
//     friend Relation *_projection(Relation *R1, list<string> projectattrs);
//     friend Relation *difference(Relation *R1, string s1, string s2);
//     friend Relation *naturaljoin(Relation *R1, Relation *R2, list<string> joinattr);
//     friend Relation *selection(Relation *R1, DNFformula *f);
// };
// Relation *_union(Relation *R1, Relation *R2)
// {
//     Relation *R3 = new Relation(R1->attrnames);
//     R3->addRecord(R1);
//     R3->print();
//     R3->addRecord(R2);
//     R3->print();
//     return R3;
// }
// Relation *_difference(Relation *R1, Relation *R2)
// {
//     Relation *R3 = new Relation(R1->attrnames);
//     for (list<Record *>::iterator it = R1->recs.begin(); it != R1->recs.end(); it++)
//     {
//         if (R2->find(*it) == 0)
//             R3->addRecord(*it);
//     }
//     return R3;
// }
// Relation *_catersianproduct(Relation *R1, Relation *R2)
// {
//     vector<string> newschema(R1->attrnames);
//     for (int i = 0; i < R2->attrnames.size(); i++)
//         newschema.push_back(R2->attrnames[i]);
//     Relation *R3 = new Relation(newschema);
//     for (list<Record *>::iterator it1 = R1->recs.begin(); it1 != R1->recs.end(); it1++)
//     {
//         for (list<Record *>::iterator it2 = R2->recs.begin(); it2 != R2->recs.end(); it2++)
//         {
//             Record *r3record = new Record((*it1)->get_arr());
//             r3record->addAttr((*it2)->get_arr());
//             R3->addRecord(r3record);
//         }
//     }
//     return R3;
// }
// Relation *_projection(Relation *R1, list<string> projectattrs)
// {
//     vector<string> newschema;
//     vector<int> schemaidx;
//     for (int i = 0; i < R1->attrnames.size(); i++)
//     {
//         list<string>::iterator it = find(projectattrs.begin(), projectattrs.end(), R1->attrnames[i]);
//         if (it != projectattrs.end())
//         {
//             newschema.push_back(*it);
//             schemaidx.push_back(i);
//         }
//     }
//     Relation *R3 = new Relation(newschema);
//     for (list<Record *>::iterator it1 = R1->recs.begin(); it1 != R1->recs.end(); it1++)
//     {
//         Record *r3record = new Record(vector<Attr *>{});
//         for (int i = 0; i < schemaidx.size(); i++)
//         {
//             r3record->addAttr((*it1)->get_arr()[schemaidx[i]]);
//         }
//         R3->addRecord(r3record);
//     }
//     return R3;
// }
// bool check_tuple(Record *ptr, int i, tuple<string, char, Attr *> condition)
// {
//     Attr *tableattr = ptr->attrptr[i];
//     char compare = get<1>(condition);
//     Attr *compattr = get<2>(condition);
//     switch (compare)
//     {
//     case '<':
//         if ((tableattr[0] < compattr[0]))
//             return true;
//         return false;
//         break;
//     case '>':
//         if ((tableattr[0] > compattr[0]))
//             return true;
//         return false;
//         break;
//     case '=':
//         if ((tableattr[0] == compattr[0]))
//             return true;
//         return false;
//         break;
//     default:
//         break;
//     }
//     cout << "please give a valid character !!!!" << endl;
// }
// bool check(Record *ptr, Relation *R1, DNFformula *f)
// {
//     for (list<list<tuple<string, char, Attr *>>>::iterator it = f->ops.begin(); it != f->ops.end(); it++)
//     {
//         int flag = 1;
//         for (list<tuple<string, char, Attr *>>::iterator it1 = it->begin(); it1 != it->end(); it1++)
//         {
//             int index = -1;
//             for (int i = 0; i < R1->attrnames.size(); i++)
//             {
//                 if (R1->attrnames[i] == get<0>(*it1)){
//                     index = i;
//                 }
//             }
//             if (check_tuple(ptr, index, (*it1))==0)
//                 flag = 0;
//         }
//         if (flag)
//             return true;
//     }
//     return false;
// }
// Relation *selection(Relation *R1, DNFformula *f)
// {
//     Relation *res = new Relation(R1->attrnames);
//     for (list<Record *>::iterator it = R1->recs.begin(); it != R1->recs.end(); it++)
//     {
//         if (check(*it, R1, f))
//             res->addRecord(*it);
//     }
//     return res;
// }
// Relation *difference(Relation *R1, string s1, string s2)
// {
//     for (int i = 0; i < R1->attrnames.size(); i++)
//     {
//         if (R1->attrnames[i] == s1)
//             R1->attrnames[i] = s2;
//     }
//     return R1;
// }
// Relation *naturaljoin(Relation *R1, Relation *R2, list<string> joinattr)
// {
//     DNFformula *f = new DNFformula;
//     DNFformula *dnfformula = new DNFformula;
//     for (list<Record *>::iterator it1 = R2->recs.begin(); it1 != R2->recs.end(); it1++)
//     {
//         list<tuple<string, char, Attr *>> andformula;
//         for (list<string>::iterator it = joinattr.begin(); it != joinattr.end(); it++)
//         {
//             if(find(R1->attrnames.begin(),R1->attrnames.end(),*it)!=R1->attrnames.end()){
//                 string str = *it;
//                 char comp = '=';
//                 Attr *comp_para = (*it1)->get_arr()[(R2->getindex(str))];
//                 andformula.push_back((make_tuple(str, comp, comp_para)));
//                 andformula.push_back(make_tuple(str + str, comp, comp_para));
//             }
//         }
//         dnfformula->ops.push_back(andformula);
//     }
//     for (list<string>::iterator it = joinattr.begin(); it != joinattr.end(); it++)
//     {
//         if(find(R1->attrnames.begin(),R1->attrnames.end(),*it)!=R1->attrnames.end())
//             difference(R2, (*it), (*it) + (*it));
//     }
//     Relation *cartition_relation = _catersianproduct(R1, R2);
//     cartition_relation->print();              
//     Relation *new_relation = selection(cartition_relation, dnfformula);
//     new_relation->print();
//     list<string> ls;
//     for (int i = 0; i < R1->attrnames.size(); i++)
//     {
//         ls.push_back(R1->attrnames[i]);
//     }
//     for (int i = 0; i < R2->attrnames.size(); i++)
//     {
//         int flag = 1;
//         for (list<string>::iterator it = joinattr.begin(); it != joinattr.end(); it++)
//         {
//             if (*it + *it == R2->attrnames[i]){
//                 difference(R2, (*it)+ (*it),(*it));
//                 flag = 0;
//             }
//         }
//         if (flag)
//             ls.push_back(R2->attrnames[i]);
//     }
//     Relation *response = _projection(new_relation, ls);
//     return response;
// }

Attr *get_attr(string s)
{
    if (s == "integer")
    {
        int x;
        cin >> x;
        return new integerAttr(x);
    }
    if (s == "float")
    {
        float x;
        cin >> x;
        return new floatAttr(x);
    }
    if (s == "string")
    {
        string x;
        cin >> x;
        return new stringAttr(x);
    }
}
Relation *inputRelation(void)
{
    cout << "\n- - : : creating a new table : : - -" ;
    int nattr, nrecs;
    cout << "Please enter number of rows : " << endl;
    cin >> nrecs;
    cout << "Please enter number of colomn : " << endl;
    cin >> nattr;
    vector<string> schema_name(nattr), schema_type(nattr);
    cout << "please enter the schema name and type(integer/float/string): " << endl;
    for (int i = 0; i < nattr; i++)
    {
        cout << "Schema " << i + 1 << " name : ";
        cin >> schema_name[i];
        cout << "Schema " << i + 1 << " type(integer/float/string) : ";
        cin >> schema_type[i];
    }

    Relation *relation = new Relation(schema_name);
    cout << "now please enter the records : " << endl;
    for (int i = 0; i < nrecs; i++)
    {
        vector<Attr *> attrptr;
        for (int j = 0; j < nattr; j++)
        {
            cout << "enter " << j + 1 << " attribute of " << i + 1 << " record( " << schema_type[j] << " ): ";
            Attr *ptr = get_attr(schema_type[j]);
            attrptr.push_back(ptr);
        }
        relation->addRecord(new Record(attrptr));
    }
    // relation->print();
    return relation;
}

vector<Relation *> arr(10);
int i = 0;

int main()
{
    /*
    • Create	a new	empty table:	the	user	can	interactively	enter	the	schema.
• Delete	an	existing	table	with	all	data	in	it.
• Add	a	record	to	a	table.
• Print	a table	in	appropriate	format.
• Create	a	table	from	existing	tables	using	the	above	developed	operations.
    */
    // Relation* R1 = inputRelation();
    // Relation* R2 = inputRelation();
    while (1)
    {
        cout << "0-> quit" << endl;
        cout << "1-> add a new table" << endl;
        cout << "2-> delete table" << endl;
        cout << "3-> add a record to a table" << endl;
        cout << "4-> print a table" << endl;
        cout << "5-> creating a table from a existing table" << endl;
        int choice,x,y,subswitch,sz;
        cout << "\nenter your choice : ";
        cin >> choice;
        list<string> lt;
        set<string> st;

        switch (choice)
        {
        case 0:
            exit(0);
        case 1:
            arr[i++] = inputRelation();
            break;
        case 2:
            cout << "Enter the index of the table to delete : " << endl;
            cin >> x;
            delete arr[x];
            while (x < i - 1)
            {
                arr[x] = arr[x + 1];
            }
            i--;
            break;
        case 3:
            cout << "Enter the index of the table to add record : " << endl;
            cin >> x;
            break;
        case 4:
            cout<<"Printing the table -->"<<endl;
            for (int j = 0; j < i; j++)
            {
                cout<<"\nTable at the index "<<j<<" is -"<<endl;
                arr[j]->print();
            }
            break;
        case 5:
            cout<<"Enter what operation you want to perform-->"<<endl;
            cout<<"50-->union of two relation "<<endl;
            cout<<"51-->difference of two relation"<<endl;
            cout<<"52-->cartesion product of two relation"<<endl;
            cout<<"53-->naturaljoin of two relation"<<endl;
            cout<<"Enter your choice: ";
            cin>>subswitch;
            cout<<"Enter the index of the element ";
            cin>>x>>y;
            switch (subswitch)
            {
            case 50:
                arr[i++]= _union(arr[x],arr[y]);
                break;
            
            case 51:
                arr[i++]= _difference(arr[x],arr[y]);
                break;
            case 52:
                arr[i++]= _catersianproduct(arr[x],arr[y]);
                break;
            case 53:
                for(auto it:arr[x]->attrnames)
                    st.insert(it);
                for(auto it:arr[y]->attrnames){
                    sz = st.size();
                    st.insert(it);
                    if(sz==st.size())
                        lt.push_back(it);    
                }
                arr[i++] = naturaljoin(arr[x],arr[y],lt);
                break;
            default:
                break;
            }
        
        default:
            break;
        }
    }
    return 0;
}