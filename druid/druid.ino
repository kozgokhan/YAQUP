#include "gyro_read.h"
#include <Wire.h>

float raw_gyro[6];
float offset[6];
float pos[3];
float accAngleX = 0;
float gyroAngleX = 0;
float accAngleXfild = 0;
float previousTime, currentTime, dt_ms, dt_s;
float corr;

void setup() {
  Wire.begin(); 
  Serial.begin(9600);

  init_mpu();
  get_offset(offset);
}

void loop() {

  previousTime = currentTime;
  currentTime = millis();
  dt_ms = (currentTime - previousTime);
  dt_s = dt_ms * 0.001;
  
  read_gyro(raw_gyro, offset);
  get_gyro_pos(pos, raw_gyro, dt_s);
  Serial.print("AccX ");
  Serial.print(raw_gyro[0]);
  Serial.print(" GyrX ");
  Serial.println(pos[0]);
}
