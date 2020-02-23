int U_D = 0;
int R_L = 0;
int q = 0;
int w = 0;
int e = 0;
int r = 0;
// output pins as variables for joysticks
int LED1 = 2;
int LED2 = 4;
int LED3 = 7;
int LED4 = 13;
int GREEN_LIGHT = 12;
// LED lights
int JU_D = A1;
int JR_L = A0;
// Joystick inputs
int t;
void setup() {
  // put your setup code here, to run once:
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(GREEN_LIGHT, OUTPUT);

  digitalWrite(GREEN_LIGHT, LOW);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  // define movements
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(GREEN_LIGHT, LOW);
 U_D = (analogRead(JU_D));
 R_L = (analogRead(JR_L));
  Serial.println(U_D);
  Serial.println(R_L);
 // what up and down and left and right is ^
 // Starting up and down
 if (U_D > 800){
  digitalWrite(LED1, HIGH);
  (q = q + 1);
 }else{
  digitalWrite(LED1, LOW);
 }
 //this makes up turn the first light on^
 if (U_D < 300){
   digitalWrite(LED3, HIGH);
   (w = w +1);
 }else{
   digitalWrite(LED3, LOW);
 }
  // this makes down turn on the third light
  
 if (R_L < 300){
   digitalWrite(LED2, HIGH);
   (e = e + 1);
 }else{
   digitalWrite(LED2, LOW);
 }
  // this makes right turn on the second light
 if (R_L > 800){
   digitalWrite(LED4, HIGH);
   (r = r + 1);
 }else{
   digitalWrite(LED4, LOW);
 }
 //this makes left turn on the fourth light
  delay(1000);

 t = (q + (e * 2) + (w * 3) + (r * 4));
if ((t  >= 4) and (t <5))
 {
  digitalWrite(GREEN_LIGHT, HIGH);
  delay(1000);
  Serial.print("ACCESS ACCEPTED");
 
  delay(100);
  // while is an infinite loop if correct that makes the lights stay on
    while(1)
    {
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, HIGH);
      digitalWrite(GREEN_LIGHT, HIGH);
    }
  }
  else if (t >5)
  {Serial.print("ACCESS DENIED");
  // while is an infinte loop that turns all the lights off if incorrect
    while(1){
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
    }
 
  }
 
}
