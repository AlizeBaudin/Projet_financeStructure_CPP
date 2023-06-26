#ifndef PORTEFOLIO_H
#define PORTEFOLIO_H

#include <iostream>
#include <string>
#include <vector>
/*#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>*/

#include "Part.h"
#include "Borrower.h"

using namespace std;
//using namespace sql;

/**
    This class is for handle the repayment amout what due the borrower
    is link between Pool and Borrower. For this, Portefolio is children of Part
    and pointed by Borrower.
*/

class Portefolio : public Part
{
    public:
        Portefolio();
        //Portefolio(double total);
        Portefolio(double totPrincipal); // all debt of the borrower : canonical constructor
        Portefolio(double totPincipal, double totInterest);
        virtual ~Portefolio();

        // getter et setter
        double getTotPrincipal(){return m_totalPrincipal;}
        double getTotInterest(){return m_totalInterest;}
        void setTotPrincipal(double totPrincip);
        void setTotInterest(double totInterest);

        //attribut and method
        void displayPortfolio()const;
        std::vector<Part>* getAllPartsFromBorrower(Borrower* borrower);
        double calculPrice(Borrower* borrower);
        double debt(Borrower* borrower); //
        void addPartPF(Part part, Borrower* borrower);


    protected:
        double m_totalPrincipal;
        double m_totalInterest;
};


inline void Portefolio::setTotPrincipal(double totPrincip){
    this->m_totalPrincipal=totPrincip;
}

inline void Portefolio::setTotInterest(double totInterest){
    this -> m_totalInterest=totInterest;
}


#endif // PORTEFOLIO_H
