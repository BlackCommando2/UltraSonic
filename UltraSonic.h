class UltraSonic
{
  private:
    int trigPin;
    int echoPin;
    const int SOUND_SPEED = 0.034;
    const int CM_TO_INCH = 0.393701;
    long duration;
    bool changedist=false;
  public:
    int distanceCm,prevDistanceCm,dist;
    int distanceInch,prevDistanceInch;
    UltraSonic(){};
    UltraSonic(int trigpin,int echopin)
    {
      this->echoPin = echopin;
      this->trigPin = trigpin;
      pinMode(trigPin, OUTPUT);
      pinMode(echoPin, INPUT);
    }

    int getReadings()
    {
      //Serial.println("Readings");
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      duration = pulseIn(echoPin, HIGH);
      delay(50);
      distanceCm = int(duration * 0.017);
      return distanceCm;
    }
    
    int getReadingsCm()
    {
      return getReadings();
    }

    int getReadingsInch()
    {
      return getReadings()*CM_TO_INCH;
    }

    int getReadingsCmOnChange(int change=1)
    {
      dist=getReadingsCm();
      if(abs(prevDistanceCm-dist)>=change)
      {
        changedist=true;  
      }

      if(changedist)
      {
        prevDistanceCm=dist;
        changedist=false;
        return prevDistanceCm;
      }
      else
      {
        return 0;
      }
    }

    int getReadingsInchOnChange(int change=1)
    {
      dist=getReadingsInch();

      if(abs(prevDistanceInch-dist)>=change)
      {
        changedist=true;  
      }

      if(changedist)
      {
        prevDistanceInch=dist;
        changedist=false;
        return prevDistanceInch;
      }

      else
      {
        return 0;
      }

    }
};