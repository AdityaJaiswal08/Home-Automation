#include <ESP8266WiFi.h>

String  i;
WiFiServer server(80);

void setup()
{
  i = "";

Serial.begin(9600);
pinMode(16, OUTPUT);
pinMode(5, OUTPUT);
pinMode(4, OUTPUT);
pinMode(0, OUTPUT);
  WiFi.disconnect();
  delay(3000);
   WiFi.begin("Skynet Global Network - 2.4GHz","1982239016923");
  Serial.print("Connecting");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("Connected");
  Serial.print("Local IP : ");
  Serial.println((WiFi.localIP().toString()));
  server.begin();
  Serial.println("Server Started");

}


void loop()
{

    WiFiClient client = server.available();
    if (!client) { return; }
    while(!client.available()){  delay(1); }
    i = (client.readStringUntil('\r'));
    i.remove(0,8);
    i.remove(i.length()-9,9);
    if (i == "TurnONFan") {
      Serial.println("Fan on");
      digitalWrite(16,HIGH);
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("Fan ON");
      client.println("</html>");

      delay(1);

    } else if (i == "TurnONLigFar") {
      Serial.println("Far lights on");
      digitalWrite(5,HIGH);
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("Lights ON");
      client.println("</html>");

      delay(1);
    } else if (i == "TurnONLigNer") {
      Serial.println("Near lights on");
      digitalWrite(4,HIGH);
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("Lights ON");
      client.println("</html>");

      delay(1);
    } else if (i == "TurnONDisco") {
      Serial.println("LED's on");
      digitalWrite(0,HIGH);
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("Chill Time!");
      client.println("</html>");

      delay(1);
    } else if (i == "TurnOFFFan") {
      Serial.println("Fan off");
      digitalWrite(16,LOW);
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("Fans OFF! ");
      client.println("</html>");

      delay(1);
    } else if (i == "TurnOFFLigFar") {
      Serial.println("Far Lights OFF");
      digitalWrite(5,LOW);
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("Lights OFF!");
      client.println("</html>");

      delay(1);
    } else if (i == "TurnOFFLigNer") {
      Serial.println("Near Lights OFF");
      digitalWrite(4,LOW);
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("Lights OFF!");
      client.println("</html>");

      delay(1);
    } else if (i == "TurnOFFDisco") {
      Serial.println("LES's OFF");
      digitalWrite(0,LOW);
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("LED Strips OFF!");
      client.println("</html>");

      delay(1);
    } else {
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("Did Not work, NOPE!!");
      client.println("</html>");

      delay(1);

    }

}
