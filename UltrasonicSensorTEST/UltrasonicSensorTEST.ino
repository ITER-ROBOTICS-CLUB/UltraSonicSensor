const int trigPin = 8;
const int echoPin = 9;
int measuredDist;
unsigned long duration,distance;
void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  measuredDist = Dist(); 
  Serial.println(measuredDist);

}

int Dist()
{
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin,HIGH);
  //distance = (340*100*(duration/2))/1000000;
  distance = duration*0.017;
  return distance;
}
