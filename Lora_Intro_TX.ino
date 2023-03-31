/*This Code is for the TRANSMITTER*/

int pot = A0;

void setup() {
  // put your setup code here, to run once:
  
  Serial1.begin(115200);   //default baudrate of module is 115200
  delay(100);             //wait for Lora device to be ready
  
  Serial1.print("AT\r\n");
  delay(100);
  
  Serial1.print("AT+PARAMETER=10,7,1,7\r\n");    //For Less than 3Kms
  //Serial1.print("AT+PARAMETER=10,7,1,7\r\n");    //For More than 3Kms
  delay(100);   //wait for module to respond
  
  Serial1.print("AT+BAND=868500000\r\n");    //Bandwidth set to 868.5MHz
  delay(100);   //wait for module to respond
  
  Serial1.print("AT+ADDRESS=115\r\n");   //needs to be unique
  delay(100);   //wait for module to respond
  
  Serial1.print("AT+NETWORKID=6\r\n");   //needs to be same for receiver and transmitter
  delay(100);   //wait for module to respond

  Serial1.print("AT+PARAMETER?\r\n");    //prints the current parameters
  delay(100);   //wait for module to respond
  
  Serial1.print("AT+BAND?\r\n");    //prints the current bandwidth
  delay(100);   //wait for module to respond
  
  Serial1.print("AT+NETWORKID?\r\n");   //prints the network id
  delay(100);   //wait for module to respond
  
  Serial1.print("AT+ADDRESS?\r\n");   //prints the address
  delay(100);   //wait for module to respond


}

void loop() {
  int val = map(analogRead(pot),0,1024,0,255);
  String potval = String(val);
  Serial1.print("AT+SEND=100,"+String(potval.length()) +","+ String(val)+"\r\n");
 delay(100);
}
