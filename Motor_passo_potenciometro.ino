#include <AFMotor.h>
//sketch para controle de motor de passo
//declaraçao de portas no geral entradas

double passo_total=100;
int const potenciometro_leitura=0;

int porta_motor=2;
int  valorPot;

double numero_de_passo=0;

AF_Stepper motor1 (passo_total,porta_motor);

void setup ()
{
  motor1.setSpeed(10);//velocidade do motor de passo
  Serial.begin(9600);


}




void loop ()
{
     //leitura do potenciometro e converto para sinal depois em angulo em seguida converto para passo
     //converçao direta interfere na velocidade dos passos
     
     valorPot=analogRead(potenciometro_leitura);
     valorPot=map(valorPot,0,1023,0,360);
     numero_de_passo=(valorPot*passo_total)/360;
   
 
   
    
    
   
       Serial.println(valorPot);

      motor1.step(numero_de_passo, FORWARD,SINGLE);//ativa valor de passos horario e ativando uma bobina de cada vez
      motor1.release();
      delay(3000);
     
      
 


}

