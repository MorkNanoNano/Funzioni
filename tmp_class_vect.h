struct particella {
double p[4]; // energia-momento (E, px, py, pz)
int carica; // carica elettrica
double eta; // pseudo-rapidita’
};

#define type particella

class Vector {
    public:
        int len=0;
        type *arr = new type[0];

    void append(type el);
    void prepend(type el);
    void remove(int index);
    void sort(double (*func)(type), bool inverted);
    type val(int index);
};
