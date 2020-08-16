/*
   Author: Jared Thacker
   Auburn ID: jwt0024
   filename: project2_jwt0024.cpp
   compilation instructions: g++ project2_jwt0024.cpp -o project2_jwt0024.out
   Help:
         1) Murach's C++ Programming: For if else statements and call by reference info
*/
#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <ctime>

using namespace std;

void pause_terminal();
/*
   Inputs: None
   Returns: None
   Purpose: to pause the terminal until the use presses "Enter"
*/

bool at_least_two_alive(bool A_alive,bool B_alive,bool C_alive);
/*
   Input: A_alive indicates whether Aaron is alive
          B_alive indicates whether Bob is alive
          C_alive indicates whether Charlie is alive
   Return: true if at least two are alive
           otherwise return false
*/
void Aaron_shoots1(bool& B_alive,bool& C_alive);
/*
   Use call by reference
   Input: B_alive indicates whether Bob is alive
          C_alive indicates whether Charlie is alive
   Return: Change B_alive inot false if Bob is killed
           Change C_alive into false if Charlie is killed 
*/
void Bob_shoots(bool& A_alive,bool& C_alive);
/*
   Use call by reference
   Input: A_alive indicates whether Aaron is alive
          C_alive indicates whether Charlie is alive
   Return: Change A_alive inot false if Aaron is killed
           Change C_alive into false if Charlie is killed 
*/

void Charlie_shoots(bool& A_alive,bool& B_alive);
/*
   Use call by reference
   Input: A_alive indicates whether Aaron is alive
          B_alive indicates whether Bob is alive
   Return: Change A_alive inot false if Aaron is killed
           Change B_alive into false if Bob is killed 
*/

void Aaron_shoots2(bool& B_alive,bool& C_alive);
/*
   Use Call by reference
   Input: A_alive indicates whether Aaron is alive
          B_alive indicates whether Bob is alive
   Return: Change B_alive inot false if Bob is killed
           Change C_alive into false if Charlie is killed 
*/

void test_at_least_two_alive(void);
/*
   This is a test driver for at_least_two_alive()
*/
void test_Aaron_shoots1(void);
/*
   This is a test driver for Aaron_shoots1()
*/

void test_Bob_shoots(void);
/*
   This is a test driver for Bob_shoots()
*/

void test_Charlie_shoots(void);
/*
   This is a test driver for Charlie_shoots()
*/

void test_Aaron_shoots2(void);
/*
   This is a test driver for Aaron_shoots2
*/

