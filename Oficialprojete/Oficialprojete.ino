#include <LiquidCrystal.h>  
LiquidCrystal lcd(8, 9, 4, 5, 6, 7); 

#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

// DEFINIÇÕES DE PINOS
#define pinRx 10
#define pinTx 11

// DEFINIÇÕES
#define volumeMP3 30

#define DEBUG
// INSTANCIANDO OBJETOS
SoftwareSerial playerMP3Serial(pinRx, pinTx);

DFRobotDFPlayerMini playerMP3;


 int porta;
 String botao;
 int estado = 1;
 int ponto = 0;
 boolean resposta = false;
 int aux = 0; 



void setup(){  
  lcd.begin(16, 2);
Serial.begin(9600);
 playerMP3Serial.begin(9600);

  Serial.println();
  Serial.println(F("Iniciando DFPlayer ... (Espere 3~5 segundos)"));

  if (!playerMP3.begin(playerMP3Serial)) {  // COMUNICAÇÃO REALIZADA VIA SOFTWARE SERIAL
    Serial.println(F("Falha ao iniciar:"));
    Serial.println(F("1.Confira as conexões!"));
    Serial.println(F("2.Confira o cartão SD!"));
    while(true){
      delay(0);
    }
  }

  Serial.println(F("DFPlayer ligado!"));

  playerMP3.volume(volumeMP3);
  
  #ifdef DEBUG
    Serial.println("Fim Setup");
  #endif 
  
}

