#ifndef LENDER_H
#define LENDER_H

//#include "Deal.h"
#include <iostream>
#include <string>
#include <vector>
/*#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>*/

#include "Facility.h"

using namespace std;
//using namespace sql;

/**

    Class for explain all actor of lend for borrower (company C1)
        - Agent : bank A who deal with company C1 and get some pool of other banks
        - Other bank : get some pool with agent

    Class Lender is parent of Pool and Borrower
    Class is child of Deal

*/

class Lender
{
    public:
        Lender();
        Lender(string name);
        Lender(string name, double iR);
        virtual ~Lender();

        //getter et setter
        string getName(){return m_name;}
        double getInterestRate(){return m_interestRate;}
        Facility* getFacilities() {return m_facilities;}
        void setName(string name);
        void setInterestRate(double iR);
        void setFacility(Facility* facility);

        // attributs et methode
        void displayLender()const;
        void displayFacilities(std::vector<Facility*> vecFacility);// getter facilities of Lender
        std::vector<Facility*> vectorFacilitie(Facility* facility); // to stock facility

    protected:
        //int m_id;
        string m_name;
        double m_interestRate;
        Facility* m_facilities;
};

inline void Lender::setInterestRate(double iR){this -> m_interestRate = iR;}
inline void Lender::setName(string name){this -> m_name=name;}
inline void Lender::setFacility(Facility* facility){ m_facilities=facility;}

#endif // LENDER_H
