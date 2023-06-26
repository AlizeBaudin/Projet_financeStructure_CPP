#ifndef PART_H
#define PART_H

#include <iostream>
#include <string>
#include <vector>
/*#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>*/

#include "Deal.h"
#include "Pool.h"
using namespace std;
//using namespace sql;

/**
    This class it is for represent a simple part of change in deal.
    It is only child of Facility, not link with other class.
    Facility is contract : Part it is application of contract
*/

class Part
{
    public:
        Part();
        virtual ~Part();
        Part(Pool* pool, double repaymentAmount, double interestRate);

        //getter et setter
        double getRepaymetAmout(){return m_repaymentAmount;}
        double getInterestRate() {return m_interestRate;}
        void setRepaymentAmout(double rA);
        void setInterestRate(double iR);

        // Autre attribut
        void displayPart() const;
        double calculatePart(double repaymentAmout, double interestRate); // (level of payement)x(%interest)
        //void saveToDatabase(Connection* con, const string& facilityStartDate);

    protected:
        double m_repaymentAmount;
        double m_interestRate;
        Pool* m_pool ;
        //Portefolio m_portefolio;
};

inline void Part::setInterestRate(double rA){this -> m_repaymentAmount = rA;}
inline void Part::setRepaymentAmout(double iR){this -> m_interestRate = iR;}

#endif // PART_H
