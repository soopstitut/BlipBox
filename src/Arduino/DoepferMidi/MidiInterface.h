#ifndef _MIDIINTERFACE_H_
#define _MIDIINTERFACE_H_

class MidiInterface {
 public:
  virtual void channelPressure(int value){}
  virtual void startSong(){}
  virtual void stopSong(){}
  virtual void midiClock(){}
  virtual void pitchBend(int16_t value){}
  virtual void controlChange(int cc, int value){}
  virtual void noteOff(int note, int velocity){}
  virtual void noteOn(int note, int velocity){}
};


#endif /* _MIDIINTERFACE_H_ */
