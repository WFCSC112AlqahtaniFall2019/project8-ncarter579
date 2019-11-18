
//
// Created by carte on 11/14/2019.
//

#ifndef PROJECT8_DATA_H
#define PROJECT8_DATA_H

#include <iostream>
using namespace std;

class Data{
public:
    friend ostream& operator<<( ostream& os, const Data& d); //output stream overload operator
    bool operator<(const Data &rt) const;     //overload operator
    bool operator>(const Data &rt) const;
    Data(double point, double rebound, double assist, double rate);     //constructor
    Data(){};   //default constructor
private:
    double pointsPerGame;              //four data points
    double assistsPerGame;
    double reboundsPerGame;
    double  rating;
};

#endif //PROJECT8_DATA_H
