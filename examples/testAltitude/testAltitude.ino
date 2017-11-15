/****************
BMP180 引脚
SDA ----- I2C-SDA
SCL ----- I2C-SCL
****************/

#include <BMP180.h>

BMP180 pressure;

//double baseline; // baseline pressure

void setup()
{
    Serial.begin(115200);
    Serial.println("BMP180");

    if (pressure.begin())
    {
        Serial.println("BMP180 init success");
    }
    else
    {
        Serial.println("BMP180 init fail (disconnected?)\n\n");
        while(1); //错误停止
    }

    // Get the baseline pressure:

    //baseline = pressure.getPressure();

    Serial.print("baseline pressure: ");
    //Serial.print(baseline);
    Serial.println(" mb");
}

void loop()
{
    double a,P;
    //获取气压值
    P = pressure.getPressure();
    //计算海拔
    a = pressure.altitude(P);

    Serial.print("relative altitude: ");

    if (a >= 0.0) Serial.print(" "); // add a space for positive numbers
    Serial.print(a,1);
    Serial.print(" meters, ");

    if (a >= 0.0) Serial.print(" "); // add a space for positive numbers
    Serial.print(a*3.28084,0);
    Serial.println(" feet");

    delay(500);
}
