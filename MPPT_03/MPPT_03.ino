#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
float MPP, offsetVoltage = 0.5047, temp, voltage[255], current[255], power[255], operatingtVoltage , operatingCurrent ;
int i = 1;
void initialize () ;
void displaySetUp () ; 
void inputSetUp () ;
void outputSetUp () ;
void scanData (int) ;
void displayData (int) ;

// Setup starts here //
  void setup() {
    initialize () ;
    displaySetUp () ;
    inputSetUp () ;
    outputSetUp () ; 
}  
// Setup Ends here //


void loop() {   

    
    operatingtVoltage 
    operatingCurrent 

    scanData (i) ;  displayData (i) ; 
    
    if ((power[i] >= 10.0 ) && (((power[i] -power[i-1] )/power[i]) * 100.0 ) <= 1.00 ) {
        while (1) {displayData (i) ;
                  } 
    }  
    
     i++ ; 
   if ( i>=255 ) i = 0 ;
  }           
  
  /***      Main Program Ends      ***/


              /***      Function Definitio      ***/
void initialize () {
  for (int j = 0; j <= 7; j++) {
    digitalWrite(j+22, LOW); 
    }      
  digitalWrite(30, HIGH) ;
  lcd.clear(); lcd.setCursor(0, 0); lcd.print("System Starts Up... ");
  delay(1000); lcd.clear() ;
  digitalWrite(30, LOW) ;
}

  void displaySetUp () {
    lcd.begin(20, 4); 
    
  }

  void inputSetUp () {
       pinMode(A0, INPUT); pinMode(A1, INPUT); pinMode(A8, INPUT); pinMode(A9, INPUT);
  }

  void outputSetUp () {
      for (int i = 22; i <= 30; i++) pinMode(i, OUTPUT);
  }

  void scanData (int i) {
       
   // Loop through the binary values 0 to 255 
     // for ( i = 35; i <= 255; i++) {   
    // Write the binary value to pins 22 to 29
      for (int j = 0; j <= 7; j++) {        
      digitalWrite(j+22, bitRead(i, j));     
    }
    // Read analog input values of A0 and A1               
     voltage[i] = ( analogRead(A0) * 5.00 * 10.0) / 1023.0 ;  
     current[i] = ( analogRead(A1) * 5.00 * 20.0) / 1023.0 ; 
     power[i]   = voltage[i] * current[i] ;
    }
 // }

  void displayData (int i) {
    // Display the input values on the LCD display
    lcd.clear() ;
    lcd.setCursor(0,0);  lcd.print("Loop N0: ");
    lcd.setCursor(0,1);  lcd.print("PV_volt= ");  lcd.setCursor(16,1);  lcd.print("V");
    lcd.setCursor(0,2);  lcd.print("PV_crnt= ");  lcd.setCursor(16,2);  lcd.print("A");
    lcd.setCursor(0,3);  lcd.print("Power  = ");  lcd.setCursor(16,3);  lcd.print("W");

    lcd.setCursor(9,0); lcd.print("   "); 
    lcd.setCursor(9,0); lcd.print(i); 
    lcd.setCursor(14,0); lcd.print("."); lcd.setCursor(15,0); lcd.print(" ");
    lcd.setCursor(9,1); lcd.print(voltage[i]);
    lcd.setCursor(9,2); lcd.print(current[i]);
    lcd.setCursor(9,3); lcd.print(power[i]);
    delay(50); // Adjust the delay time as needed
    lcd.setCursor(14,0); lcd.print(" "); lcd.setCursor(15,0); lcd.print(".");
  }



/*
  for ( i = 1; i <= 255 ; i++ ) {
    if (Power[i] > maxPower) {
      maxPower = Power[i];
      MPP = maxPower;
    }
  }
*/

/*
lcd.clear();
  lcd.setCursor(0, 0);    lcd.print("MPP Found: ");
  lcd.setCursor(12, 0);   lcd.print(MPP);
  lcd.setCursor(0, 1);    lcd.print("Voltage: ");
  lcd.setCursor(11, 1);   lcd.print(voltage[i]);
  lcd.setCursor(0, 2);    lcd.print("Current: ");
  lcd.setCursor(11, 2);   lcd.print(current[i]);
  lcd.setCursor(0, 3);    lcd.print("Power: ");
  lcd.setCursor(11, 3);   lcd.print(Power[i]);
  delay(5000);

*/

