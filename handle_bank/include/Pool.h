#ifndef POOL_H
#define POOL_H


#include <iostream>
#include <string>
#include <vector>
/*#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>*/
#include "Lender.h"
#include "Facility.h"

using namespace std;
//using namespace sql;

/**
    Class for structure one pool link with deal. It is send of agent bank ISB.
    It is child of Facility
    Pool gather all facility by Lender.
    Link with pointer to Portefolio
*/

class Pool : public Facility
{
    public:
        Pool();
        Pool(Lender* bank, std::vector<Facility*> vectFacility);
        virtual ~Pool();

        // getter et setter
        Lender* getBanks(){return m_bank;}
        std::vector<Facility*> getFacilities(){return m_facilities;}
        void setBanks(Lender* banks);
        void setFacilitie(std::vector<Facility*> facilities);
        //attribut and methode
        void displaysPool() const;

    private:
        Lender* m_bank;
        std::vector<Facility*> m_facilities; //set of all facility by bank/lender.
};


inline void Pool::setBanks(Lender* bank){m_bank = bank;}
inline void Pool::setFacilitie(std::vector<Facility*> facilities){m_facilities = facilities;}

#endif // POOL_H