//Define the constants as requested from the rubric
const int N = 10000, P_A = 33, P_B = 50;
int main()
{
   //Set random seed
   srand(time(0));
   //Define the variables necessary for this program
   int n, numberOfAaronWinsStrat1, numberOfBobWinsStrat1, numberOfCharlieWinsStrat1;
   int numberOfAaronWinsStrat2,numberOfBobWinsStrat2, numberOfCharlieWinsStrat2;
   double aWinPercStrat1, bWinPercStrat1, cWinPercStrat1, aWinPercStrat2, bWinPercStrat2, cWinPercStrat2;
   bool A_alive, B_alive, C_alive; 

   cout << "***Welcome to Jared's Duel Simulator***" << endl;
   //Run the all of the test drivers
   test_at_least_two_alive();
   pause_terminal(); //Pause terminal 
   test_Aaron_shoots1();
   pause_terminal(); //Pause terminal
   test_Bob_shoots();
   pause_terminal(); //Pause terminal
   test_Charlie_shoots();
   pause_terminal(); //Pause terminal
   test_Aaron_shoots2();
   pause_terminal(); //Pause terminal

   cout << "Ready to test strategy 1 (Run 10,000 times):" << endl;
   pause_terminal();

   //Initialize the number of wins for Aaron, Bob, and Charlie for strategy 1
   numberOfAaronWinsStrat1 = 0;
   numberOfBobWinsStrat1 = 0;
   numberOfCharlieWinsStrat1 = 0;

   //Implement strategy 1
   for(n=0;n<N;n++){
      //Initially Aaron, Bob, and Charlie are all alive
      A_alive = true;
      B_alive = true; 
      C_alive = true;
      //While there are at least two people alive keep the duel going
      while(at_least_two_alive(A_alive,B_alive,C_alive)){

         if(A_alive){
            Aaron_shoots1(B_alive,C_alive); 
         }
          if(B_alive){
            Bob_shoots(A_alive,C_alive);
         }
         if(C_alive){
            Charlie_shoots(A_alive,B_alive);
         }
      }
      //Add a win to whoever is left standing at the end of the duel
      if(A_alive){
         numberOfAaronWinsStrat1 += 1;
      } else if(B_alive){
         numberOfBobWinsStrat1 += 1;
      } else if(C_alive){
         numberOfCharlieWinsStrat1 += 1;
      }
   }

   //Define the win percentage for Aaron, Bob, and Charlie for strategy 1
   aWinPercStrat1 = (double) numberOfAaronWinsStrat1 / (double) N;
   bWinPercStrat1 = (double) numberOfBobWinsStrat1 / (double) N;
   cWinPercStrat1 = (double) numberOfCharlieWinsStrat1 / (double) N;

   cout << "Aaron won " << numberOfAaronWinsStrat1 << "/" << N << " duels or " << numberOfAaronWinsStrat1 / (double) N * (double) 100 << "%" << endl;
   cout << "Bob won " << numberOfBobWinsStrat1 << "/" << N << " duels or " << numberOfBobWinsStrat1 / (double) N * (double) 100 << "%" << endl;
   cout << "Charlie won " << numberOfCharlieWinsStrat1 << "/" << N << " duels or " << numberOfCharlieWinsStrat1 / (double) N * (double) 100 << "%" << endl;

   cout << endl;

   cout << "Ready to test strategy 2 (Run 10,000 times):" << endl;
   pause_terminal();

   //Initialize the number of wins for Aaron, Bob, and Charlie for strategy 2
   numberOfAaronWinsStrat2 = 0;
   numberOfBobWinsStrat2 = 0;
   numberOfCharlieWinsStrat2 = 0;

  //Implement strategy 2
   for(n=0;n<N;n++){
      //Initially Aaron, Bob, and Charlie are all alive
      A_alive = true;
      B_alive = true; 
      C_alive = true;
      //While there are at least two people alive keep the duel going
      while(at_least_two_alive(A_alive,B_alive,C_alive)){
         if(A_alive){
            Aaron_shoots2(B_alive,C_alive);
         }
         if(B_alive){
            Bob_shoots(A_alive,C_alive);
         }
         if(C_alive){
            Charlie_shoots(A_alive,B_alive);
         }
      }
      //Add a win to whoever is left standing at the end of the duel
      if(A_alive){
         numberOfAaronWinsStrat2 += 1;
      } else if(B_alive){
         numberOfBobWinsStrat2 += 1;
      } else if(C_alive){
         numberOfCharlieWinsStrat2 += 1;
      }
   } 

   //Define the win percentage for Aaron, Bob, and Charlie for strategy 2
   aWinPercStrat2 = (double) numberOfAaronWinsStrat2 / (double) N;
   bWinPercStrat2 = (double) numberOfBobWinsStrat2 / (double) N;
   cWinPercStrat2 = (double) numberOfCharlieWinsStrat2 / (double) N;


   cout << "Aaron won " << numberOfAaronWinsStrat2 << "/" << N << " duels or " << numberOfAaronWinsStrat2 / (double) N * (double) 100  << "%" << endl;
   cout << "Bob won " << numberOfBobWinsStrat2 << "/" << N << " duels or " << numberOfBobWinsStrat2 / (double) N * (double) 100 << "%" << endl;
   cout << "Charlie won " << numberOfCharlieWinsStrat2 << "/" << N << " duels or " << numberOfCharlieWinsStrat2 / (double) N * (double) 100 << "%" << endl;

   cout << endl;
   //Compare strategy 1 and 2 and display which strategy is better
   if (aWinPercStrat1 > aWinPercStrat2){
      cout << "Strategy 1 is better than strategy 2" << endl;
   } else{
      cout << "Strategy 2 is better than strategy 1" << endl;   
   }

   return 0;
}

