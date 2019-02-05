#include<LiquidCrystal.h>
LiquidCrystal lcd(2,4,6,8,10,12);

int c=0,a=0,i=0,value=40,b=0;

void setup()
{
  Serial.begin(9600);
    lcd.begin(16,2);
  pinMode(9,OUTPUT); // analog led
  pinMode(11,INPUT);
  pinMode(13,INPUT);
  pinMode(7,OUTPUT); //red signal
  pinMode(5,OUTPUT); // green signal
  lcd.print("SPACE IN PARKING");
   lcd.setCursor(0,1); 
lcd.print(6);  
}

void loop()
{
  int N,M;
  M=digitalRead(11);
  N=digitalRead(13);
  if(N==1 && a!=1 )
 {c++;
   if(c<6)
   {i=i+value;
     digitalWrite(5,1);
     digitalWrite(7,0);
   Serial.print(c);
   Serial.println(" PERSON ENTER THE ROOM ");
   lcd.clear();
   lcd.print("SPACE IN PARKING");
   lcd.setCursor(0,1);
   lcd.print(6-c);
   if(i>=0)
    analogWrite(9,i);
   }
   else if(c>=6)
    {
      if(c==6)
        i=i+value;
        
      lcd.clear();
      delay(500 );
      lcd.print("THE SPACE IS FULL");
      digitalWrite(7,1);
      digitalWrite(5,0);
    }
      value=40;
  Serial.println(i);
     
 a=1;
   }
  if(N==0)
  {
    a=0;
  }
  if(M==1 && b!=1)
  {c--;
   if(c<6)
  {i=i-value;
    Serial.print(c);
   Serial.println(" PERSON LEAVES THE ROOM ");
   lcd.clear();
   lcd.print("SPACE IN PARKING");
   lcd.setCursor(0,1);
   lcd.print(6-c);
   if(i>=0)
    analogWrite(9,i);
    digitalWrite(5,1);
    digitalWrite(7,0);
  }
  else if(c>=6)
    {
      if(c==6)
        i=i-value;
        
      lcd.clear();
      delay(500 );
      lcd.print("THE SPACE IS FULL");
      digitalWrite(7,1);
      digitalWrite(5,0);
    }
    b=1;
    value=40;
   Serial.println(i);
  }
  if(M==0)
  {
    b=0;
  }
delay(500);
digitalWrite(5,0);
 digitalWrite(7,0);
}

