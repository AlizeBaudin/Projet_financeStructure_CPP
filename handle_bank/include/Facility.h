#ifndef FACILITY_H
#define FACILITY_H
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

//#include "Pool.h"
using namespace std;
//using namespace sql;


/**
    Class for explain the different slice money of lenders, lend for borrower.
    The Facility create a 'contract' for engage a Part for payment of company C1.
    Child of Pool
    Each Pool need one facility
    Each Part have one facility, so Facility  is parent of Part.
*/

class Facility
{
    public:
        Facility();
        virtual ~Facility();
        Facility(int id);
        Facility(const int id, const string& startDate, const string& endDate, double trancheAmount,
             const string& currency);

        // getter and setter : access to variable protected
        string getStartDate() const {return m_startDate;}
        string getEndDate() const {return m_endDate;}
        double getTrancheAmount() const {return m_trancheAmount;}
        string getCurrency() const {return m_currency;}
        int getId() const{return m_id;}
        void setStartDate(const string& startDate);
        void setEndDate(const string& endDate);
        void setTrancheAmount(double trancheAmount);
        void setCurrency(const string& currency);
        void setId(const int& id);

        // other attribute :
        void displayFacility() const;


    protected:
        int m_id; // id of facility
        string m_startDate;
        string m_endDate;
        double m_trancheAmount;
        string m_currency;
        string m_dealStatus;
};

inline void Facility::setId(const int& id) {this->m_id = id;}
inline void Facility::setStartDate(const string& startDate) {this->m_startDate = startDate;}
inline void Facility::setEndDate(const string& endDate) {this->m_endDate = endDate;}
inline void Facility::setTrancheAmount(double trancheAmount) {this->m_trancheAmount = trancheAmount;}
inline void Facility::setCurrency(const string& currency) {this->m_currency = currency;}




#endif // FACILITY_H