/*
   Function: at_least_two_alive
   Inputs: A_alive, B_alive, C_alive
   Outputs: True/False - there are at least duelists alive
*/
bool at_least_two_alive(bool A_alive,bool B_alive,bool C_alive)
{
   int n_alive = 0;
   //If Aaron is alive add 1 to n_alive 
   if (A_alive == true){
      n_alive += 1;
   }
   
   //If Bob is alive add 1 to n_alive 
   if(B_alive == true)
   {
      n_alive += 1;
   }
    
   //If Charlie is alive add 1 to n_alive 
   if(C_alive == true)
   {
      n_alive += 1;
   }
   
   //If there are more than 2 duelists alive
   //return true, otherwise return false
   if(n_alive >= 2)
   {
      return true;
   }
   else
   {
      return false;
   }       
}
/*
   Test driver for at_least_two_alive
*/
void test_at_least_two_alive(void)
{
   cout << "Unit Testing 1:Function - at_least_two_alive() \n";

   //Test case 1
   cout << "\t" << "Case 1: Aaron alive,Bob alive,Charlie alive\n";
   assert(true == at_least_two_alive(true,true,true));
   cout << "\t" << "Case passed...\n";

   //Test case 2
   cout << "\t" << "Case 2: Aaron dead,Bob alive,Charlie alive\n";
   assert(true == at_least_two_alive(false,true,true));
   cout << "\t" << "Case passed...\n";

   //Test case 3
   cout << "\t" << "Case 3: Aaron alive,Bob dead,Charlie alive\n";
   assert(true == at_least_two_alive(true,false,true));
   cout << "\t" << "Case passed...\n";

   //Test case 4
   cout << "\t" << "Case 4: Aaron alive,Bob alive,Charlie dead\n";
   assert(true == at_least_two_alive(true,true,false));
   cout << "\t" << "Case passed...\n";

   //Test case 5
   cout << "\t" << "Case 5: Aaron dead,Bob dead,Charlie alive\n";
   assert(false == at_least_two_alive(false,false,true));
   cout << "\t" << "Case passed...\n";

   //Test case 6
   cout << "\t" << "Case 6: Aaron dead,Bob alive,Charlie dead\n";
   assert(false == at_least_two_alive(false,true,false));
   cout << "\t" << "Case passed...\n";

   //Test case 7
   cout << "\t" << "Case 7: Aaron alive,Bob dead,Charlie dead\n";
   assert(false == at_least_two_alive(true,false,false));
   cout << "\t" << "Case passed...\n";

   //Test case 8
   cout << "\t" << "Case 8: Aaron dead,Bob dead,Charlie dead\n";
   assert(false == at_least_two_alive(false,false,false));
   cout << "\t" << "Case passed...\n";
}

/*
   Function: pause_terminal
   Inputs: None
   Outputs: None
   Purpose: pause the terminal until the user presses the "Enter" key
*/
void pause_terminal()
{
   cout << "Press Enter to continue...";
   cin.ignore().get();
}
/*
   Function: Aaron_shoots1
   Inputs: B_alive, C_alive
   Outputs: B_alive, C_alive
   Purpose: Change the status of whoever has been shot
*/
void Aaron_shoots1(bool& B_alive,bool& C_alive)
{
   //Define random number
   int p = rand() %100;

   //If p less than threshold probablility and Charlie is alive
   //then shoot Charlie, otherwise shoot Bob
   if (p <= P_A)
   {
      if (C_alive)
      {
         C_alive = false;
      } else {
         B_alive = false;
      }
   }
}

/*
   Test driver for Aaron_shoots1
*/
void test_Aaron_shoots1()
{
   bool Bob_Initializer = true, Charlie_Initializer = true;

   cout << "Unit Testing 2:Function - Aaron_shoots1(Bob_alive,Charlie_alive) \n";
   
   //Test case 1
   cout << "\t" << "Case 1: Bob alive,Charlie alive\n";
   Aaron_shoots1(Bob_Initializer,Charlie_Initializer);
   assert(true == Bob_Initializer);
   cout << "\t" << "\t" << "Aaron is shooting at Charlie \n";

   Bob_Initializer= false;
   Charlie_Initializer = true;
   
   //Test case 2
   cout << "\t" << "Case 2: Bob dead,Charlie alive\n";
   cout << "\t" << "\t" << "Aaron is shooting at Charlie\n";
   Aaron_shoots1(Bob_Initializer,Charlie_Initializer);
   assert(false == Bob_Initializer);
   
   Bob_Initializer = true;
   Charlie_Initializer = false;

   //Test case 3
   cout << "\t" << "Case 3: Bob alive,Charlie dead\n";
   cout << "\t" << "\t" << "Aaron is shooting at Bob\n";
   Aaron_shoots1(Bob_Initializer,Charlie_Initializer);
   assert(false == Charlie_Initializer);
   
}

/*
   Function: Bob_shoots
   Inputs: A_alive, C_alive
   Outputs: A_alive, C_alive
   Purpose: Change the alive status of whoever has been shot
*/
void Bob_shoots(bool& A_alive,bool& C_alive){
   int p = rand() %100;

   //If p less than threshold probablility and Charlie is alive
   //then shoot Charlie, otherwise shoot Aaron
   if(p <= P_B)
   {
      if(C_alive)
      {
         C_alive = false;
      } else{
         A_alive = false;
      }
   }
} 

