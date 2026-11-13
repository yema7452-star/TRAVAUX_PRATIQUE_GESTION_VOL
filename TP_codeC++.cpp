#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Passager {
int id;
string nom;
string prenom;
string passeport;
};
struct Vol {
string numero;
string depart;
string arrivee;
int capacite;
int reserves;
double prix;
};
struct Reservation {
int id;
int idPassager;
string numeroVol;
string statut;
};
struct Paiement {
int idReservation;
double montant;
string remboursement;
};
vector<Passager> passagers;
vector<Vol> vols;
vector<Reservation> reservations;
vector<Paiement> paiements;
int prochainIdRes = 1;
int trouverPassager(int id) {
for (unsigned int i = 0; i < passagers.size(); i++)
if (passagers[i].id == id) return i;
return -1;
}
int trouverVol(string num) {
for (unsigned int i = 0; i < vols.size(); i++)
if (vols[i].numero == num) return i;
return -1;
}
int trouverReservation(int id) {
for (unsigned int i = 0; i < reservations.size(); i++)
if (reservations[i].id == id) return i;
return -1;
}
void enregistrerPassager() {
Passager p;
cout << "Id Nom Prenom Passeport : ";
cin >> p.id >> p.nom >> p.prenom >> p.passeport;
if (trouverPassager(p.id) != -1) { cout << "ERREUR : Id deja utilise.\n"; return; }
passagers.push_back(p);
cout << "Passager enregistre.\n";
}
void ajouterVol() {
Vol v;
cout << "Numero Depart Arrivee Capacite Prix : ";
cin >> v.numero >> v.depart >> v.arrivee >> v.capacite >> v.prix;
v.reserves = 0;
if (trouverVol(v.numero) != -1) { cout << "ERREUR : Vol deja existant.\n"; return; }
vols.push_back(v);
cout << "Vol ajoute.\n";
}
void afficherVolsDisponibles() {
cout << "--- VOLS DISPONIBLES ---\n";
for (unsigned int i = 0; i < vols.size(); i++) {
if (vols[i].reserves < vols[i].capacite) {
cout << vols[i].numero << " : " << vols[i].depart << " -> " << vols[i].arrivee
<< " | " << vols[i].reserves << "/" << vols[i].capacite
<< " | Prix : " << vols[i].prix << endl;
}
}
}
void rechercherVol() {
string num; cout << "Numero vol : "; cin >> num;
int i = trouverVol(num);
if (i == -1) { cout << "Vol introuvable.\n"; return; }
cout << vols[i].numero << " : " << vols[i].depart << " -> " << vols[i].arrivee
<< " | " << vols[i].reserves << "/" << vols[i].capacite << endl;
}
void effectuerReservation() {
int idP; string num;
cout << "Id Passager + Numero Vol : "; cin >> idP >> num;
if (trouverPassager(idP) == -1) { cout << "ERREUR : Passager non enregistre.\n"; return; }
int iv = trouverVol(num);
if (iv == -1) { cout << "ERREUR : Vol introuvable.\n"; return; }
if (vols[iv].reserves >= vols[iv].capacite) { cout << "ERREUR : Vol complet.\n"; return; }
for (unsigned int i = 0; i < reservations.size(); i++) {
if (reservations[i].idPassager == idP && reservations[i].numeroVol == num &&
reservations[i].statut != "ANNULEE") {
cout << "ERREUR : Deja reserve ce vol.\n"; return;
}
}
Reservation r;
r.id = prochainIdRes++;
r.idPassager = idP;
r.numeroVol = num;
r.statut = "VALIDEE";
reservations.push_back(r);
vols[iv].reserves++;
cout << "Reservation VALIDEE. Id = " << r.id << endl;
}
void enregistrerPaiement() {
int idR; cout << "Id Reservation : "; cin >> idR;
int ir = trouverReservation(idR);
if (ir == -1) { cout << "ERREUR : Reservation introuvable.\n"; return; }
if (reservations[ir].statut == "ANNULEE") { cout << "ERREUR : Reservation annulee.\n"; return; }
if (reservations[ir].statut == "PAYEE") { cout << "ERREUR : Deja payee.\n"; return; }
int iv = trouverVol(reservations[ir].numeroVol);
Paiement p; p.idReservation = idR; p.montant = vols[iv].prix; p.remboursement = "AUCUN";
paiements.push_back(p);
reservations[ir].statut = "PAYEE";
cout << "Paiement enregistre : " << p.montant << " FCFA\n";
}
void annulerReservation() {
int idR; cout << "Id Reservation : "; cin >> idR;
int ir = trouverReservation(idR);
if (ir == -1) { cout << "ERREUR : Reservation introuvable.\n"; return; }
if (reservations[ir].statut == "ANNULEE") { cout << "ERREUR : Deja annulee.\n"; return; }
if (reservations[ir].statut == "PAYEE") {
for (unsigned int i = 0; i < paiements.size(); i++)
if (paiements[i].idReservation == idR) {
paiements[i].remboursement = "REMBOURSE_PARTIEL";
cout << "Remboursement partiel applique.\n";
}
}
int iv = trouverVol(reservations[ir].numeroVol);
if (iv != -1) vols[iv].reserves--;
reservations[ir].statut = "ANNULEE";
cout << "Reservation annulee.\n";
}
void consulterReservations() {
for (unsigned int i = 0; i < reservations.size(); i++)
cout << "Res [" << reservations[i].id << "] Passager " << reservations[i].idPassager
<< " Vol " << reservations[i].numeroVol << " Statut " << reservations[i].statut << endl;
}
void afficherInfosReservation() {
int idR; cout << "Id Reservation : "; cin >> idR;
int ir = trouverReservation(idR);
if (ir == -1) { cout << "ERREUR : Reservation introuvable.\n"; return; }
cout << "Reservation " << reservations[ir].id << " | Passager " << reservations[ir].idPassager
<< " | Vol " << reservations[ir].numeroVol << " | Statut " << reservations[ir].statut << endl;
}
bool quitter() {
char rep;
cout << "\nVoulez-vous vraiment quitter ? (o/n) : ";
cin >> rep;
if (rep == 'o' || rep == 'O') {
cout << "\n====================================\n";
cout << "Merci d'avoir utilise l'Agence de Voyage de Cotonou.\n";
cout << "A bientot !\n";
cout << "====================================\n";
return true;
} else {
cout << "Retour au menu...\n";
return false;
}
}
int main() {
// Donnees de test - version C++98
Passager p1;
p1.id = 1; p1.nom = "DOSSOU"; p1.prenom = "Jean"; p1.passeport = "BJ123";
passagers.push_back(p1);
Vol v1;
v1.numero = "AF001"; v1.depart = "Cotonou"; v1.arrivee = "Paris";
v1.capacite = 2; v1.reserves = 0; v1.prix = 350000;
vols.push_back(v1);
Vol v2;
v2.numero = "AF002"; v2.depart = "Cotonou"; v2.arrivee = "Abidjan";
v2.capacite = 1; v2.reserves = 0; v2.prix = 120000;
vols.push_back(v2);
int choix;
bool fin = false;
while (!fin) {
cout << "\n===== AGENCE DE VOYAGE COTONOU =====\n";
cout << "1. Enregistrer un passager\n";
cout << "2. Ajouter un vol\n";
cout << "3. Afficher les vols disponibles\n";
cout << "4. Rechercher un vol\n";
cout << "5. Effectuer une reservation\n";
cout << "6. Enregistrer un paiement\n";
cout << "7. Annuler une reservation\n";
cout << "8. Consulter les reservations\n";
cout << "9. Afficher les infos d'une reservation\n";
cout << "0. Quitter\n";
cout << "Choix : ";
cin >> choix;
if (choix == 1) enregistrerPassager();
else if (choix == 2) ajouterVol();
else if (choix == 3) afficherVolsDisponibles();
else if (choix == 4) rechercherVol();
else if (choix == 5) effectuerReservation();
else if (choix == 6) enregistrerPaiement();
else if (choix == 7) annulerReservation();
else if (choix == 8) consulterReservations();
else if (choix == 9) afficherInfosReservation();
else if (choix == 0) fin = quitter();
else cout << "Choix invalide, reessayez.\n";
}
return 0;
}
