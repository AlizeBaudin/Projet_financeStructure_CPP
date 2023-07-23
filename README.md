# Projet finance structurée en C++
Projet en C++ visant à créer une application sur la gestion d'un deal pour un emprunt entre les banques et une companie. <br>
Codé sous Code::Block, il peut être adapté à Visual Studio Code avec connexion à Google Cloud, sous protocole SSH.

## Objectif du projet 
- Mise en place du polymorphisme : héritage/classe. <br>
- Code en majoritée avec des pointeurs. Cela fut essentielle pour la gestion du contrat 'Deal' et de l'interaction entre les classes afin de communiquer leurs fonctionnalitées sans l'utilisation massive de la mémoire, c'est-à-dire sans copier la classe entière dans une autre classe.
- Utilisation de connector C++ 8.0 MySQL pour faire un gestion de l'application dans une base de donnée. <br>
- Il n'y a pas de développement d'interface, compte tenue de l'utilisationde MySQL. Ce projet n'est pas à but d'utilisation d'un client mais interne, pour la bonne gestion des données.

## Le contenue du projet
### Les classes
- Deal : classe principale de gestion du contrat passé entre l'emprunter et le prêteur. Deal n'est pas une classe mère, mais est pointé par l'emprunteur et le prêteur.
- Lender : regroupe l'ensemble des acteurs prêtant l'argent sous forme de part.
- Facility : Gestion des pull du premier contrat d'engagement et de capacité de payement des 'Lender' ici sur une année.
- Borrower : est la classe de gestion de l'emprunteur.
- Part : gestion des part présent dans le portefolio.
- Pool : présentation des Pool de chaque prêteur de la classe Lender.
- Portefolio : regroupe l'ensemble des parts, pour gérer la dette de l'emprunteur. Ici la dette est positive, vu comme une option pouvant être investit sur les marchés financier.

### Exécution 
Dans le main, nous voyons l'utilisation des pointeurs pour la gestion des Lender. On a un contrat (Deal), avec un certain constructeur selon la demande, et un prêteur principale issue de la classe Lender, qui va lancer des pools pour une demande de financement du prêt. 

## Remarques
Le projet est toujours en cours de finalisation dans l'attente de la fin de mon année d'étude en fin septembre 2023. Il sera repris ultérieurement pour peaufiner et améliorer l'exécution ainsi que la communication entre MySql et l'application qui n'est pas encore mise au point. 



