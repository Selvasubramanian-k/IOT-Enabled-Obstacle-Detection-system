#include <SPI.h>
#include <Ethernet.h>
//Variables:
int LED=13;
int obstaclepin=7;
int hasObstacle=HIGH;

// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
//byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
byte mac[]={0x00,0x26,0x6C,0x28,0x55,0x4A};
IPAddress ip(192,168,1,177); //This is the ip of Ardunio. Make sure your computer is connected to the same network
// Initialize the Ethernet server library
// with the IP address and port you want to use 
// (port 80 is default for HTTP):
EthernetServer server(80); 

void setup() 
{
  Ethernet.begin(mac, ip);
  pinMode(LED,OUTPUT);
  pinMode(obstaclepin,INPUT);
  server.begin();  
  
}
void loop() 
{
  hasObstacle = digitalRead(obstaclepin); 
  EthernetClient client = server.available();
  if (client)
  {
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    while (client.connected())
    {
      if (client.available())
      {
        char c = client.read();
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        if (c == '\n' && currentLineIsBlank)
        {
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");  // the connection will be closed after completion of the response
          client.println("Refresh: 5");  // refresh the page automatically every 5 sec
          client.println();
          ///HTML Codes goes here //
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
          client.println("<title> VHNSN | Arduino | IOT OBSTACLE DETECTION  </title>");
          client.println("<div align=center>");
          client.println("<h2>Welcome to VHNSNC</h2>");
          client.println("<h2>IoT Enabled OBSTACLE DETECTION Monitoring system</h2>");
           if(hasObstacle == LOW)
            {
               client.println("STOP SOMETHING IS AHEAD!!");
          }
          else
          {
            client.println("PATH IS CLEAR");
          }
          break; 
          client.println("</h3>");
          client.println("<br/>");
          client.println("</div>");
          
           client.println("</html>");
          break;
        }
        
        if(hasObstacle == LOW)
        {
          Serial.println("STOP SOMETHING IS AHEAD!!");
          digitalWrite(LED,HIGH);
          }
          else
          {
            Serial.println("PATH IS CLEAR");
            digitalWrite(LED,LOW);
          }
        
      }
    }
    // give the web browser time to receive the data
    delay(1); 
    // close the connection:
    client.stop();
    delay(10000); // wait for 10 seconds before taking the reading again
  }
}


































