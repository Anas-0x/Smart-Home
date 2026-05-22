#include <WiFi.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

int relay1 = 19;
int relay2 = 18;
int relay3 = 5;
int relay4 = 17;
int relay5 = 16;
int relay6 = 4;
int relay7 = 2;
int relay8 = 15;


unsigned long timerEnd1 = 0;
unsigned long timerEnd2 = 0;
unsigned long timerEnd3 = 0;
unsigned long timerEnd4 = 0;
unsigned long timerEnd5 = 0;
unsigned long timerEnd6 = 0;
unsigned long timerEnd7 = 0;
unsigned long timerEnd8 = 0;

bool timer1 = false;
bool timer2 = false;
bool timer3 = false;
bool timer4 = false;
bool timer5 = false;
bool timer6 = false;
bool timer7 = false;
bool timer8 = false;

WiFiServer server(80);

const char* webPage = R"rawliteral(

<!DOCTYPE html>
<html lang="en">

<head>

<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">

<title>Smart Home</title>

<style>

body { 
    background-color: #050510; 
    color: #e0e0ff;
    text-align: center;
    padding: 20px;
    font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
}

.header { 
    padding: 15px; 
    border-radius: 15px; 
    border: 2px solid #8844ff; 
    margin-bottom: 30px;
    background: rgba(136, 68, 255, 0.1); 
}

h1 { 
    text-shadow: 0 0 10px #bb86fc; 
    color: #bb86fc; 
}

.container { 
    display: flex; 
    justify-content: center; 
    gap: 20px;
    flex-wrap: wrap;
}

.card { 
    background: #121225; 
    border: 1px solid #332255;
    padding: 20px; 
    border-radius: 15px; 
    width: 260px; 
}

h2 {
    color: #4cc9f0;
}

.btn { 
    padding: 10px 20px; 
    font-weight: bold; 
    border-radius: 8px; 
    cursor: pointer; 
    border: none; 
    margin: 5px; 
    width: 85px; 
}

.on { 
    background: #00ff88; 
    color: #000; 
}

.off { 
    background: #ff4444; 
    color: #fff; 
}

input { 
    width: 65%; 
    padding: 8px; 
    margin-top: 10px;
    margin-bottom: 10px;
    border-radius: 5px; 
    background: #000; 
    border: 1px solid #443366; 
    color: #fff; 
}

.set-btn { 
    background: #bb86fc; 
    padding: 10px; 
    border-radius: 5px; 
    font-weight: bold; 
    cursor: pointer; 
    width: 95%; 
    border: none;
}

</style>

<script>

function sendData(value){

    fetch(value);

}

</script>

</head>

<body>

<div class="header">

<h1>Smart home</h1>

<p>Home control panel</p>

</div>

<div class="container">

<div class="card">

<h2>Living Room</h2>

<button class="btn on" onclick="sendData('/R1ON')">ON</button>
<button class="btn off" onclick="sendData('/R1OFF')">OFF</button>

<br><br>

<input type="number" id="t1" placeholder="Minutes">

<br><br>

<button class="set-btn"
onclick="
let m=document.getElementById('t1').value;
sendData('/T1?min='+m)
">Start Timer</button>
</div>

<div class="card">

<h2>Kitchen</h2>

<button class="btn on" onclick="sendData('/R2ON')">ON</button>
<button class="btn off" onclick="sendData('/R2OFF')">OFF</button>

<br><br>

<input type="number" id="t2" placeholder="Minutes">

<br><br>

<button class="set-btn"
onclick="
let m=document.getElementById('t2').value;
sendData('/T2?min='+m)
">Start Timer</button>

</div>

<div class="card">

<h2>Bedroom</h2>

<button class="btn on" onclick="sendData('/R3ON')">ON</button>
<button class="btn off" onclick="sendData('/R3OFF')">OFF</button>

<br><br>

<input type="number" id="t3" placeholder="Minutes">

<br><br>

<button class="set-btn"
onclick="
let m=document.getElementById('t3').value;
sendData('/T3?min='+m)
">
Start Timer
</button>

</div>

<div class="card">

<h2>Garden</h2>

<button class="btn on" onclick="sendData('/R4ON')">ON</button>
<button class="btn off" onclick="sendData('/R4OFF')">OFF</button>

