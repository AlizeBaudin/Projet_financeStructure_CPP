#include "Portefolio.h"

Portefolio::Portefolio(){}
Portefolio::Portefolio(double totPrincipal): m_totalPrincipal(totPrincipal){}

Portefolio::Portefolio(double totPrincipal, double totInterest):
    m_totalPrincipal(totPrincipal), m_totalInterest(totInterest){}

/*Destructor*/
Portefolio::~Portefolio(){}

void Portefolio::displayPortfolio() const{
    cout<<"Total principal portfolio : "<<m_totalPrincipal<<endl;
    cout<<"Total interest portfolio : "<<m_totalInterest<<endl;
}

// Get all part who get borrower
std::vector<Part>* Portefolio::getAllPartsFromBorrower(Borrower* borrower) {
    std::vector<Part>* allPart;
    allPart=borrower->getPartBorrower();
    return allPart;
}

// Need when borrower use money from lender
void Portefolio::addPartPF(Part part, Borrower* borrower){
    // add part of borrower
    std::vector<Part>* allPart;
    allPart=borrower->getPartBorrower();
    if(allPart==nullptr){
        allPart = new std::vector<Part>;
    }

    allPart->push_back(part);
}

//this function calculate th sum of all price of port from borrower
double Portefolio::calculPrice(Borrower* borrower){
    std::vector<Part>* partOfBorrower;
    partOfBorrower=getAllPartsFromBorrower(borrower);
    double res =0.0; // stock result for return of vector of calcul parts
    double repaymentAmout, interestRate;
    for(Part part : *partOfBorrower){
        repaymentAmout = part.getRepaymetAmout(); // keep the value of amout for each part
        interestRate = part.getInterestRate(); // keep the value of interest rate for each part
        res=res+calculatePart(repaymentAmout, interestRate);
    }
    return res;
}


double Portefolio::debt(Borrower* borrower) {
    /*
        Calculte total principal minus the calculation of interest rate due to the lenders-pool
        We need a list of all price what due the borrower
    */
    double price = calculPrice(borrower);
    m_totalPrincipal= m_totalPrincipal+price; // calculate of debt : m_totalPrincipal is dept total of borrower (is it positive number)
    //here, we supose the portefolio is invest in the financial market :
    if(m_totalPrincipal>0){ //calculate the interest of portefolios
        m_totalPrincipal=m_totalPrincipal*(1 - m_totalInterest/100);
        // if total is positif, we substract the interest gain with money placed in portefolio, so the interest decrease the debt.
    }else{
        m_totalPrincipal=m_totalPrincipal*(1 + m_totalInterest/100);
        // if total is negatif, the debt is gain, so with interest of gain with money in portefolio
    }

    return m_totalPrincipal;
}
