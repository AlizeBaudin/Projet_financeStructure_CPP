#ifndef BORROWER_H
#define BORROWER_H

#include <iostream>
#include <string>
#include <vector>
/*#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>*/


//#include "Deal.h"
#include "Part.h"

using namespace std;
//using namespace sql;


class Borrower
{
    public:
        Borrower();
        Borrower(string name);
        virtual ~Borrower();

        //gette et setter
        string getName(){return m_name;}
        std::vector<Part>* getPartBorrower(){return m_parts;}
        void setName(string name);

        //attributs and methods
        void displayBorrower()const;
        void repaymentPart();
        void displayAllPart(); // get Parts
        void addPart(Part part); // set part;

    protected:
        string m_name;
        //Deal* m_deal;
        std::vector<Part>* m_parts;
};

inline void Borrower::setName(string name){this -> m_name = name;}


#endif // BORROWER_H
