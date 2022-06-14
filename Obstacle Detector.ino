int m11 = 5;
int m12 = 4;
int m21 = 7;
int m22 = 8;
long duration;
int distance;
int trigPin= 3 ,echoPin= 2;

void setup() 
{
 Serial.begin(9600);
pinMode( m11 , OUTPUT);
pinMode( m12 , OUTPUT);
pinMode( m21 , OUTPUT);
pinMode( m22 , OUTPUT);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT); 
Serial.begin(9600);

}

void loop() 
{
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
    // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  if ( distance > 50)
  {
    digitalWrite( m11 , HIGH);
    digitalWrite( m12 , LOW);
    digitalWrite( m21 , HIGH);            // FORWARD DIRECTION
    digitalWrite( m22 , LOW);
  }
  else if ( distance < 50)
  {
    digitalWrite( m11 , LOW);
    digitalWrite( m12 , HIGH);               // RIGHT DIRECTION
    digitalWrite( m21 , HIGH);
    digitalWrite( m22 , LOW);
    delay(300);
    }
}