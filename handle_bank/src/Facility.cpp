#include "Facility.h"

Facility::Facility(){}

Facility::~Facility(){}
Facility::Facility(int id): m_id(id){}
Facility::Facility(const int id, const string& startDate, const string& endDate, double trancheAmount,
             const string& currency)
        : m_id(id), m_startDate(startDate), m_endDate(endDate), m_trancheAmount(trancheAmount),
          m_currency(currency) {}

void Facility::displayFacility() const{
    cout << "Start Date: " << m_startDate << endl;
    cout << "End Date: " << m_endDate << endl;
    cout << "Tranche Amount: " << m_trancheAmount << " " << m_currency << endl;

}



/* for MySQL
void Facility::saveToDatabase(Connection* con, const string& dealContractNumber) {
    PreparedStatement* pstmt = con->prepareStatement(
        "INSERT INTO facilities (deal_contract_number, start_date, end_date, tranche_amount, currency) "
        "VALUES (?, ?, ?, ?, ?)"
    );
    pstmt->setString(1, dealContractNumber);
    pstmt->setString(2, startDate);
    pstmt->setString(3, endDate);
    pstmt->setDouble(4, trancheAmount);
    pstmt->setString(5, currency);

    pstmt->executeUpdate();

    delete pstmt;
}*/
