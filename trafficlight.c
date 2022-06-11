#include <stdio.h>
#include <stdbool.h>
#include <sys/time.h>
#include <interrupt.h>
//jede lampe hat eigene adresse wo pointer drauf zeigt

#define char green = 2;
#define char red = 0;
#define char yellow = 1;

bool *green;
bool *red;
bool *yellow;
char light; // 0 = red, 1 = yellow, 2 = green, 3 = out
//bool set;
char setState; // 0 = goGreen 1 = goRed 2 = blinkYellow 
bool step;
bool error;

bool lightsGreen(bool isActive, light); //
bool sendError(time_t *now);
bool setLight(bool set, light);
char getLight();

bool sendError(time_t *now){
        printf("%s: Die Ampel war nicht rot", ctime(&now)); //test output if traffic light isnt red
        if (getLight() = green)
        {
            setLight(false, green);
        }
        
        setLight(true, 0);
        if (getLight() = 0)
        {
            printf("%s: Hardwarefehler. \n Die Ampel geht in den Notfallstatus", ctime(&now)); //traffic light blinking yellow
        }
        return error;
}  

bool setLight(bool set, char light){
    switch (light)
    {
    case 0:
        *red = set;
        break;
    case 1:
        *yellow = set;
        break;
    case 2:
        *green = set;
        break;
    default:
        break;
    }
}

char getLight(){
   if (*red)
   {
       light = 0;
   }else if (*yellow)
   {
       light = 1;
   }else if (*green){
       light = 2;
   }else {
       light = 3;
   }
      
   return light;    
}

bool setTrafficLight(bool isActive, light){
    
    switch (setState)
    {
    case 0:
        if (getLight() = 0 || getLight() = 3)
        {
            setLight(true,yellow); //two seconds programming
            setLight(true,green); 

        }
        
        setLight()
        break;
    
    default:
        break;
    }

}

void main(){

    while (1){

    }
}
