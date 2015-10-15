                                                         // THE PNEUMATIC CODE //
// THis is the stock pneumatic code with timed solenoids //

int upsensor = 5;       
int middlesensor = 9;
int downsensor = 12;
int upshiftcoil = A0; 
int downshiftcoil = A2;
int launch = A4;

unsigned long button_time = 0;  
unsigned long last_button_time = 0; 



void setup ()
{
Serial.begin(9600);
pinMode(upsensor,INPUT);
pinMode(middlesensor,INPUT);
pinMode(downsensor,INPUT);
pinMode(downshiftcoil,OUTPUT);
pinMode(upshiftcoil,OUTPUT);
pinMode(launch,OUTPUT);//launch control
digitalWrite(launch,LOW);
digitalWrite(downshiftcoil,LOW);
digitalWrite(upshiftcoil,LOW);
attachInterrupt(1,upshift,RISING);
attachInterrupt(0,downshift,RISING);
}

void loop () 
{
}

void upshift ()                                   
{
 double x = 0;
 
  button_time = millis();

if (button_time - last_button_time > 250)
 {

  if(digitalRead(middlesensor) == HIGH )  
   {
       
      do 
     {
      digitalWrite(launch,HIGH);
      digitalWrite(upshiftcoil,HIGH);
      for(double i = 0 ; i <= 1000 ; i++ )
      {}
      x++; 
     }
    
    while (digitalRead(upsensor) != HIGH && (x <= 275));
    
    digitalWrite(launch,LOW); 
   
  if (digitalRead(upsensor) == HIGH)
  {
    Serial.println("upshift ");
  }
  
 }  
    digitalWrite(upshiftcoil,LOW);

last_button_time = button_time;
 }
} 


void downshift () 
{
 double x = 0;
 button_time = millis(); 
 if (button_time - last_button_time > 250)
  
  {
  if(digitalRead(middlesensor) == HIGH )
  {
    do
  {
    digitalWrite(downshiftcoil,HIGH);
    for(double i = 0 ; i <= 1000 ; i++ )
    {}
    x++;
  }
  
  while(digitalRead(downsensor) != HIGH  && (x <= 275) ); // Was made in the middle of the road at Mid night........by bavo and michiel :p  
 
  if( digitalRead(downsensor) == HIGH)
 { 
  Serial.println("downshift ");
 }
  } 
  digitalWrite(downshiftcoil,LOW);

last_button_time = button_time;
 }
}