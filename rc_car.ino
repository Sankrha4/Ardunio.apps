#define M1P1 6  //motor1_pin1 => 6
#define M1P2 7  //motor1_pin2 => 7
#define M2P1 8  //motor2_pin1 => 8
#define M2P2 9  //motor2_pin2 => 9
#define M1s 5 //motor1_speed => 5
#define M2s 10 //motor2_speed => 10
#define LED1 11 //set led1 in pin 11 
#define LED2 12 //set led2 in pin 12 
#define BUZ  2 //set buzzer in pin 2 
char bluetooth; 
void setup() {
  // put your setup code here, to run once:
  pinMode(M1P1,OUTPUT);
  pinMode(M1P2,OUTPUT);
  pinMode(M2P1,OUTPUT);
  pinMode(M2P2,OUTPUT);
  pinMode(M1s,OUTPUT);
  pinMode(M2s,OUTPUT);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(BUZ,OUTPUT);
 Serial.begin(9600);
}

void loop()
  {
    bluetooth=Serial.read(); //Rx from bluethooth and store in var
    switch(bluetooth)
    {
      case 'F':
            Forward();
            break;
      case 'B':
            Backward();
            break;
      case 'L':
            Left();
            break;  
      case 'R':
            Right();
            break;
      case 'G':
            Forward_Left();
            break;
      case 'I':
            Forward_Right();
            break;
      case 'H':
            Backward_Left();
            break;
      case 'J':
            Backward_Right();
            break;
      case 'S':
            Stop();
            break;
     default:
          break;
    }
    if(bluetooth=='V')
    {
      BUZZER_ON();
    }
    if(bluetooth=='v')
    {
      BUZZER_OFF();
    }
    if(bluetooth=='W')
    {
      LED_ON();
      
    }
    if(bluetooth=='w')
    {
      LED_OFF();
    }
    
  }

void Forward()
  {
    digitalWrite(M1P1,HIGH);
    digitalWrite(M1P2,LOW);
    digitalWrite(M2P1,HIGH);
    digitalWrite(M2P2,LOW);
    analogWrite(M1s,248);
    analogWrite(M2s,248);
  }

void Backward()
  {
    digitalWrite(M1P1,LOW);
    digitalWrite(M1P2,HIGH);
    digitalWrite(M2P1,LOW);
    digitalWrite(M2P2,HIGH);
    analogWrite(M1s,248);
    analogWrite(M2s,248);
  }

void Right()
  {
    digitalWrite(M1P1,HIGH);
    digitalWrite(M1P2,LOW);
    digitalWrite(M2P1,LOW);
    digitalWrite(M2P2,HIGH);
    analogWrite(M1s,248);
    analogWrite(M2s,248);
  }

void Left()
  {
    digitalWrite(M1P1,LOW);
    digitalWrite(M1P2,HIGH);
    digitalWrite(M2P1,HIGH);
    digitalWrite(M2P2,LOW);
    analogWrite(M1s,248);
    analogWrite(M2s,248);
  }

void Stop()
  {
    digitalWrite(M1P1,LOW);
    digitalWrite(M1P2,LOW);
    digitalWrite(M2P1,LOW);
    digitalWrite(M2P2,LOW);
    analogWrite(M1s,0);
    analogWrite(M2s,0);
  }

void Forward_Left()//G
{
    digitalWrite(M1P1,HIGH);
    digitalWrite(M1P2,LOW);
    digitalWrite(M2P1,HIGH);
    digitalWrite(M2P2,LOW);
    analogWrite(M1s,100);
    analogWrite(M2s,248);
}

void Forward_Right()//I
{
    digitalWrite(M1P1,HIGH);
    digitalWrite(M1P2,LOW);
    digitalWrite(M2P1,HIGH);
    digitalWrite(M2P2,LOW);
    analogWrite(M1s,248);
    analogWrite(M2s,100);
}

void Backward_Left()//H
  {
    digitalWrite(M1P1,LOW);
    digitalWrite(M1P2,HIGH);
    digitalWrite(M2P1,LOW);
    digitalWrite(M2P2,HIGH);
    analogWrite(M1s,100);
    analogWrite(M2s,248);
  }

void Backward_Right()//J
  {
    digitalWrite(M1P1,LOW);
    digitalWrite(M1P2,HIGH);
    digitalWrite(M2P1,LOW);
    digitalWrite(M2P2,HIGH);
    analogWrite(M1s,248);
    analogWrite(M2s,100);
  }
void LED_ON()
{
  digitalWrite(LED1,HIGH);
  digitalWrite(LED2,HIGH);
}


void LED_OFF()
{
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
}
void BUZZER_ON()
{
  digitalWrite(BUZ,HIGH);
}
void BUZZER_OFF()
{
  digitalWrite(BUZ,LOW);  
}
