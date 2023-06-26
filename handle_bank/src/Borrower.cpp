#include "Borrower.h"

Borrower::Borrower(){}
Borrower::Borrower(string name): m_name(name){}

Borrower::~Borrower(){}


void Borrower::displayBorrower()const{
    cout<<"Name of borrower : "<<m_name<<endl;
//    cout<<"Stat of deal : "<<endl;
//    m_deal->displayDeal();
//    cout<<"All actual lender : "<<endl;
//    m_deal->displayLender();
//    cout<<"All facility : "<<endl;
//    m_deal->displayAllFacility();
}

void Borrower::displayAllPart(){
    if(m_parts==nullptr){
        cout<<"Not part : keep calm and go deal"<<endl;
    }else{
        cout<<"List of Part of each pool by facility :"<<endl;
        for(Part part : *m_parts){
            part.displayPart();
        }
    }
}

void Borrower::addPart(Part part){
    if(m_parts==nullptr){
        m_parts = new std::vector<Part>;
    }

    m_parts->push_back(part);
}
