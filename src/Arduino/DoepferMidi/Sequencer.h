#ifndef _SEQUENCER_H_
#define _SEQUENCER_H_

#define SEQUENCER_STEPS 8

class Step {
 public:
  int8_t note;
  int8_t delay;
  int8_t duration;
  int8_t velocity;
  int8_t modulation;
};

class Sequencer : public MidiInterface {
public:
  void init(MidiInterface* _midi){
    midi = _midi;
    divisor = 8;
  }

  void stepOn(const Step& step){
    midi->noteOn(step.note, step.velocity);
    midi->controlChange(step.modulation);
  }

  void stepOff(const Step& step){
    midi->noteOff(step.note, step.velocity);
  }

  void clock(){
    if(++clock / divisor == SEQUENCER_STEPS)
      clock = 0;
    Step& step = steps[clock/divisor];
    uint8_t tick = clock % divisor;
    if(tick == step.delay)
      stepOn(step);
    // note that step end point is not affected by changes to its start point
    if(tick == step.duration || tick == divisor-1)
      stepOff(step);
  }

  virtual void controlChange(int cc, int value){
    // cc:
    // 0-7 : set note
    // 8-15 : set delay
    // 16-23 : set duration
    // 24-31 : velocity
    // 32-39 : modulation
    if(cc < 40){
      Step& step = steps[cc%SEQUENCER_STEPS];
      switch(cc/SEQUENCER_STEPS){
      case 0:
        step.note = value;
        break;
      case 1:
        step.delay = value;
        break;
      case 2:
        step.duration = value;
        break;
      case 3:
        step.velocity = value;
        break;
      case 4:
        step.modulation = value;
        break;
      }
    }
  }

private:
  Step[] steps[SEQUENCER_STEPS];
  uint8_t length;
  MidiInterface* midi;
  uint8_t divisor;
  uint16_t clock;
};

#endif /* _SEQUENCER_H_ */
