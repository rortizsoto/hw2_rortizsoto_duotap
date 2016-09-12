/*
 Serial Print Example for RedBear Duo
 Print a character based on a two-button combination
 Roberto Ortiz-Soto, 9/11/2016
 
 This example code is in the public domain.
 */

// do not use the cloud functions - assume programming through Arduino IDE
#if defined(ARDUINO) 
SYSTEM_MODE(MANUAL); 
#endif

int active_button;                     // set active button
int active_button0;                    // button 1 pushed;connected to D0 and 3V3
int active_button1;                    // button 2 pushed;connected to D1 and 3V3
int active_button2;                    // button 3 pushed;connected to D2 and 3V3
int active_button8;                    // button 4 pushed;connected to D8 and 3V3
int active_button9;                    // button 5 pushed;connected to D9 and 3V3
int active_button12;                   // button 6 pushed;connected to D12 and 3V3
int button0 = D0;                      // button is connected to D0 and 3V3
int button1 = D1;                      // button is connected to D1 and 3V3
int button2 = D2;                      // button is connected to D2 and 3V3
int button8 = D8;                      // button is connected to D8 and 3V3
int button9 = D9;                      // button is connected to D9 and 3V3
int button12 = D12;                    // button is connected to D12 and 3V3
int buttonState;                       // the current reading from the input pin
int lastButtonState = LOW;             // the previous reading from the input pin
int push[7];                           // define array to keep track of which pin is pushed
int i=0;                               // number of buttons pushed counter
int j;                                 // counter to reset push[]
int instruct=0;                      //instructions counter

String line1 = "What do you want to write?";                  // first line of instructions
String line2 = "Choose a letter by pressing the two-button combination shown";      // instructions
String line3 = "a [1,1] b [1,2] c [1,3] d [1,4] e [1,5] f [1,6]";                   // instructions
String line4 = "g [2,1] h [2,2] i [2,3] j [2,4] k [2,5] l [2,6]";                   // instructions
String line5 = "m [3,1] n [3,2] o [3,3] p [3,4] q [3,5] r [3,6]";                   // instructions
String line6 = "s [4,1] t [4,2] u [4,3] v [4,4] w [4,5] x [4,6]";                   // instructions
String line7 = "y [5,1] z [5,2] _ [5,3] & [5,4] ! [5,5] ? [5,6]";                   // instructions
String line8 = "# [6,1] ( [6,2] ) [6,3] + [6,4] - [6,5] * [6,6]";                   // instructions
String line9 = "_ is space bar [5,3]";                                              // instructions
String line10 = "& is return [5,4]";                                                // instructions

// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 10;    // the debounce time; increase if the output flickers

void setup() {
 
  pinMode(button0, INPUT_PULLDOWN);    // sets pin as input
  pinMode(button1, INPUT_PULLDOWN);    // sets pin as input
  pinMode(button2, INPUT_PULLDOWN);    // sets pin as input
  pinMode(button8, INPUT_PULLDOWN);    // sets pin as input
  pinMode(button9, INPUT_PULLDOWN);    // sets pin as input
  pinMode(button12, INPUT_PULLDOWN);    // sets pin as input
  Serial.begin(9600);
  Serial.println(line1);
}

unsigned test_delay = 210000;