/*
   Test driver for Bob_shoots
*/
void test_Bob_shoots()
{
   bool Aaron_Initializer = true, Charlie_Initializer = true;
   
   cout << "Unit Testing 3:Function - Bob_shoots(Aaron_alive,Charlie_alive) \n";

   //Test case 1
   cout << "\t" << "Case 1: Aaron alive,Charlie alive\n";
   cout << "\t" << "\t" << "Bob is shooting at Charlie \n";
   Bob_shoots(Aaron_Initializer,Charlie_Initializer);
   assert(true == Aaron_Initializer);
   
   Aaron_Initializer = false;
   Charlie_Initializer = true;

   //Test case 2
   cout << "\t" << "Case 2: Aaron dead,Charlie alive\n";
   cout << "\t" << "\t" << "Bob is shooting at Charlie \n";
   Bob_shoots(Aaron_Initializer,Charlie_Initializer);
   assert(false == Aaron_Initializer);

   Aaron_Initializer = true;
   Charlie_Initializer = false;

   //Test case 3
   cout << "\t" << "Case 3: Aaron alive,Charlie dead\n";
   Bob_shoots(Aaron_Initializer,Charlie_Initializer);
   assert(false == Charlie_Initializer);
   cout << "\t" << "\t" << "Bob is shooting at Aaron \n";

}

/*
   Function: Charlie_shoots
   Inputs: A_alive, B_alive
   Outputs: A_alive, B_alive
   Purpose: To change the alive status of whoeve was shot
*/
void Charlie_shoots(bool& A_alive,bool& B_alive){
      //If Bob is alive shoot Bob, otherwise shoot Aaron
      if(B_alive)
      {
         B_alive = false;
      } else{
         A_alive = false;
      }
   //}
} 

/*
   Test driver for Charlie shoots
*/
void test_Charlie_shoots(){
   bool Aaron_Initializer = true, Bob_Initializer = true;
   
   cout << "Unit Testing 4:Function - Charlie_shoots(Aaron_alive,Bob_alive) \n";

   //Test case 1
   cout << "\t" << "Case 1: Aaron alive,Bob alive\n";
   cout << "\t" << "\t" << "Charlie is shooting at Bob \n";
   Charlie_shoots(Aaron_Initializer,Bob_Initializer);
   assert(false == Bob_Initializer && true == Aaron_Initializer);

   Aaron_Initializer = false;
   Bob_Initializer = true;

   //Test case 2
   cout << "\t" << "Case 2: Aaron dead,Bob alive\n";
   cout << "\t" << "\t" << "Charlie is shooting at Bob \n";
   Charlie_shoots(Aaron_Initializer,Bob_Initializer);
   assert(false == Bob_Initializer && false == Aaron_Initializer);

   Aaron_Initializer = true;
   Bob_Initializer = false;

   //Test case 3
   cout << "\t" << "Case 3: Aaron alive,Bob dead\n";
   cout << "\t" << "\t" << "Charlie is shooting at Aaron \n";
   Charlie_shoots(Aaron_Initializer,Bob_Initializer);
   assert(false == Aaron_Initializer && false == Bob_Initializer);

}

/*
   Function: Aaron_shoots2
   Inputs: B_alive, C_alive
   Outputs: B_alive, C_alive
   Purpose: To implement Aarons 2nd strategy and to 
            change the alive status of whoever was shot
*/
void Aaron_shoots2(bool& B_alive,bool& C_alive){
   int p = rand() %100 ;
   
   //If Charlie is dead OR Bob is dead then shoot at 
   //whoever is alive. Otherwise if they are both alive,
   //do not shoot 
   if(!C_alive || !B_alive){
      if(p <= P_A){
         if(C_alive){
            C_alive = false; 
         }else{
            B_alive = false; 
         }
      }
   }
}

/*
   Test driver for Aaron_shoots2
*/
void test_Aaron_shoots2(){
   bool Bob_Initializer = true, Charlie_Initializer = true;
   
   cout << "Unit Testing 5:Function - Aaron_shoots2(Bob_alive,Charlie_alive) \n";

   //Test case 1
   cout << "\t" << "Case 1: Bob alive,Charlie alive\n";
   cout << "\t" << "\t" << "Aaron intentionally misses his first shot \n";
   Aaron_shoots2(Bob_Initializer,Charlie_Initializer);
   assert(true == Bob_Initializer && true == Charlie_Initializer);
   cout << "\t" << "\t" << "Both Bob and Charlie are alive" << endl;

   Bob_Initializer = false, Charlie_Initializer = true;
      
   //Test case 2
   cout << "\t" << "Case 2: Bob dead,Charlie alive\n";
   cout << "\t" << "\t" << "Aaron is shooting at Charlie" << endl;
   Aaron_shoots2(Bob_Initializer,Charlie_Initializer);
   assert(false == Bob_Initializer);

   Bob_Initializer = true, Charlie_Initializer = false;
      
   //Test case 3
   cout << "\t" << "Case 3: Bob alive,Charlie dead\n";
   cout << "\t" << "\t" << "Aaron is shooting at Bob" << endl;
   Aaron_shoots2(Bob_Initializer,Charlie_Initializer);
   assert(false == Charlie_Initializer);

}
