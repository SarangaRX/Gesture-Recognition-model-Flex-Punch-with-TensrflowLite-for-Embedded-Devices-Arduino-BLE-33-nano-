#include <Arduino_LSM9DS1.h>

const double gThreshold = 2;   // Samples if the threshold of 2 G's is exceeded
const int samplingRate = 119;  // Default sampling rate of the IMU

int sampleRead = samplingRate;

void setup() {
  Serial.begin(9600);
  while (!Serial)
    ;

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU");
    while (true)
      ;
  }

  Serial.println("aX,aY,aZ,gX,gY,gZ");
}

void loop()  //captures 199 samples (one second worth data))
{
  float aX, aY, aZ, gX, gY, gZ;  // Variables to hold IMU data

  while (sampleRead == samplingRate)  //Check if there is a moment than the threshold before captuing data
  {
    // Checking if acceleration data can be captured from *THIS SPECIFIC* IMU
    if (IMU.accelerationAvailable()) {
      IMU.readAcceleration(aX, aY, aZ);

      double accelerationSum = fabs(aX) + fabs(aY) + fabs(aZ);

      if (accelerationSum >= gThreshold) {
        sampleRead = 0;
        break;
      }
    }
  }

  while (sampleRead < samplingRate)  //As thresholsd is broken
  {
    // check if both new acceleration and gyroscope data is
    // available
    if (IMU.accelerationAvailable() && IMU.gyroscopeAvailable()) {
      // read the acceleration and gyroscope data
      IMU.readAcceleration(aX, aY, aZ);
      IMU.readGyroscope(gX, gY, gZ);

      sampleRead++;

      // print the data in CSV format
      Serial.print(aX, 3);
      Serial.print(',');
      Serial.print(aY, 3);
      Serial.print(',');
      Serial.print(aZ, 3);
      Serial.print(',');
      Serial.print(gX, 3);
      Serial.print(',');
      Serial.print(gY, 3);
      Serial.print(',');
      Serial.print(gZ, 3);
      Serial.print(',');
      Serial.println();

      if (sampleRead == samplingRate) {
        // add an empty line if it's the last sample
        Serial.println();
      }
    }
  }
}