#ifndef Date
#define Date

class date{
    public:
        long long day;
        long long month;
        long long year;
        long long m[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
        void julian(long long x,bool flag);
        void gregorian(long long x);
};

#endif