int led=8;
int button=7;
int stat=0;
int buzzer=4;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 100; 
unsigned long buttonstate=0;
unsigned long lbuttonstate=0;
unsigned long reading=0;

void setup() {
Serial.begin(9600);
pinMode(led,OUTPUT);
pinMode(button,INPUT_PULLUP);
pinMode(buzzer,OUTPUT);
digitalWrite(led,LOW);
}

void loop() {
  // First Reading
  reading=!digitalRead(button);

  //Reset last debounce time at noticed change
  if(reading!=lbuttonstate){
    lastDebounceTime=millis();
  }

  //Hold read value for 50ms and then set button state
  if((millis()-lastDebounceTime)>debounceDelay){
    if(reading!=buttonstate){
      buttonstate=reading;
    if(buttonstate){
      stat=!stat;
    }
    if(stat){
      digitalWrite(led,HIGH);
      digitalWrite(buzzer,HIGH);
    }
    else{
      digitalWrite(led,LOW);
      digitalWrite(buzzer,LOW);
    }
    }
  } 
  //Set last button state
  lbuttonstate=reading;
  
  Serial.print(stat);
}
