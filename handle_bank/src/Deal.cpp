#include "Deal.h"

Deal::Deal(){}
Deal::Deal(const int& id, Lender* agent, const string& borrower):
    m_contractId(id), m_agent(agent), m_nameBorrower(borrower){} // constructor canonical
Deal::Deal(const int& contractNumber, Lender* agent,
     const string& borrower, double projectAmount, const string& currency,
     const string& contractStartDate, const string& contractEndDate,
     const string& dealStatus)
    : m_contractId(contractNumber), m_agent(agent),
      m_nameBorrower(borrower), m_projectAmount(projectAmount), m_currency(currency),
      m_contractStartDate(contractStartDate), m_contractEndDate(contractEndDate),
      m_dealStatus(dealStatus) {} //all for constructor (not need here)

Deal::~Deal(){} // destructor


// display all actor ins this deal
void Deal::displayDeal() const {
    cout << "Contract Number: " << m_contractId << endl;
    cout << "Agent: " << m_agent << endl;
    cout << "Pool: " << m_facilities << endl;
    cout << "Borrower: " << m_nameBorrower << endl;
    cout << "Project Amount: " << m_projectAmount << " " << m_currency << endl;
    cout << "Contract Start Date: " << m_contractStartDate << endl;
    cout << "Contract End Date: " << m_contractEndDate << endl;
    cout << "Deal Status: " << m_dealStatus << endl;
}

void Deal::displayAllFacility(){

    if (m_facilities == nullptr) {
        std::cout << "Not pool open." << std::endl;
    }else{
        for (Facility pool : *m_facilities) {
            pool.displayFacility();
        }
    }
}

void Deal::displayLender(){
    if (m_lenders == nullptr) {
        std::cout << "Not lenders in this deal." << std::endl;
        return;
    }

    std::cout << "List of actual lenders for pool : " << std::endl;
    for (Lender lender : *m_lenders) {
        lender.displayLender();
    }
    cout<<" "<<endl;
}


// add actor in this deal
void Deal::addLender(Lender lender){
    if (m_lenders == nullptr) {
        m_lenders = new std::vector<Lender>;
    }

    m_lenders->push_back(lender);
}

 void Deal::addFacility(Facility pool) {
    if (m_facilities == nullptr) {
        m_facilities = new std::vector<Facility>;
    }else if(m_lenders==nullptr){
        cout<<"No actor for deal : please keep calm and deal"<<endl;
    }

    m_facilities->push_back(pool);
 }

/* pour la connexion à la bdd
void Deal::saveToDatabase(Connection* con) {
    PreparedStatement* pstmt = con->prepareStatement(
        "INSERT INTO deals (contract_number, agent, pool, borrower, project_amount, currency, "
        "contract_start_date, contract_end_date, deal_status) "
        "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)"
    );
    pstmt->setString(1, m_contractNumber);
    pstmt->setString(2, m_agent);
    pstmt->setString(3, m_pool);
    pstmt->setString(4, m_borrower);
    pstmt->setDouble(5, m_projectAmount);
    pstmt->setString(6, m_currency);
    pstmt->setString(7, m_contractStartDate);
    pstmt->setString(8, m_contractEndDate);
    pstmt->setString(9, m_dealStatus);

    pstmt->executeUpdate();

    delete pstmt;
}
*/


