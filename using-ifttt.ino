
int lightSensorPin = A0;
int analogValue = 0;
bool sunlight = false;

void setup() 
{
  pinMode(lightSensorPin, INPUT);
}

void loop()
{
  analogValue = analogRead(lightSensorPin);
  
  if ( analogValue >= 80 and sunlight == false)
  {
      sunlight = true;
      Particle.publish("Sunlight", "light's shinning");
  }
  if ( analogValue < 80 and sunlight == true )
  {
      sunlight = false;
      Particle.publish("Sunlight", "light's gone");
  }
}