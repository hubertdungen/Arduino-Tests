/*  Show temperature with  TMP36/LM35/2N3904 temperature sensor
  copy right John Yu
  connect VS1838B to  D10 see http://osoyoo.com/?p=160
*/

//LED 4DIGITS

int a = 1;
int b = 2;
int c = 3;
int d = 4;
int e = 5;
int f = 6;
int g = 7;
int p = 8;

int DT = 4;

int d4 = 9;
int d3 = 10;
int d2 = 11;
int d1 = 12;

int x = 100;
long del = 600;
int interval=50000;

int num;
int dig1 = 0;
int dig2 = 0;
int dig3 = 0;
int dig4 = 0;

int GND1 = 12;
int GND2 = 11;
int GND3 = 10;
int GND4 = 9;

//TEMP
int analog_no = 5 ;// define A5 as input signal pin

 void setup() {
  //LED 4DIG
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(p, OUTPUT);

  
 Serial.begin(9600);
}

void loop()
{
  /////TEMP
  int pin_value;
  int temperature;
  
  int rawvoltage = analogRead(analog_no);
  float volts= rawvoltage/205.0;
  float celsiustemp= 100.0 * volts - 50;
  float fahrenheittemp= celsiustemp * 9.0/5.0 + 32.0;
  Serial.print(celsiustemp);
  Serial.println(" Celsius");
  Serial.print(fahrenheittemp);
  Serial.println(" Fahrenheit");
  /*temperature = (125*pin_value)>>8 ;
  Serial.print("Current temperature is ") ;
  Serial.print(temperature) ;
  Serial.println("C");
  */
  //delay(400);
  //END

  //LED 4DIG
 float t = celsiustemp;
    num = t;
    dig1 = num / 10;
    num = num - (dig1 * 10);
    dig2 = num ;
    dig3 =  111;
    dig4 = 222;
  Serial.println(dig1);
  delay(600);
  Serial.println(dig2);
  delay(600);  
  Serial.println(dig3);
  delay(600);
  Serial.println(dig4);
  delay(600);
  long i;
    for (i=0;i<1000000;i++)
      {
        
        showNum(i);
      }

  //END

}

 void showNum(long n)
{
//          digitalWrite( GND4, LOW);   digit 4
        clearLEDs();
        pickDigit(4);
        pickNumber(dig4);
        delay(DT);
        digitalWrite( GND4, HIGH);
        delayMicroseconds(del);

        clearLEDs();
        pickDigit(3);
        //digitalWrite( GND3, LOW);    digit 3
        pickNumber(dig3);
        delay(DT);
        //digitalWrite( GND3, HIGH);
        delayMicroseconds(del);

        clearLEDs();
        pickDigit(2);
        //digitalWrite( GND2, LOW);   digit 2
        pickNumber(dig2);
        delay(DT);
        //digitalWrite( GND2, HIGH);
        delayMicroseconds(del);

        clearLEDs();
        pickDigit(1);
        //digitalWrite( GND1, LOW);   digit 1
        pickNumber(dig1);
        delay(DT);
        //digitalWrite( GND1, HIGH);
        delayMicroseconds(del);
        
    n++;

    if (digitalRead(13) == HIGH)
      {
        n = 0;
       }
}

void pickDigit(int x) {
digitalWrite(d1, HIGH);
digitalWrite(d2, HIGH);
digitalWrite(d3, HIGH);
digitalWrite(d4, HIGH);

switch(x)
{
case 1:
digitalWrite(d1, LOW);
break;
case 2:
digitalWrite(d2, LOW);
break;
case 3:
digitalWrite(d3, LOW);
break;
default:
digitalWrite(d4, LOW);
break;
}
}

void pickNumber(int x)
{
switch(x)
{
default:
zero();
break;
case 1:
one();
break;
case 2:
two();
break;
case 3:
three();
break;
case 4:
four();
break;
case 5:
five();
break;
case 6:
six();
break;
case 7:
seven();
break;
case 8:
eight();
break;
case 9:
nine();
break;
case 111: o(); break;
case 222: C(); break;
}
}

void dispDec(int x)
{
digitalWrite(p, HIGH);
}

void clearLEDs()
{
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, LOW);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
digitalWrite(p, LOW);
}

void zero()
{
digitalWrite(a, HIGH);
digitalWrite(b, HIGH);
digitalWrite(c, HIGH);
digitalWrite(d, HIGH);
digitalWrite(e, HIGH);
digitalWrite(f, HIGH);
digitalWrite(g, LOW);
}

void one()
{
digitalWrite(a, LOW);
digitalWrite(b, HIGH);
digitalWrite(c, HIGH);
digitalWrite(d, LOW);
digitalWrite(e, LOW);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
}

void two()
{
digitalWrite(a, HIGH);
digitalWrite(b, HIGH);
digitalWrite(c, LOW);
digitalWrite(d, HIGH);
digitalWrite(e, HIGH);
digitalWrite(f, LOW);
digitalWrite(g, HIGH);
}

void three()
{
digitalWrite(a, HIGH);
digitalWrite(b, HIGH);
digitalWrite(c, HIGH);
digitalWrite(d, HIGH);
digitalWrite(e, LOW);
digitalWrite(f, LOW);
digitalWrite(g, HIGH);
}

void four()
{
digitalWrite(a, LOW);
digitalWrite(b, HIGH);
digitalWrite(c, HIGH);
digitalWrite(d, LOW);
digitalWrite(e, LOW);
digitalWrite(f, HIGH);
digitalWrite(g, HIGH);
}

void five()
{
digitalWrite(a, HIGH);
digitalWrite(b, LOW);
digitalWrite(c, HIGH);
digitalWrite(d, HIGH);
digitalWrite(e, LOW);
digitalWrite(f, HIGH);
digitalWrite(g, HIGH);
}

void six()
{
digitalWrite(a, HIGH);
digitalWrite(b, LOW);
digitalWrite(c, HIGH);
digitalWrite(d, HIGH);
digitalWrite(e, HIGH);
digitalWrite(f, HIGH);
digitalWrite(g, HIGH);
}

void seven()
{
digitalWrite(a, HIGH);
digitalWrite(b, HIGH);
digitalWrite(c, HIGH);
digitalWrite(d, LOW);
digitalWrite(e, LOW);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
}

void eight()
{
digitalWrite(a, HIGH);
digitalWrite(b, HIGH);
digitalWrite(c, HIGH);
digitalWrite(d, HIGH);
digitalWrite(e, HIGH);
digitalWrite(f, HIGH);
digitalWrite(g, HIGH);
}

void nine()
{
digitalWrite(a, HIGH);
digitalWrite(b, HIGH);
digitalWrite(c, HIGH);
digitalWrite(d, HIGH);
digitalWrite(e, LOW);
digitalWrite(f, HIGH);
digitalWrite(g, HIGH);
}
void o()
{
  digitalWrite( a, LOW);
  digitalWrite( b, LOW);
  digitalWrite( c, HIGH);
  digitalWrite( d, HIGH);
  digitalWrite( e, HIGH);
  digitalWrite( f, LOW);
  digitalWrite( g, LOW);
}

void C()
{
  digitalWrite( a, LOW);
  digitalWrite( b, HIGH);
  digitalWrite( c, HIGH);
  digitalWrite( d, LOW);
  digitalWrite( e, LOW);
  digitalWrite( f, LOW);
  digitalWrite( g, HIGH);
}
