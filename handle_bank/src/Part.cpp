#include "Part.h"

Part::Part(){}

Part::~Part(){}

Part::Part(Pool* pool, double repaymentAmount, double interestRate)
        : m_pool(pool), m_repaymentAmount(repaymentAmount), m_interestRate(interestRate) {}


void Part::displayPart() const{
    cout<<"Part from pool : "<<m_pool<<endl;
    cout << "Repayment Amount: " << m_repaymentAmount << endl;
    cout << "Interest Rate: " << m_interestRate << endl;
}

double Part::calculatePart(double repaymentAmout, double interestRate){
    double y;
    y=repaymentAmout*(1+interestRate/100);
    return y;
}



/* for SQL
void Part::saveToDatabase(Connection* con, const string& facilityStartDate) {
    PreparedStatement* pstmt = con->prepareStatement(
        "INSERT INTO parts (facility_start_date, repayment_amount, interest_rate) "
        "VALUES (?, ?, ?)"
    );
    pstmt->setString(1, facilityStartDate);
    pstmt->setDouble(2, repaymentAmount);
    pstmt->setDouble(3, interestRate);

    pstmt->executeUpdate();

    delete pstmt;
}*/
