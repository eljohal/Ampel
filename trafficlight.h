#include <stdio.h>
#include <stdbool.h>
#include <sys/time.h>

/*  Zu Programmieren ist eine Funktion für die Steuerung der Ampel auf ihren jeweiligen Ampelphasen. Dabei kann die Ampel auf Keyboardinputs reagieren und gibt den jeweiligen 
    Zustand auf der Konsole aus. 
    Keyboardinput einlesen --> Auto kommt und Ampel schaltet auf Grün
    Ampel schaltet nach 10 Sekunden auf Rot
    Ampel sendet Fehlermeldung falls Ampel nicht auf rot schaltet

  */

#define ROT 0
#define GELB 1
#define GRÜN 2
#define CHANGEROT 3
#define CHANGEGELB 4
#define CHANGEGRÜN 5
#define BLINKGELB 6
#define ERROR 7
#define MAXAMPEL 3

int ampelZustand; //Variable beschreibt Zustand der Ampel; 0 = rot; 1 = grün; 2 = wird rot; 3 = wird gelb; 4 = wird grün; 5 = gelb; 6 = gelb blinkend; 7 = fehler
int goToZustand; //Beschreibt welchen Zustand die AMpel einnehmen soll
int farbe; // 0 = Rot; 1 = Gelb; 2 = Grün

bool *pLampe; //Pointer Lampe
bool green;
bool yellow;
bool red;




bool changeAmpel(int ampelZustand); //Diese Funktion stellt den Zustand der Ampel ein
int stepCounter(); //Zählt Steps in changeAmpel
int setLight(int farbe, bool value); //Diese Funktion schaltet die Lampen ein
int getLight(); //Diese Funktion liest den Zustand der Ampel Lampen
bool sendError(); //Diese Funktion sendet mittels eines Timestamp eine Fehlermeldung wenn die Ampel rot ist TODO AUSLAGERN DER FUNKTION IN EIGENE DATEI
int getAmpelState(); //Diese Funktion zeigt Ampelstatus

int setLight(int farbe, bool value){
    switch (farbe)
    {
    case 0:
        red = value;
        break;

    case 1:
        yellow = value;
        break;
    case 2:
        green = value;
        break;
    default:
        sendError();
        break;
    }

}

int getLight(){
    if (green == true)
    {
        farbe = GRÜN;
    }else if (yellow == true)
    {
        farbe = GELB;
    }else if (red == true)
    {
        farbe = ROT;
    }else{
        sendError();
        return NULL;
    }
    
    return farbe;
}

int getAmpelState(){
    return ampelZustand;
}

//changeAmpel in eine while schleife und solange bis sie den zustand erreicht hat der gewünscht ist. zB wird rot verknüpft mit rot als zustand unbedingt anfangszustand

bool changeAmpel(int goToZustand){
    
    switch (goToZustand){
        case 0:
        ampelZustand = 2;
        if(ampelZustand == 6){
            setLight(GELB, false);         
            
        }else if (getLight()==GRÜN || getLight()==GELB)
        {
            setLight(getLight(), false);
            
        }
        if(getLight()==ROT){
            setLight(ROT,true);
            ampelZustand = 0;
            return true;
            break; //check when function leaves
        }
        case 1:          
        }              
}

