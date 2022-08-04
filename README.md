# Blinds

## Introduction

The goal of this project was to create a device that can open and close window blinds via a mobile phone app.

## const.h

Contains all the constant value variables for the program (pinouts, hardware specs, etc).

## config.h

Sets up adafruit.io (IoT functionality commented out in due to program size limitations).

## blinds.h

Contains methods to control the blinds via stepper motor. Note that the full potential of this code is not utilized due to hardware limitations.

## main.cpp

Driver program. Takes user inputs and executes functions from the above header files.

