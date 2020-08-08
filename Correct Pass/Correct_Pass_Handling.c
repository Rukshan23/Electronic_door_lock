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


void CorrectPass()
{
            UART1_Write(10);
            UART1_Write(13);
            UART1_Write(10);
            UART1_Write(13);
            UART1_Write_Text("Select one of the below Options: ");
            UART1_Write(10);
            UART1_Write(13);
            UART1_Write(10);
            UART1_Write(13);
            UART1_Write_Text("1) Press Y to Lock.");
            UART1_Write(10);
            UART1_Write(13);
            UART1_Write_Text("2) Press N to Unlock.");
            UART1_Write(10);
            UART1_Write(13);
            UART1_Write_Text("3) Press C to Change Password.");
            UART1_Write(10);
            UART1_Write(13);
            UART1_Write(10);
            UART1_Write(13);
            UART1_Write_Text("Waiting for Response: ");
            
            while(1)
            {
                  if (UART1_Data_Ready())
                  {
                        Indata = UART1_Read();

                        if((Indata == 'Y') || (Indata == 'y')){UART1_Write_Text("Y"); PortD.F0 = 1; PortD.F1 = 0; UART1_Write(10); UART1_Write(13); UART1_Write(10); UART1_Write(13); break;}
                        if((Indata == 'N') || (Indata == 'n')){UART1_Write_Text("N"); PortD.F0 = 0; PortD.F1 = 1; UART1_Write(10); UART1_Write(13); UART1_Write(10); UART1_Write(13); break;}
                        if((Indata == 'C') || (Indata == 'c')){UART1_Write_Text("C"); UART1_Write(10); UART1_Write(13); UART1_Write(10); UART1_Write(13); UART1_Write_Text("Enter New Password: "); PassChange();break;}


                  }
            }
}




