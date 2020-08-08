 char Indata;
 char P1 = '1';
 char P2 = '2';
 char P3 = '3';
 int PassCheck = 0;
 int WrongCheck = 0;
 int CPassCheck = 0;
 

void Initialization()
{
      UART1_Init(9600);
      TRISD = 0;
      PortD = 0;
      P1 = EEPROM_Read(0x01);
      P2 = EEPROM_Read(0x02);
      P3 = EEPROM_Read(0x03);
}


void main() {
      Initialization();

      do
      {
          UART1_Write_Text("Enter Password: ");
          while(1)
          {
                if (UART1_Data_Ready())
                {
                      Indata = UART1_Read();

                      if((Indata == P1) && (PassCheck == 0)){PassCheck = 1;}
                      if((Indata == P2) && (PassCheck == 1)){PassCheck = 2;}
                      if((Indata == P3) && (PassCheck == 2)){PassCheck = 3;}

                      if((Indata == 13) && (PassCheck == 3)){PassCheck = 0; WrongCheck = 0; UART1_Write(10); UART1_Write(13); UART1_Write_Text("Correct Password.");CorrectPass();break;}
                      if((Indata == 13) && (PassCheck != 3)){PassCheck = 0; UART1_Write(10); UART1_Write(13); UART1_Write_Text("Wrong Password."); WrongCheck = WrongCheck + 1; if(WrongCheck == 3){WrongPass();}UART1_Write(10); UART1_Write(13); UART1_Write(10); UART1_Write(13);break;}
                      UART1_Write_Text("*");
                }
          }

      } while(1);
}