#include <string.h>
#include <iostream>
#include "FORUMtext.h"

using namespace std;

//TO PERIEXOMENO TWN STRINGS EINAI TUXAIO KAI APOSKOPEI KATHARA STI DIEUKOLINSI TOU DEBUGGING

const string strTHREADTITLES[] =			
{	"Κανόνες και χρήσιμες πληροφορίες",
	"Thread2",
	"Thread3",
	"Thread4",
	"Thread5",
	"Thread6"
};

const string strPOSTTITLES[] =		
{   "Χρηση συναρτησεων",
    "Υπακολουθίες",
    "Μέγεθος MAXNUMΒ",
    "Παράμετροι gcc",
    "Μεγάλες αποκλίσεις στον χρόνο εκτέλεσης "
};

const string strPOSTTEXTS[] =
{
	"Θα πρέπει να γίνεται δυναμκή δέσμευση μέσω new και delete απο constructors, destructors για ορόφους-καμπίνες? Αν όχι η μόνη τους δουλειά θα είναι η ανάθεση χωριτικότητας και η εκτύπωση των μηνμάτων? ",
	"ναι εχεις 2 κλασειςγια το αλλο,δλδ αν ελεγε εχεις 1000000 καμ.πινες θα εφτιαχνες 1000000 μεταβλητες???",
	"γιατί εχουμε δύο κλάσεις, δεν μπορούμε να έχουμε μια με μια μεταβλητή [capacity] και μια συνάρτηση-μέλος που να την κάνει 4 ή 2 ανάλογα με το τι θέλουμε;",
	"άρα δεν θέλουμε να εμφανίζονται από 400 φορές το μήνυμα?αν γίνει με πίνακα δεν θα εμφανίζονται μόνο από 4 φορές? ",
	"gia na kanw arxikopoihsh se ena antikeimeno estw student grafw:student s1([john]);kai kaleitai o constructor ths student.gia na kanw to idio me enan pinaka poia einai h synta3h?"
};

const string strCREATORS[] =
{
	"UserA",
	"UserB",
	"UserC",
	"UserD",
	"UserE",
	"UserF",
	"UserG",
	"UserH",
	"UserI",
	"UserK",
	"UserL",
	"UserM"
};

