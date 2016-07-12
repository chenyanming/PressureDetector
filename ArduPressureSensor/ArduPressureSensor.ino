/*
 Name:		ArduPressureSensor.ino
 Created:	5/18/2016 10:17:48 PM
 Author:	chandamon
*/

int value[4];
byte buffer[4];
byte buf;
const int blueled = 25;
boolean toggle = true;
boolean start = false;

// Setup
void setup()
{
	Serial.begin(9600);
        pinMode(blueled, OUTPUT); // Set built-in LED to OUPUT mode
        digitalWrite(blueled, toggle);
}

// Loop
void loop() {

	if (Serial.available() > 0)
	{
		buf = Serial.read();
                toggle = !toggle;
                digitalWrite(blueled, toggle);
                start = !toggle;
		
	}
  
        if (start == true)
        {
        
            
      
      
    	value[0] = analogRead(0);
    	//delay(6); value[0] = analogRead(0);
    	value[1] = analogRead(1);
    	//delay(6); value[1] = analogRead(1);
    	value[2] = analogRead(2);
    	//delay(6); value[2] = analogRead(2);
    	value[3] = analogRead(3);
    	//delay(6); value[3] = analogRead(3);
    
    	//for (int i = 0; i<4; i++)
    	//{
    	//	value[i] = value[i] - 10;
    	//	if (value[i]<0)
    	//		value[i] = 0;
    	//}
    
    	//for (int i = 0; i<4; i++)
    	//{
    	//	buffer[i] = value[i];
    	//}
    
    	
    	//test();
    	String tmp = "START,";
    	tmp = tmp + value[0];
    	tmp = tmp + ',';
    	tmp = tmp + value[1];
    	tmp = tmp + ',';
    	tmp = tmp + value[2];
    	tmp = tmp + ',';
    	tmp = tmp + value[3];
    	tmp = tmp + ",END\n";
    	Serial.print(tmp);
    	delay(100);
        }
}
///////////////////////////////////////
void BT()
{
	if (Serial.available() > 0)
	{
		buf = Serial.read();
                toggle = !toggle;
                digitalWrite(blueled, toggle);
		
	}
}
//////////////////////////////////
void test()
{
	for (int i = 0; i<4; i++)
	{
		Serial.print(buffer[i]);
		Serial.print(" ");
		delay(100);
	}
	Serial.println();
}
