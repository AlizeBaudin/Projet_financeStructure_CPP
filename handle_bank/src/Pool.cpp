#include "Pool.h"

Pool::Pool(){}
Pool::Pool(Lender* bank, std::vector<Facility*> facilitie): m_bank(bank), m_facilities(facilitie){}

Pool::~Pool(){}

void Pool::displaysPool()const{
    cout << "Pool of banks : ";
    m_bank->displayLender();
    m_bank ->displayFacilities(m_facilities);
}

