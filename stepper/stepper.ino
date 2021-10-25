#include <Unistep2.h>
#define RELAY_IN 4  //relay input 腳位
bool relay_able = false;
Unistep2 stepper(14, 13, 12, 3, 4096, 1000); //設置步進馬達的步數和引腳


void able_stepper(){
	digitalWrite(RELAY_IN, HIGH);
  Serial.println("Stepper Abled");
  relay_able = true;
}

void disable_stepper(){
	digitalWrite(RELAY_IN, LOW);
  Serial.println("Stepper Disabled");
  relay_able = false;
}

void move

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(RELAY_IN, OUTPUT);
  digitalWrite(RELAY_IN, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

  char a = 'n';
  a = Serial.read();
  if(a != -1){
    Serial.print("Received: ");
    Serial.println(a);
  }
  delay(2000);
    
  if(a == 'y' && relay_able == false){
    able_stepper();
    delay(2000);
  }else if(a == 'n' && relay_able == true){
    disable_stepper();
    delay(2000);
  }
  
  

  if(relay_able == true){
    stepper.run();

    if( stepper.stepsToGo() == 0){
      delay(500);
      stepper.move(4096);
    }
  }

  
  
  
  
}
