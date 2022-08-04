
#include <Arduino.h>
#include <SPI.h>
#include "BluetoothSerial.h"
#include "const.h"
#include "blinds.h"
#include "config.h"

Stepper motor(steps_per_revolution,IN1,IN3,IN2,IN4);

BluetoothSerial SerialBT;

//Object to send position data to adafruit io
//AdafruitIO_Feed *position = io.feed("position");

void setup() {

  Serial.begin(9600);
  SerialBT.begin("Yassin_Blinds");

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  motor.setSpeed(60);

  /*
  // connect to io.adafruit.com
  Serial.print("Connecting to Adafruit IO");
  io.connect();

  // wait for a connection
  long connect_time = 0;
  long start = millis(), finish;
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    finish = millis();
    connect_time = finish - start;
    if (connect_time > 4000){
      break;
    }
  }
  if(io.status() < AIO_CONNECTED){  
    Serial.print("No WiFi");
  }
  else{
    Serial.print("Connected");
  }
  */
}

void clearBuffer(){
  while(SerialBT.read() != -1){
    SerialBT.read();
  }
}

void loop() {
/*
//maintain io connection
  if(io.status() < AIO_CONNECTED){
    io.run();
  }
*/
  int cmd = SerialBT.read();

  if (cmd != -1){
    Serial.println(cmd);
  }
  
  if(cmd == 113){
    while(cmd != 114){
      motor.step(steps_per_increment);
      //step_open_blinds(motor);
      cmd = SerialBT.read();
    }
  }
  if(cmd == 119){
    while(cmd != 114){
      motor.step(-steps_per_increment);
      //step_close_blinds(motor);
      cmd = SerialBT.read();
    }
  }
  if(cmd == 49){
    open_blinds(motor);
    clearBuffer();
  }
  if(cmd == 50){
    close_blinds(motor);
    clearBuffer();
  }

  //upload position to adafruit io
  //position->save(steps);
}

