This c code has written for MikroC pro for pic Compiler tool. 
Password = " 123 "
Other keys - 	"Y" or "y" for Locking the door
		"N" or "n" for Unlocking the door
		"C" or "c" use for change the password.
If user changed password EEPROM will save the new password and can be use further.
We have used 2 LEDs for indicate the "Lock" & "Unlock" because in proteus we can't be able to show working purpose of 
DC motor.
If the user entered the wrong password for three consecutive times, then the system will shut down and will start 
blinking the RGD lights, which I have used as an indication. 