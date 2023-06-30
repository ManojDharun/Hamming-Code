#include<iostream>
using namespace std;
class hamm
{
        public:
                hamm();
                void find_r(int);
                int power(int,int);
                void getdetails();
                void display();
                void parity();
                void getBin(int);
                void getpowers(int,int,int*);
                void getpos(int *);
                int* makearray1(int,int,int*);
                int* dec_bin(int);
                void change(int**);
                void makearray(int,int,int*);
                int* findpos(int,int);
                int findparity(int,int[]);
                int l,*arr,sum,*arr1,r,*bin,*pow_a;
                int **par;
                int **my_par;
                int **new_par;
};
