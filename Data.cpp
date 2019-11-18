//
// Created by carte on 11/14/2019.
//
using namespace std;
#include <ostream>
#include "Data.h"


Data::Data(double points, double rebounds, double assists, double rate) {     //constructor for a Data object
    pointsPerGame = points;
    reboundsPerGame = rebounds;
    assistsPerGame = assists;
    rating = rate;
}
ostream &operator<<(ostream &os, const Data &d) {
    os << d.pointsPerGame << " " << d.reboundsPerGame << " " << d.assistsPerGame << "  " << d.rating << endl;    //printing the Data object
    return os;
}

bool Data::operator<(const Data &rt) const {
    return rt.rating < rating;
}

bool Data::operator>(const Data &rt) const {
    return rt.rating > rating;
}



