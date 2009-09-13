package org.blipbox;

public interface BlipBoxProxy extends BlipBoxOutput {
    public int getParameterValue(int pid);
    public int getSensorValue(SensorType type);
    public int getSensorValue(SensorType type, int min, int max); // get scaled value
    public boolean isScreenPressed();
    public int getX();
    public int getY();
//     public boolean isButtonPressed(int buttonIndex);
}