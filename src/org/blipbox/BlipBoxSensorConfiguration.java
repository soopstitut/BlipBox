package org.blipbox;

public class BlipBoxSensorConfiguration extends SensorConfiguration {

    public static final int X_MIN = 0;
    public static final int X_MAX = 1023;
    public static final int Y_MIN = 0;
    public static final int Y_MAX = 1023;
    public static final int Z_MIN = 20;
    public static final int Z_MAX = 200;
    public static final int POT_MIN = 252;
    public static final int POT_MAX = 1023;    

    {
        // 260 / 210
        // 800 / 780
//         int X_MIN = 170;
//         int X_MAX = 860;
//         int Y_MIN = 130;
//         int Y_MAX = 860;
        setBlipSensor(new BlipSensor(SensorType.Z_SENSOR, Z_MIN, Z_MAX));
        setBlipSensor(new BlipSensor(SensorType.X_SENSOR, X_MIN, X_MAX));
        setBlipSensor(new BlipSensor(SensorType.Y_SENSOR, Y_MIN, Y_MAX));
        setBlipSensor(new BlipSensor(SensorType.POT_SENSOR, POT_MIN, POT_MAX));
        setBlipSensor(new BlipSensor(SensorType.BUTTON1_SENSOR, 0, 1));
//         setBlipSensor(new BlipSensor(SensorType.BUTTON2_SENSOR, BUTTON2_SENSOR_MSG, 0, 1));
//         setBlipSensor(new BlipSensor(SensorType.BUTTON3_SENSOR, BUTTON3_SENSOR_MSG, 0, 1));
    }
}