<br><br>

<input type="number" id="t4" placeholder="Minutes">

<br><br>

<button class="set-btn"
onclick="
let m=document.getElementById('t4').value;
sendData('/T4?min='+m)
">Start Timer</button>
</div>

<div class="card">

<h2>Garage</h2>

<button class="btn on" onclick="sendData('/R5ON')">ON</button>
<button class="btn off" onclick="sendData('/R5OFF')">OFF</button>

<br><br>

<input type="number" id="t5" placeholder="Minutes">

<br><br>

<button class="set-btn"
onclick="
let m=document.getElementById('t5').value;
sendData('/T5?min='+m)
">Start Timer</button>

</div>

<div class="card">

<h2>Office</h2>

<button class="btn on" onclick="sendData('/R6ON')">ON</button>
<button class="btn off" onclick="sendData('/R6OFF')">OFF</button>

<br><br>

<input type="number" id="t6" placeholder="Minutes">

<br><br>

<button class="set-btn"
onclick="
let m=document.getElementById('t6').value;
sendData('/T6?min='+m)
">Start Timer</button>

</div>

<div class="card">

<h2>Bathroom</h2>

<button class="btn on" onclick="sendData('/R7ON')">ON</button>
<button class="btn off" onclick="sendData('/R7OFF')">OFF</button>

<br><br>

<input type="number" id="t7" placeholder="Minutes">

<br><br>

<button class="set-btn"
onclick="
let m=document.getElementById('t7').value;
sendData('/T7?min='+m)
">Start Timer</button>

</div>

<div class="card">

<h2>Balcony</h2>

<button class="btn on" onclick="sendData('/R8ON')">ON</button>
<button class="btn off" onclick="sendData('/R8OFF')">OFF</button>

<br><br>

<input type="number" id="t8" placeholder="Minutes">

<br><br>

<button class="set-btn"
onclick="
let m=document.getElementById('t8').value;
sendData('/T8?min='+m)
">Start Timer</button>

</div>

</div>

</body>
</html>

)rawliteral";

void setup() {

  Serial.begin(115200);

  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  pinMode(relay5, OUTPUT);
  pinMode(relay6, OUTPUT);
  pinMode(relay7, OUTPUT);
  pinMode(relay8, OUTPUT);

  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);
  digitalWrite(relay5, HIGH);
  digitalWrite(relay6, HIGH);
  digitalWrite(relay7, HIGH);
  digitalWrite(relay8, HIGH);

  WiFi.begin(ssid, password);

  Serial.print("Connecting");

  while (WiFi.status() != WL_CONNECTED) {

    delay(500);
    Serial.print(".");

  }

  Serial.println("");
  Serial.println("WiFi Connected");
  Serial.println(WiFi.localIP());

  server.begin();

}

