#define div 64
#define PI 3.14159

int potPin = A1;
int powerPin = 13;
int ledPin = 9;
int sine_table[div];
int j=0;

void setup()
{
 Serial.begin(9600);
 pinMode(powerPin,OUTPUT);
 digitalWrite(powerPin,HIGH);
 pinMode(ledPin,OUTPUT);
 Serial.print(div);
 for(int i=0; i<div; i++){
  sine_table[i]=200*abs(sin((float)2*PI*i/(float)div));
 }
  
 
}

void loop()
{
  int val=analogRead(potPin);
  long speedDelay= 20+(val*(float)200/980);
  Serial.print(val);
  Serial.print(" ");
  Serial.println(speedDelay);
  analogWrite(ledPin,sine_table[j]);
  delay(speedDelay);
  j=(j+1)%div;
}
