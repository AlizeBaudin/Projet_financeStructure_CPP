#include <iostream>

#include "Deal.h"
#include "Lender.h"
#include "Facility.h"
#include "Part.h"
#include "Portefolio.h"
#include <string>
#include <vector>
/*#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>*/

using namespace std;
//using namespace sql;

void mySQL_connexion(){
/*
    // Connexion à la base de données MySQL
    mysql::MySQL_Driver* driver;
    Connection* con;

    driver = mysql::get_mysql_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306", "username", "password");
    con->setSchema("bank_database");

    // Création d'un exemple de Deal
    Deal deal("S1234", "Bank A", "Pool A", "Borrower A", 1000000.0, "USD",
              "2023-01-01", "2024-01-01", "closed");

    // Enregistrement du Deal dans la base de données
    deal.saveToDatabase(con);

    // Création d'un exemple de Facility
    vector<string> lenders = {"Lender 1", "Lender 2"};
    Facility facility("2023-01-01", "2023-06-30", 500000.0, "USD", lenders);

    // Enregistrement de la Facility dans la base de données
    facility.saveToDatabase(con, deal.getContractNumber());

    // Création d'un exemple de Part
    Part part(250000.0, 0.05);

    // Enregistrement de la Part dans la base de données
    part.saveToDatabase(con, facility.getStartDate());

    // Fermeture de la connexion à la base de données
    delete con;
*/
}


/** PLan d'action
// Exemple d'utilisation des classes pour représenter un financement structuré
// Dans un premier temps : distribuer l'héritage avec les classse
// dans un second temps : établir les pointeur entre les classe enfant ou entre parent au besoin
*/

int main()
{


    // for stat the deal : we have borrower, Ariane space, and lender, Space-Bank, who sign the deal
    Borrower *ArianeSpace = new Borrower("Ariane Space");
    Lender *ISB = new Lender("International Space Bank");
    Deal deal(1, ISB, "Ariane Space"); // id=1, Lender=A, borrower="company C1"

    //The deal is for get many money to colonize Mars, for the 5th colonie (oh yeah : we are in 2184 years)
    // It need many money : more than we can explain in 2023 (in our moment, it is represent 102 trillion dollar)
    // Well the Space Bank get some pool in financial market : they call many Lender
    Lender *ESABank = new Lender("Space Bank European", 3.8);
    //ESABank->displayLender();
    //Lender *MuskAction = new Lender("Action of Musk", 5.1);
    //Lender *NasaBank = new Lender("Space Bank U.S.A", 4.9);
    //Lender *RosccosmosBank = new Lender("Space Bank Soviet", 4.8);
    //Lender *CNSABank = new Lender("Space Bank Chiness", 5.0);


    // And get some pool by bank : we need facilities by lenders
    Facility* facilityEuro = new Facility(1, "2184-01-01", "2184-12-31", 10000000000.0, "EUR");
    // a Lender could be have different facilities. for tha we stock facilities in pointer vector of Facility
    std::vector<Facility*> vectESA;
    vectESA = ESABank->vectorFacilitie(facilityEuro);
    //ESABank->displayLender();
    //ESABank->displayLender();
    //ESABank->displayFacilities(vectESA);

/*    Facility facilityUSD(2, "2184-01-01", "2184-12-31", 200000000000.0, "USD");
    NasaBank->addFacility(facilityUSD);
    MuskAction->addFacility(facilityUSD);
*/
    //we got of pool this :
    Pool* poolESA = new Pool(ESABank, vectESA);
    //pool1->displaysPool();
//    Pool* pool2 = new Pool(NasaBank);
//    Pool* pool3 = new Pool(MuskAction);

    // We creat differente part emits by facility and get by pool:
    Part part1(poolESA, 50000.0, 5.0);
    //part1.displayPart();
    //Part* part2 = new Part(100000.0, 4.5);

    //borrower get all part
    ArianeSpace->addPart(part1);
    // and deal add a part

    // Now, we creat the Ariane Space portfolio for handle the payement what due borrower to lenders
    // We suppose the portefolio could be invest in the financial market for deal
    Portefolio* portefolio = new Portefolio(5000000000.0, 1.8);
    portefolio->addPartPF(part1, ArianeSpace);
    //portefolio->calculPrice(ArianeSpace);
    portefolio->displayPart();
    //portefolio->addPart(part2);



    //delete ArianeSpace;
    //delete ISB;
   // cout << " All is ok in class " << endl;
    return 0;
}