void loop() {

  if (timer1 && millis() > timerEnd1) {
    digitalWrite(relay1, HIGH);
    timer1 = false;
  }

  if (timer2 && millis() > timerEnd2) {
    digitalWrite(relay2, HIGH);
    timer2 = false;
  }

  if (timer3 && millis() > timerEnd3) {
    digitalWrite(relay3, HIGH);
    timer3 = false;
  }

  if (timer4 && millis() > timerEnd4) {
    digitalWrite(relay4, HIGH);
    timer4 = false;
  }

  if (timer5 && millis() > timerEnd5) {
    digitalWrite(relay5, HIGH);
    timer5 = false;
  }

  if (timer6 && millis() > timerEnd6) {
    digitalWrite(relay6, HIGH);
    timer6 = false;
  }

  if (timer7 && millis() > timerEnd7) {
    digitalWrite(relay7, HIGH);
    timer7 = false;
  }

  if (timer8 && millis() > timerEnd8) {
    digitalWrite(relay8, HIGH);
    timer8 = false;
  }

  WiFiClient client = server.available();

  if (client) {

    String line = "";

    while (client.connected()) {

      if (client.available()) {

        char c = client.read();

        if (c == '\n') {

          if (line.length() == 0) {

            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            client.print(webPage);

            break;

          } else {

            line = "";

          }

        } else if (c != '\r') {

          line += c;

        }

        if (line.endsWith("GET /R1ON")) {
          digitalWrite(relay1, LOW);
          timer1 = false;
        }

        if (line.endsWith("GET /R1OFF")) {
          digitalWrite(relay1, HIGH);
          timer1 = false;
        }

        if (line.endsWith("GET /R2ON")) {
          digitalWrite(relay2, LOW);
          timer2 = false;
        }

        if (line.endsWith("GET /R2OFF")) {
          digitalWrite(relay2, HIGH);
          timer2 = false;
        }

        if (line.endsWith("GET /R3ON")) {
          digitalWrite(relay3, LOW);
          timer3 = false;
        }

        if (line.endsWith("GET /R3OFF")) {
          digitalWrite(relay3, HIGH);
          timer3 = false;
        }

        if (line.endsWith("GET /R4ON")) {
          digitalWrite(relay4, LOW);
          timer4 = false;
        }

        if (line.endsWith("GET /R4OFF")) {
          digitalWrite(relay4, HIGH);
          timer4 = false;
        }

        if (line.endsWith("GET /R5ON")) {
          digitalWrite(relay5, LOW);
          timer5 = false;
        }

        if (line.endsWith("GET /R5OFF")) {
          digitalWrite(relay5, HIGH);
          timer5 = false;
        }

        if (line.endsWith("GET /R6ON")) {
          digitalWrite(relay6, LOW);
          timer6 = false;
        }

        if (line.endsWith("GET /R6OFF")) {
          digitalWrite(relay6, HIGH);
          timer6 = false;
        }

        if (line.endsWith("GET /R7ON")) {
          digitalWrite(relay7, LOW);
          timer7 = false;
        }

        if (line.endsWith("GET /R7OFF")) {
          digitalWrite(relay7, HIGH);
          timer7 = false;
        }

        if (line.endsWith("GET /R8ON")) {
          digitalWrite(relay8, LOW);
          timer8 = false;
        }

        if (line.endsWith("GET /R8OFF")) {
          digitalWrite(relay8, HIGH);
          timer8 = false;
        }

        if (line.indexOf("GET /T1?min=") >= 0) {
          int mins = line.substring(line.indexOf("min=") + 4).toInt();
          digitalWrite(relay1, LOW);
          timerEnd1 = millis() + (mins * 60000);
          timer1 = true;
        }

        if (line.indexOf("GET /T2?min=") >= 0) {
          int mins = line.substring(line.indexOf("min=") + 4).toInt();
          digitalWrite(relay2, LOW);
          timerEnd2 = millis() + (mins * 60000);
          timer2 = true;
        }
        if (line.indexOf("GET /T3?min=") >= 0) {
          int mins = line.substring(line.indexOf("min=") + 4).toInt();
          digitalWrite(relay3, LOW);
          timerEnd3 = millis() + (mins * 60000);
          timer3 = true;
        }

        if (line.indexOf("GET /T4?min=") >= 0) {
          int mins = line.substring(line.indexOf("min=") + 4).toInt();
          digitalWrite(relay4, LOW);
          timerEnd4 = millis() + (mins * 60000);
          timer4 = true;
        }

        if (line.indexOf("GET /T5?min=") >= 0) {
          int mins = line.substring(line.indexOf("min=") + 4).toInt();
          digitalWrite(relay5, LOW);
          timerEnd5 = millis() + (mins * 60000);
          timer5 = true;
        }

        if (line.indexOf("GET /T6?min=") >= 0) {
          int mins = line.substring(line.indexOf("min=") + 4).toInt();
          digitalWrite(relay6, LOW);
          timerEnd6 = millis() + (mins * 60000);
          timer6 = true;
        }

        if (line.indexOf("GET /T7?min=") >= 0) {
          int mins = line.substring(line.indexOf("min=") + 4).toInt();
          digitalWrite(relay7, LOW);
          timerEnd7 = millis() + (mins * 60000);
          timer7 = true;
        }

        if (line.indexOf("GET /T8?min=") >= 0) {
          int mins = line.substring(line.indexOf("min=") + 4).toInt();
          digitalWrite(relay8, LOW);
          timerEnd8 = millis() + (mins * 60000);
          timer8 = true;
        }

      }
    }

    client.stop();
  }
}