void loop() {
    //Delay before printing instructions
    if(test_delay > 0)
    {
        --test_delay;
        return;
    }

    // Only print instructions one time
    if (instruct == 0) { 
     //Display instructions
     Serial.println(line1);
     Serial.println(line2);
     Serial.println(line3);
     Serial.println(line4);
     Serial.printlnf(line5);
     Serial.printlnf(line6);
     Serial.printlnf(line7);
     Serial.println(line8);
     Serial.println(line9);
     Serial.println(line10);
     Serial.println();
     instruct = 1;
   }
  
    // read the state of the switch into a local variable:
    active_button0 = digitalRead(button0);
    active_button1 = digitalRead(button1);
    active_button2 = digitalRead(button2);
    active_button8 = digitalRead(button8);
    active_button9 = digitalRead(button9);
    active_button12 = digitalRead(button12);
  
    //determine which button is active
      if (active_button0 == HIGH) {
      active_button = active_button0;
      }
    else if (active_button1 == HIGH) {
      active_button = active_button1;
      }

    else if (active_button2 == HIGH) {
      active_button = active_button2;
      }

    else if (active_button8 == HIGH) {
      active_button = active_button8;
      }

    else if (active_button9 == HIGH) {
      active_button = active_button9;
      }

    else if (active_button12 == HIGH) {
      active_button = active_button12;
      }

     // If the switch changed, due to noise or pressing:
     if (active_button != lastButtonState) {
      // reset the debouncing timer
      lastDebounceTime = millis();
      }

    if ((millis() - lastDebounceTime) > debounceDelay) {
      // whatever the reading is at, it's been there for longer
      // than the debounce delay, so take it as the actual current state:

      // if the button state has changed:
      if (active_button != buttonState) {
        buttonState = active_button;

        // keep track of which button went HIGH (was pressed)
          if (active_button0 == HIGH) {
            push[i]=1;
            i++;
          }
        
        // keep track of which button went HIGH (was pressed)
          if (active_button1 == HIGH) {
            push[i]=2;
            i++;
          }

        // keep track of which button went HIGH (was pressed)
          if (active_button2 == HIGH) {
            push[i]=3;
            i++;
          }

        // keep track of which button went HIGH (was pressed)
          if (active_button8 == HIGH) {
            push[i]=4;
            i++;
          }

        // keep track of which button went HIGH (was pressed)
          if (active_button9 == HIGH) {
            push[i]=5;
            i++;
          }

        // keep track of which button went HIGH (was pressed)
          if (active_button12 == HIGH) {
            push[i]=6;
            i++;
          }
        }
    }
    if(i==2){
      if(push[0]==1 && push[1]==1){
       Serial.print('a');
       }
      if(push[0]==1 && push[1]==2){
      Serial.print('b');
      }
      if(push[0]==1 && push[1]==3){
       Serial.print('c');
       }
      if(push[0]==1 && push[1]==4){
      Serial.print('d');
      }
      if(push[0]==1 && push[1]==5){
       Serial.print('e');
       }
      if(push[0]==1 && push[1]==6){
      Serial.print('f');
      }
      if(push[0]==2 && push[1]==1){
       Serial.print('g');
       }
      if(push[0]==2 && push[1]==2){
      Serial.print('h');
      }
      if(push[0]==2 && push[1]==3){
       Serial.print('i');
       }
      if(push[0]==2 && push[1]==4){
      Serial.print('j');
      }
      if(push[0]==2 && push[1]==5){
       Serial.print('k');
       }
      if(push[0]==2 && push[1]==6){
      Serial.print('l');
      }
      if(push[0]==3 && push[1]==1){
       Serial.print('m');
       }
      if(push[0]==3 && push[1]==2){
      Serial.print('n');
      }
      if(push[0]==3 && push[1]==3){
       Serial.print('o');
       }
      if(push[0]==3 && push[1]==4){
      Serial.print('p');
      }
      if(push[0]==3 && push[1]==5){
       Serial.print('q');
       }
      if(push[0]==3 && push[1]==6){
      Serial.print('r');
      }
      if(push[0]==4 && push[1]==1){
       Serial.print('s');
       }
      if(push[0]==4 && push[1]==2){
      Serial.print('t');
      }
      if(push[0]==4 && push[1]==3){
       Serial.print('u');
       }
      if(push[0]==4 && push[1]==4){
      Serial.print('v');
      }
      if(push[0]==4 && push[1]==5){
       Serial.print('w');
       }
      if(push[0]==4 && push[1]==6){
      Serial.print('x');
      }
      if(push[0]==5 && push[1]==1){
       Serial.print('y');
       }
      if(push[0]==5 && push[1]==2){
      Serial.print('z');
      }
      if(push[0]==5 && push[1]==3){
       Serial.print(' ');
       }
      if(push[0]==5 && push[1]==4){
      Serial.println();
      }      
      if(push[0]==5 && push[1]==5){
       Serial.print('!');
       }
      if(push[0]==5 && push[1]==6){
      Serial.print('?');
      }
      if(push[0]==6 && push[1]==1){
       Serial.print('#');
       }
      if(push[0]==6 && push[1]==2){
      Serial.print('(');
      }
      if(push[0]==6 && push[1]==3){
       Serial.print(')');
       }
      if(push[0]==6 && push[1]==4){
      Serial.print('+');
      }      
      if(push[0]==6 && push[1]==5){
       Serial.print('-');
       }
      if(push[0]==6 && push[1]==6){
       Serial.print('*');
      }
      //reset push[] array
      for(j=0;j<2;j++){
        push[j]=0;
      }
    }

    //save last button state
    lastButtonState = active_button;
    //reset active_button
    active_button = 0;

    //reset i if greater than or equal to 2
    if(i>=2){
      i=0;
    }
}

