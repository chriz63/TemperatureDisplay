#include "WebServer.h"

#include "Arduino.h"
#include "ESPAsyncWebServer.h"

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1" />
    <link
      rel="stylesheet"
      href="https://use.fontawesome.com/releases/v5.7.2/css/all.css"
      integrity="sha384-fnmOCqbTlWIlj8LyTjo7mOUStjsKC4pOpQbqyi7RrhN7udi9RwhKkMHpvLbHG9Sr"
      crossorigin="anonymous"
    />
    <link
      href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css"
      rel="stylesheet"
      integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC"
      crossorigin="anonymous"
    />
    <style>
      html {
        font-family: Arial;
        display: inline-block;
        margin: 0px auto;
        text-align: center;
      }
      h2 {
        font-size: 3rem;
      }
      p {
        font-size: 3rem;
      }
      .units {
        font-size: 1.2rem;
      }
      .dht-labels {
        font-size: 1.5rem;
        vertical-align: middle;
        padding-bottom: 15px;
      }
    </style>
  </head>
  <body>
    <script
      src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js"
      integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM"
      crossorigin="anonymous"
    ></script>
    <nav class="navbar navbar-dark bg-primary">
      <div class="container-fluid">
        <span class="navbar-brand mb-0 h1">ESP8266 DHT Server</span>
      </div>
    </nav>
    <div class="container-sm">
      <div class="row">
        <div class="col"></div>
      </div>
    </div>

    <p>
      <i class="fas fa-thermometer-half" style="color: #059e8a"></i>
      <span class="dht-labels">Temperature</span>
      <span id="temperature">%TEMPERATURE%</span>
      <sup class="units">&deg;C</sup>
    </p>
    <p>
      <i class="fas fa-tint" style="color: #00add6"></i>
      <span class="dht-labels">Humidity</span>
      <span id="humidity">%HUMIDITY%</span>
      <sup class="units">%</sup>
    </p>
  </body>
  <script>
    setInterval(function ( ) {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
          var temp = document.getElementById("temperature").innerHTML = this.responseText;
          //console.log("temp: ", temp);
        }
      };

      xhttp.open("GET", "/temperature", true);
      xhttp.send();
    }, 1000 ) ;

    setInterval(function ( ) {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
          var hum = document.getElementById("humidity").innerHTML = this.responseText;
          //console.log("hum: ",hum);
        }
      };

      xhttp.open("GET", "/humidity", true);
      xhttp.send();
    }, 1000 ) ;
</script>
</html>)rawliteral";

String processor(const String& var){
  //Serial.println(var);
  if(var == "TEMPERATURE"){
    return String("temperature");
  }
  else if(var == "HUMIDITY"){
    return String("humidity");
  }
  return String();
}

AsyncWebServer server(80);

WebServer::WebServer() {}

void WebServer::Configure() {
    Serial.println("Configuring WebServer");

    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send_P(200, "text/html", index_html, processor);
    });

    server.on("/temperature", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send_P(200, "text/plain", String("temperature").c_str());
    });

    server.on("/humidity", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send_P(200, "text/plain", String("humidity").c_str());
    });

    server.on("/json", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send_P(200, "text/plain", String("{'temperature': " + String("temperature") + ", 'humidity': " + String("humidity") + "}").c_str());
    });
}

void WebServer::Start() {
    Serial.println("Starting Webserver");
    server.begin();
}