void loop(){ 

  switch (estado){
  case 1: 
  ponto = 0;

  playerMP3.playFolder(1,3);             
  lcd.clear();
  lcd.home();
  lcd.setCursor(4,0);  
  lcd.print("Projete"); 
  lcd.setCursor(2,1);  
  lcd.print("Equipe 1102");
    
  delay (2000);
  
  lcd.clear();
  lcd.home();
  lcd.setCursor(2,0);
  lcd.print("WONDER GAME");   
            
  delay (2000);
   
  lcd.clear();
  lcd.home();  
  lcd.print("Letra A para "); 
  lcd.setCursor(6,1);  
  lcd.print("Cima");
    
  delay (2000);
   
  lcd.clear();
  lcd.home();  
  lcd.setCursor(2,0);
  lcd.print("Letra B para"); 
  lcd.setCursor(4,1);  
  lcd.print("baixo");
    
  delay (2000);
  
  lcd.clear();
  lcd.home();  
  lcd.print("Para confirmar"); 
  lcd.setCursor(0,1);  
  lcd.print("aperte select");
    
  delay (3000);
    
  lcd.clear();
  lcd.home();  
  lcd.print("Para repetir use "); 
  lcd.setCursor(0,1);  
  lcd.print("o botao direito");
    
  delay (3000);
    
  lcd.clear();
  lcd.home();
  lcd.setCursor(2,0);
  lcd.print("Para pular");  
  lcd.setCursor(1,1);
  lcd.print("aperte select");

  
  delay (3500);
  
  playerMP3.playFolder(1,5);              
  lcd.clear();
  lcd.home();  
  lcd.print("Cada acerto"); 
  lcd.setCursor(0,1);  
  lcd.print(" Vale 5 pontos");
    
  delay (5000);   
 
  estado = 50;
    
  break;

    
 case 50 :
  playerMP3.playFolder(2,1);            
  lcd.clear();
  lcd.home();  
  lcd.print("1:Qual a primeira"); 
  lcd.setCursor(0,1);  
  lcd.print("capital do brasil");
    
    delay (1500);
    
   for(int cont=0; cont <2; cont++){
      lcd.scrollDisplayLeft();
      delay (100); 
      }     
    
   delay (1500);
    
    
    
   lcd.clear();
   lcd.home();  
   lcd.print("A-Salvador()"); 
   lcd.setCursor(0,1);  
   lcd.print("B-RJ()");
        
   delay (200);
   estado = 51;
   aux =0; 
    
   break;
    
   case 51 :
     
   porta = analogRead (0);
   lcd_Shield();
  
   if (botao == "Cima"){
   playerMP3.playFolder(1,4);                       
   lcd.clear();
   lcd.home();  
   lcd.print("A-Salvador(X)"); 
   lcd.setCursor(0,1);  
   lcd.print("B-RJ()");
   resposta = true;
   aux++;

   }

   else if (botao == "Baixo"){
    
   playerMP3.playFolder(1,4);             
   lcd.clear();
   lcd.home();  
   lcd.print("A-Rio de janeiro()"); 
   lcd.setCursor(0,1);  
   lcd.print("B-RJ(X)");
              
   resposta = false;
   aux++;
   }
    
             
   else if (botao == "Select"){
   if (aux !=0){
     
   if(resposta == true){
   playerMP3.playFolder(1,1);    
   lcd.clear();
   lcd.home();  
   lcd.print("Acertou!"); 
   lcd.setCursor(0,1);  
   lcd.print(" ");

     delay (2000);
     
     for(int cont=0; cont <4; cont++){
      lcd.scrollDisplayLeft();
      delay (100); 
      }   
     
     
   ponto = ponto + 5;
   estado = 60; 
   delay (1000);
   }
                
    if(resposta == false){
    playerMP3.playFolder(1,2);  
    lcd.clear();
    lcd.home();  
    lcd.print("Errou :("); 
    lcd.setCursor(0,1);  
    lcd.print(" ");
      
      delay (2000);
      
       for(int cont=0; cont <11; cont++){
      lcd.scrollDisplayLeft();
      delay (100); 
      }   
      
      
  estado = 60;  
    delay (1000);
    }            
  } 
    
    else{
    playerMP3.playFolder(1,6);  
    lcd.clear();
    lcd.home();  
    lcd.print("Voce pulou"); 
    lcd.setCursor(0,1);  
    lcd.print(" ");
    
    estado = 60;  
    delay (2000);
    }
    }    
             
     else if (botao =="Esquerda"){
     estado = 50;
     }
     
     else if (botao !="vazio"){
     tecla_Error();
     }
     
     break;
                
   
  case 60 :
  playerMP3.playFolder(2,3);
  lcd.clear();
  lcd.home();
  lcd.print("o fogo foi"); 
  lcd.setCursor(0,1);
  lcd.print("descoberto no periodo");

   delay (1500);
     
   for(int cont=0; cont <4; cont++){
        lcd.scrollDisplayLeft();
        delay (100); 
          }
   delay (1500);



   lcd.clear();
   lcd.home();
   lcd.print("neolitico()"); 
   lcd.setCursor(0,1);
   lcd.print("paleolitico()");
    
      delay (1500);
     
   for(int cont=0; cont <2; cont++){
        lcd.scrollDisplayLeft();
        delay (100); 
          }
   delay (1500);
     
   delay (200);
   estado = 61;
   aux =0; 

   break;

   case 61 :

   porta = analogRead (0);
   lcd_Shield();

   if (botao == "Cima"){

   playerMP3.playFolder(1,4);
   lcd.clear();
   lcd.home();
   lcd.print("neolitico(X)"); 
   lcd.setCursor(0,1);
   lcd.print("paleolitico()");

      delay (1500);
     
   for(int cont=0; cont <4; cont++){
        lcd.scrollDisplayLeft();
        delay (100); 
          }
   delay (1500);
     
   resposta = false;
   aux++;

   }


   else if (botao == "Baixo"){

   playerMP3.playFolder(1,4);
   lcd.clear();
   lcd.home();
   lcd.print("neolitico()"); 
   lcd.setCursor(0,1);
   lcd.print("paleolitico(x)");

      delay (1500);
     
   for(int cont=0; cont <4; cont++){
        lcd.scrollDisplayLeft();
        delay (100); 
          }
   delay (1500);
     
   resposta = true;
   aux++;
   }

   else if (botao == "Select"){
   if (aux !=0){

   if(resposta == true){
   playerMP3.playFolder(1,1);
   lcd.clear();
   lcd.home();
   lcd.print("Acertou!"); 
   lcd.setCursor(0,1);
   lcd.print(" ");

  ponto = ponto + 5;
   estado = 70;
   delay (1500);
   }



    if(resposta == false){
    playerMP3.playFolder(1,2);
    lcd.clear();
    lcd.home();
    lcd.print(" Errou..."); 
    lcd.setCursor(0,1);
    lcd.print(" ");

       for(int cont=0; cont <8; cont++){
        lcd.scrollDisplayLeft();
        delay (100); 
          }
    estado = 70;
    delay (1500);
    }
  }

  else{
    playerMP3.playFolder(1,6);
    lcd.clear();
    lcd.home();
    lcd.print("Voce pulou."); 
    lcd.setCursor(0,1);
    lcd.print(" ");

    estado = 70;
    delay (1000);
    }
    }

     else if (botao == "Esquerda"){
     estado = 60;
     }

     else if (botao != "vazio"){
     tecla_Error();
     }

     break;
     
     
    
  case 70:
  playerMP3.playFolder(2,4);
  lcd.clear();
  lcd.home();
  lcd.print("qual continente"); 
  lcd.setCursor(0,1);
  lcd.print("o brasil está");

   delay (1500);
     
   for(int cont=0; cont <4; cont++){
        lcd.scrollDisplayLeft();
        delay (100); 
          }
   delay (1500);



   lcd.clear();
   lcd.home();
   lcd.print("America do Norte()"); 
   lcd.setCursor(0,1);
   lcd.print("America do Sul()");

    
   delay (200);
   estado = 71;
   aux =0; 

   break;

  case 71 :

   porta = analogRead (0);
   lcd_Shield();

   if (botao == "Cima"){

   playerMP3.playFolder(1,4);
   lcd.clear();
   lcd.home();
   lcd.print("America do Norte(X)"); 
   lcd.setCursor(0,1);
   lcd.print("America do Sul ()");
     
   resposta = false;
   aux++;

   
   }


   else if (botao == "Baixo"){

   playerMP3.playFolder(1,4);
   lcd.clear();
   lcd.home();
   lcd.print("America do Norte()"); 
   lcd.setCursor(0,1);
   lcd.print("America do Sul (X)");
     
   delay (1500);
     
   for(int cont=0; cont <2; cont++){
        lcd.scrollDisplayLeft();
        delay (100); 
          }
   delay (1500);
     
   resposta = true;
   aux++;
 
   }

else if (botao == "Select"){
   if (aux !=0){

   if(resposta == true){
   playerMP3.playFolder(1,1);
   lcd.clear();
   lcd.home();
   lcd.print("Acertou!"); 
   lcd.setCursor(0,1);
   lcd.print(" ");

     for(int cont=0; cont <1; cont++){
        lcd.scrollDisplayLeft();
        delay (100); 
          }

 ponto = ponto + 5;
   estado = 80;
   delay (1000);
   }



    if(resposta == false){
    playerMP3.playFolder(1,2);
    lcd.clear();
    lcd.home();
    lcd.print(" Errou..."); 
    lcd.setCursor(0,1);
    lcd.print(" ");
    
      delay (1500);
      
       for(int cont=0; cont <8; cont++){
        lcd.scrollDisplayLeft();
        delay (100); 
          }
      
    estado = 80;
    delay (1000);
    }
  }
  
    else{
    playerMP3.playFolder(1,6);
    lcd.clear();
    lcd.home();
    lcd.print("Voce pulou."); 
    lcd.setCursor(0,1);
    lcd.print(" ");

    estado = 80;
    delay (1000);
    }
    }
  
     else if (botao == "Esquerda"){
     estado = 70;
     }

     else if (botao != "vazio"){
     tecla_Error();
     }

     break;
     
     
     
     
  case 80:
  playerMP3.playFolder(2,7);
  lcd.clear();
  lcd.home();  
  lcd.print("quantos estados"); 
  lcd.setCursor(0,1);  
  lcd.print("tem no brasil?");
    
   delay (1500);
  
   for(int cont=0; cont <21; cont++){
      lcd.scrollDisplayLeft();
      delay (150); 
      }     
   delay (1500);
    
    
    
   lcd.clear();
   lcd.home();  
   lcd.print("26()"); 
   lcd.setCursor(0,1);  
   lcd.print("27()");
     
   delay (1500);
  
        
   delay (200);
   estado = 81;
   aux =0; 
    
   break;
    
   
     
   case 81:
     
   porta = analogRead (0);
   lcd_Shield();

   if (botao == "Cima"){
   playerMP3.playFolder(1,4);           
   lcd.clear();
   lcd.home();  
   lcd.print("26(X)"); 
   lcd.setCursor(0,1);  
   lcd.print("27()");

     delay (1500);
      
   resposta =true;
   aux++;

   }

   else if (botao == "Baixo"){
   playerMP3.playFolder(1,4);           
   lcd.clear();
   lcd.home();  
   lcd.print("26()"); 
   lcd.setCursor(0,1);  
   lcd.print("27(X)");
              
      delay (1500);
     

             
   resposta = false;
   aux++;
   }
    
             
   else if (botao == "Select"){
   if (aux !=0){
     
   if(resposta == true){
   playerMP3.playFolder(1,1);
   lcd.clear();
   lcd.home();  
   lcd.print("Acertou!"); 
   lcd.setCursor(0,1);  
   lcd.print(" ");

     delay (1500);
     
     for(int cont=0; cont <3; cont++){
      lcd.scrollDisplayLeft();
      delay (150); 
      }   
     
   ponto = ponto + 5;
   estado = 90; 
   delay (500);
   }
                
    if(resposta == false){
    playerMP3.playFolder(1,2);
    lcd.clear();
    lcd.home();  
    lcd.print("Errou?"); 
    lcd.setCursor(0,1);  
    lcd.print(" ");
      
      delay (1500);
      
       for(int cont=0; cont <2; cont++){
      lcd.scrollDisplayLeft();
      delay (150); 
      }   
      
  estado = 90;  
    delay (1000);
    }            
   } 
    
    else{
    playerMP3.playFolder(1,6);
    lcd.clear();
    lcd.home();  
    lcd.print("Voce pulou"); 
    lcd.setCursor(0,1);  
    lcd.print(" ");
    
    estado = 90;  
    delay (1000);
    }
    }    
             
     else if (botao == "Esquerda"){
     estado = 80;
     }

     else if (botao != "vazio"){
     tecla_Error();
     }

     break;
    
     
      case 90:
      playerMP3.playFolder(2,2);
      lcd.clear();
      lcd.home();  
      lcd.print("Bioma exclusivo"); 
      lcd.setCursor(0,1);  
      lcd.print("do Brasil");
    
      delay (1500);
     
   for(int cont=0; cont <11; cont++){
      lcd.scrollDisplayLeft();
      delay (100); 
    }   
     
     
   delay (1500);  
   
   lcd.clear();
   lcd.home();  
   lcd.print("Cerrado()"); 
   lcd.setCursor(0,1);  
   lcd.print("Caatinga()");    
        
   delay (300);
   estado = 91;
   aux =0; 
    
   break;
    
   
     
   case 91:
     
   porta = analogRead (0);
   lcd_Shield();

   if (botao == "Cima"){
   playerMP3.playFolder(1,4);           
   lcd.clear();
   lcd.home();  
   lcd.print("Cerrado(X)"); 
   lcd.setCursor(0,1);  
   lcd.print("Caatinga()");

   delay (1500);
     
   resposta = false;
   aux++;

   }

   else if (botao == "Baixo"){
   playerMP3.playFolder(1,4);           
   lcd.clear();
   lcd.home();  
   lcd.print("Cerrado()"); 
   lcd.setCursor(0,1);  
   lcd.print("Caatinga(X)");
     
             
   resposta = true;
   aux++;
   }
    
             
   else if (botao == "Select"){
   if (aux !=0){
     
   if(resposta == true){
   playerMP3.playFolder(1,1);
   lcd.clear();
   lcd.home();  
   lcd.print("Acertou!"); 
   lcd.setCursor(0,1);  
   lcd.print(" ");

      delay (1500);
     
     for(int cont=0; cont <12; cont++){
      lcd.scrollDisplayLeft();
      delay (150); 
      }   
     
   ponto = ponto + 5;
   estado = 4;  
   delay (500);
   }
                
    if(resposta == false){
    playerMP3.playFolder(1,2);
    lcd.clear();
    lcd.home();  
    lcd.print("Errou?"); 
    lcd.setCursor(0,1);  
    lcd.print(" ");
      
       delay (1500);
      
       for(int cont=0; cont <14; cont++){
      lcd.scrollDisplayLeft();
      delay (150); 
      }   
      
  estado = 4; 
    delay (1000);
    }            
  }            
  
    
    else{
    playerMP3.playFolder(1,6);
    lcd.clear();
    lcd.home();  
    lcd.print("Voce pulou"); 
    lcd.setCursor(0,1);  
    lcd.print(" ?");
    
    estado = 4; 
    delay (1000);
    }
    }   
             
     else if (botao == "Esquerda"){
     estado = 90;
     }

     else if (botao != "vazio"){
     tecla_Error();
     }

     break;
    
    case 4: 
    
     lcd.clear();
     lcd.home();  
     lcd.print("Total: "); 
     lcd.setCursor(7,0);  
     lcd.print(ponto); 
     lcd.setCursor(9,0);  
     lcd.print("Pontos");

    if (ponto == 0) {
      
       lcd.setCursor(0,1);  
       lcd.print("Muito pouco");
       playerMP3.playFolder(3,1);

      delay (1500);
      
       for(int cont=0; cont <2; cont++){
      lcd.scrollDisplayLeft();
      delay (100); 
      }   
    }
    
    else if (ponto == 5 || ponto == 10) {
      lcd.setCursor(0,1);
      lcd.print("Pouco");
      playerMP3.playFolder(3,2);
      
      delay (1500);
      
       for(int cont=0; cont <6; cont++){
      lcd.scrollDisplayLeft();
      delay (150); 
      }   
    }
    
    else if (ponto == 15 || ponto == 20) {
      lcd.setCursor(0,1);
      lcd.print("bom");
      playerMP3.playFolder(3,3);
      
  delay (1500);
      
       for(int cont=0; cont <6; cont++){
      lcd.scrollDisplayLeft();
      delay (150); 
      }   
    }
    
     else if (ponto == 25) {
      lcd.setCursor(0,1);
      lcd.print("Nota máxima");
      playerMP3.playFolder(3,4);
       
       delay (1500);
      
       for(int cont=0; cont <15; cont++){
      lcd.scrollDisplayLeft();
      delay (150); 
      }   
    }
    
            estado = 1;
            ponto = 0;

            delay (3000);

            break;
  }
} 
             
 void lcd_Shield () {

   botao = "vazio";

   if (porta < 100) {  
      botao = "Direita";  
   }  
   else if (porta < 200) {  
      botao = "Cima";  
   }  
   else if (porta < 400){  
      botao = "Baixo";  
   }  
   else if (porta < 600){  
      botao = "Esquerda";  
   }  
   else if (porta < 800){  
      botao = "Select";  
   } 
}
void tecla_Error(){
  lcd.clear();
  lcd.home();
  lcd.print ("Tecla errada");
  delay (1000); 
}  
