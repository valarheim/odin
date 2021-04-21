/*
#include <WebServer.h>
#include <M5Core2.h>
#include <Arduino.h>

struct Position{float x; float y; float z;};
struct Golem{Position position;};
enum PositionOptions {pos_X, pos_Y, pos_Z};
Golem golem{{0.0, 0.0, 0.0}};
WebServer golem_server(80);

void handleRoot(){
     golem_server.send(200, "text/plain", "Golem is ready!");
}

void handleNotFound(){
    String message = "File Not Found\n\n";
    message += "URI: ";
    message += golem_server.uri();
    message += "\nMethod: ";
    message += (golem_server.method() == HTTP_GET) ? "GET" : "POST";
    message += "\nArguments: ";
    message += golem_server.args();
    message += "\n";
    for (uint8_t i = 0; i < golem_server.args(); i++){
        message += " " + golem_server.argName(i) + ": " + golem_server.arg(i) + "\n";
    }
    golem_server.send(404, "text/plain", message);
}

PositionOptions resolvePositionOption(String input) {
    if( input == "x" ) return pos_X;
    if( input == "y" ) return pos_Y;
    if( input == "z" ) return pos_Z;
}

void handleMove(){
    for (uint8_t i = 0; i < golem_server.args(); i++){
        switch (resolvePositionOption(golem_server.argName(i)))
        {
            case pos_X: golem.position.x = golem_server.arg(i).toFloat();
            case pos_Y: golem.position.y = golem_server.arg(i).toFloat();
            case pos_Z: golem.position.z = golem_server.arg(i).toFloat();
        }
    }
    golem_server.send(200, "text/plain", "ok");
}

void handleStop(){
    golem_server.send(200, "text/plain", "Golem is waiting!");
}

void golem_api_setup(){
    golem_server.on("/", handleRoot);
    golem_server.on("/move", HTTP_POST, handleMove);
    golem_server.on("/stop", handleStop);
    golem_server.onNotFound(handleNotFound);
    golem_server.begin();
}
*/
