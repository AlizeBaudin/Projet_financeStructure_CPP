#ifndef DEAL_H
#define DEAL_H

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
    Class who lead the processus
    Gather all Lender and Pool in game for deal.
    No link in portefolio
*/

class Deal
{
    public:
        Deal();
        virtual ~Deal();
        Deal(const int& idDeal, Lender* agent, const string& nameborrower); // constructor for deal canonical
        Deal(const int& contractNumber, Lender* agent,const string& nameBorrower,
             double projectAmount, const string& currency, const string& contractStartDate,
             const string& contractEndDate, const string& dealStatus); // usual constructor

        // getter et setter usual
        int getIdDeal() const {return m_contractId;}
        Lender* getAgent() const {return m_agent;}
        string getBorrower() const {return m_nameBorrower;}
        double getProjectAmount() const {return m_projectAmount;}
        string getCurrency() const {return m_currency;}
        string getContractStartDate() const {return m_contractStartDate;}
        string getContractEndDate() const {return m_contractEndDate;}
        string getDealStatus() const {return m_dealStatus;}

        void setIdDeal(const int& idDeal);
        void setAgent(Lender* agent);
        void setBorrower(string borrower);
        void setProjectAmount(double projectAmount);
        void setCurrency(const string& currency);
        void setContractStartDate(const string& contractStartDate);
        void setContractEndDate(const string& contractEndDate);
        void setDealStatus(const string& dealStatus);

        // attributs et methods usual
        void displayDeal() const; // print stat of deal
        void displayLender(); // get pool-lenders
        void displayAllFacility(); // get facilities
        void addLender(Lender lender);// set pool-lenders
        void addFacility(Facility facility); // set one facility

        // methode for handle data base with MySQL
        //void saveToDatabase(Connection* con); //save the information on database wwho given to MySQL or PostgreSQL

    protected:
        int m_contractId;
        Lender* m_agent; // principal agent of transaction : here bank A
        string m_nameBorrower; // the borrower for the deal : agent A is his prime dealer.
        double m_projectAmount;
        string m_currency;
        string m_contractStartDate;
        string m_contractEndDate;
        string m_dealStatus;
        std::vector<Lender>* m_lenders; // other banks called by agent (bank A) : send facility of deals
        std::vector<Facility>* m_facilities; //  set all pool from lender
};

inline void Deal::setIdDeal(const int& contractNumber){this->m_contractId = contractNumber;}
inline void Deal::setAgent(Lender* agent){m_agent = agent;}
inline void Deal::setBorrower(string borrower){this -> m_nameBorrower = borrower;}
inline void Deal::setProjectAmount(double projectAmount) {this->m_projectAmount = projectAmount;}
inline void Deal::setCurrency(const string& currency) {this->m_currency = currency;}
inline void Deal::setContractStartDate(const string& contractStartDate){this->m_contractStartDate = contractStartDate;}
inline void Deal::setContractEndDate(const string& contractEndDate){this->m_contractEndDate = contractEndDate;}
inline void Deal::setDealStatus(const string& dealStatus){this->m_dealStatus = dealStatus;}


#endif // DEAL_H
