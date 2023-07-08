
class Attr;
class Record;
class Relation;
struct DNFformula
{
    list<list<tuple<string, char, Attr *>>> ops;
};

class Attr
{
protected:
    string type;

public:
    Attr(string type);
    virtual void print() = 0;
    virtual Attr *clone(void) = 0;
    virtual bool operator==(const Attr &right) = 0;
    virtual bool operator!=(const Attr &right) = 0;
    virtual bool operator<(const Attr &right) = 0;
    virtual bool operator<=(const Attr &right) = 0;
    virtual bool operator>(const Attr &right) = 0;
    virtual bool operator>=(const Attr &right) = 0;
};

class integerAttr : public Attr
{
private:
    int val_int;
    integerAttr &operator=(const integerAttr &s);

public:
    integerAttr(int val);
     void print() ;
     Attr *clone(void) ;
     bool operator==(const Attr &right) ;
     bool operator!=(const Attr &right) ;
     bool operator<(const Attr &right) ;
     bool operator<=(const Attr &right) ;
     bool operator>(const Attr &right) ;
     bool operator>=(const Attr &right);
 };
class floatAttr : public Attr
{
private:
    float val_float;
    floatAttr &operator=(const floatAttr &s);

public:
    floatAttr(float val);
     void print() ;
     Attr *clone(void) ;
     bool operator==(const Attr &right) ;
     bool operator!=(const Attr &right) ;
     bool operator<(const Attr &right) ;
     bool operator<=(const Attr &right) ;
     bool operator>(const Attr &right) ;
     bool operator>=(const Attr &right);
 };
class stringAttr : public Attr
{
private:
    string val_string;
    stringAttr &operator=(const stringAttr &s);

public:
    stringAttr(string val);
     void print() ;
     Attr *clone(void) ;
     bool operator==(const Attr &right) ;
     bool operator!=(const Attr &right) ;
     bool operator<(const Attr &right) ;
     bool operator<=(const Attr &right) ;
     bool operator>(const Attr &right) ;
     bool operator>=(const Attr &right);
 };

class Record
{
private:
    vector<Attr *> attrptr;

public:
    vector<Attr *> get_arr(void);
    Record(vector<Attr *> schema);
    Record(const Record &s);
    Record &operator=(const Record &s);
    void print();
    void addAttr(Attr *ptr);
    void addAttr(vector<Attr *> ptr);
    bool operator==(const Record &right);
    friend bool check_tuple(Record *ptr, int i, tuple<string, char, Attr *> condition);
    friend Relation *naturaljoin(Relation *R1, Relation *R2, list<string> joinattr);
    friend class Relation;
};

class Relation
{
private:
    // storing a relation
    int nattr, nrecs;         // number of attributes and records
    vector<int> attrinds;     // mapping schema to indices
    list<Record *> recs;      // list of records
                              // methods
public:
    vector<string> attrnames; // schema
    int getindex(string &str);
    Relation(vector<string> schema);
    void addRecord(Record *ptr);
    void addRecord(Relation *ptr);
    bool find(Record *ptr);
    void print();
    friend Relation *_union(Relation *R1, Relation *R2);
    friend Relation *_difference(Relation *R1, Relation *R2);
    friend bool check(Record *ptr, Relation *R1, DNFformula *f);
    friend Relation *_catersianproduct(Relation *R1, Relation *R2);
    friend Relation *_projection(Relation *R1, list<string> projectattrs);
    friend Relation *difference(Relation *R1, string s1, string s2);
    friend Relation *naturaljoin(Relation *R1, Relation *R2, list<string> joinattr);
    friend Relation *selection(Relation *R1, DNFformula *f);
};

Relation *_union(Relation *R1, Relation *R2);
Relation *_difference(Relation *R1, Relation *R2);
Relation *_catersianproduct(Relation *R1, Relation *R2);
Relation *_projection(Relation *R1, list<string> projectattrs);
bool check_tuple(Record *ptr, int i, tuple<string, char, Attr *> condition);
bool check(Record *ptr, Relation *R1, DNFformula *f);
Relation *selection(Relation *R1, DNFformula *f);
Relation *difference(Relation *R1, string s1, string s2);
Relation *naturaljoin(Relation *R1, Relation *R2, list<string> joinattr);
Attr *get_attr(string s);
Relation *inputRelation(void);