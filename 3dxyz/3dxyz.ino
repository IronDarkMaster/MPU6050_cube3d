#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);
long zaman1 = 0;

void setup() {
  Serial.begin(115200);  // Baud hızını artırdık
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
}

void loop() {
  mpu6050.update();

  if (millis() - zaman1 > 100) {  // Daha sık veri gönderelim
    Serial.print(mpu6050.getAngleX());
    Serial.print(",");
    Serial.print(mpu6050.getAngleY());
    Serial.print(",");
    Serial.println(mpu6050.getAngleZ());
    
    zaman1 = millis();
  }
}
