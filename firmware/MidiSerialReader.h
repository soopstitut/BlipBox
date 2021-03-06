#ifndef _MIDISERIALREADER_H_
#define _MIDISERIALREADER_H_

#include "SerialReader.h"
#include "MidiInterface.h"
#include "MidiReader.h"

// class MidiControlChangeEvent : public Event {
// public:
//   uint8_t cc;
//   uint8_t value;
//   MidiControlChangeEvent(uint8_t cntrl, uint8_t val) : cc(cntrl), value(val) {}  
// };

// class MidiSerialReader : public SerialReader {
class MidiSerialReader : public SerialReader, public MidiInterface {
public:
  MidiReader reader;
  MidiSerialReader() : reader(this) {}
  void serialInput(unsigned char c){
    reader.read(c);
  }
  void handle(uint8_t data1, uint8_t data2){
    MidiEvent event(reader.status, data1, data2);
    blipbox.preset.handle(event);
  }
  void pitchBend(uint16_t value){
    handle(value & 0x7f, value>>7);
  }
  void controlChange(uint8_t cc, uint8_t value){
    handle(cc, value);
  }
  void noteOff(uint8_t note, uint8_t velocity){
    handle(note, velocity);
  }
  void noteOn(uint8_t note, uint8_t velocity){
    handle(note, velocity);
  }
  void channelPressure(uint8_t value){
    handle(value, 0);
  }
  void programChange(uint8_t pg){
    handle(pg, 0);
  }
};

#endif /* _MIDISERIALREADER_H_ */
