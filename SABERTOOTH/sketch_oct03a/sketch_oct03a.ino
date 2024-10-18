#include <SoftwareSerial.h>

// Set up SoftwareSerial for communication with Sabertooth
SoftwareSerial sabertoothSerial(10, 11);  // RX, TX (Adjust pins as needed)

void setup() {
  Serial.begin(9600);             // Serial communication with the PC
  sabertoothSerial.begin(9600);    // Serial communication with Sabertooth
  Serial.println("Arduino ready");
}

void loop() {
  // Check if a command is available from the Serial input (from socket communication)
  if (Serial.available()) {
    String command = Serial.readStringUntil('\n');  // Read command sent over Serial
    command.trim();  // Remove any extra whitespace

    // Execute motor control based on command
    if (command == "forward") {
      moveForward();
    } else if (command == "backward") {
      moveBackward();
    } else if (command == "left") {
      turnLeft();
    } else if (command == "right") {
      turnRight();
    } else if (command == "stop") {
      stopMotors();
    } else {
      Serial.println("Unknown command");
    }
  }
}

// Motor Control Functions
void moveForward() {
  sabertoothSerial.write(0x80);  // Device address (set as 128 by default)
  sabertoothSerial.write(0);     // Command for motor 1 forward
  sabertoothSerial.write(127);   // Speed (0 - 127)

  sabertoothSerial.write(0x80);  // Device address
  sabertoothSerial.write(4);     // Command for motor 2 forward
  sabertoothSerial.write(127);   // Speed
  Serial.println("Moving forward");
}

void moveBackward() {
  sabertoothSerial.write(0x80);
  sabertoothSerial.write(1);  // Command for motor 1 backward
  sabertoothSerial.write(127);

  sabertoothSerial.write(0x80);
  sabertoothSerial.write(5);  // Command for motor 2 backward
  sabertoothSerial.write(127);
  Serial.println("Moving backward");
}

void turnLeft() {
  sabertoothSerial.write(0x80);
  sabertoothSerial.write(0);  // Motor 1 forward
  sabertoothSerial.write(64); // Motor 1 speed (reduce for turning)

  sabertoothSerial.write(0x80);
  sabertoothSerial.write(5);  // Motor 2 backward
  sabertoothSerial.write(64); // Motor 2 speed
  Serial.println("Turning left");
}

void turnRight() {
  sabertoothSerial.write(0x80);
  sabertoothSerial.write(1);  // Motor 1 backward
  sabertoothSerial.write(64);

  sabertoothSerial.write(0x80);
  sabertoothSerial.write(4);  // Motor 2 forward
  sabertoothSerial.write(64);
  Serial.println("Turning right");
}

void stopMotors() {
  sabertoothSerial.write(0x80);
  sabertoothSerial.write(0);  // Motor 1 stop
  sabertoothSerial.write(0);

  sabertoothSerial.write(0x80);
  sabertoothSerial.write(4);  // Motor 2 stop
  sabertoothSerial.write(0);
  Serial.println("Stopping motors");
}
