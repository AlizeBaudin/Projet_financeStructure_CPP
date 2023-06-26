#include "Lender.h"

Lender::Lender(){}
Lender::Lender(string name):m_name(name){}
Lender::Lender(string name, double iR):
    m_name(name), m_interestRate(iR){}

/* destructor*/
Lender::~Lender(){}


void Lender::displayLender() const{
        cout << "Name lender: " << m_name << endl;
        cout << "Interest rate lender: " << m_interestRate << endl;
        m_facilities->displayFacility();
}

std::vector<Facility*> Lender::vectorFacilitie(Facility* facility){
    std::vector<Facility*> vectFacility;
    vectFacility.push_back(facility);
    return vectFacility;
}



void Lender::displayFacilities(std::vector<Facility*> vecFacility){
    for(Facility* facility : vecFacility){
        facility->displayFacility();
    }
}


