#include<bits/stdc++.h>
using namespace std;
int main(){
    // ---------------------------- if statements ------------------------ 
    int costOfApple = 75;

    if(costOfApple <= 80){
        cout<<"I am buying Apples";
    }

    // I am buying Apples will be printed on the screen.


    // ---------------------------- if-else statements ------------------------

    costOfApple = 90;

    if(costOfApple <= 80){
        cout<<"I am buying Apples";
    }
    else{
        cout<<"I am buying something else";
    }

    // I am buying something else will be printed on the screen.

    // ---------------------------- else-if statements ------------------------

    int costOfMangos = 120;
    
    if(costOfApple <= 80){
        cout<<"I am buying Apples";
    }
    else if(costOfMangos <= 150){
        cout<<"I am buying Mangos";
    }
    else{
        cout<<"I am buying something else";
    }

    // I am buying Mangos will be printed on the screen.

    // Note : if costOfApple is less then 80 and costOfMangos is also less then 150
    //       in that case "I am buying Apples" will be printed 
    //       because the flow control in sequential.


   // ---------------------------- switch ------------------------
    
    int dayOfWeek = 3;
   
   switch(dayOfWeek) {
   
      case 1:
         cout << "Monday";
         break;
      
      case 2:
         cout << "Tuesday";
         break;
      
      case 3:
         cout << "Wednesday";
         break;
         
      case 4:
         cout << "Thursday";
         break;
         
      case 5:
         cout << "Friday";
         break;
         
      default:
         cout << "Invalid day";
         break;
   }
}   