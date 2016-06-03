/*pin: 13-11, 9-7,5-3,2-0*/
#define switch1 A0              
#define switch2 A2             
#define switch3 A3             
#define switch4 A5  

#define power1 13
#define power2 9            
#define power3 5             
#define power4 2  

#define ground1 11              
#define ground2 7
#define ground3 3              
#define ground4 0   

int switch1LastState = 0;
int switch1CurrentState = 0;
int switch2LastState = 0;
int switch2CurrentState = 0;
int switch3LastState = 0;
int switch3CurrentState = 0;
int switch4LastState = 0;
int switch4CurrentState = 0;

void noteOn(byte channel, byte pitch, byte velocity) {
  MIDIEvent noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MIDIUSB.write(noteOn);
}

void noteOff(byte channel, byte pitch, byte velocity) {
  MIDIEvent noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MIDIUSB.write(noteOff);
}

void controlChange(byte channel, byte control, byte value) {
  MIDIEvent event = {0x0B, 0xB0 | channel, control, value};
  MIDIUSB.write(event);
}
void setup() {
pinMode(switch1,INPUT);
pinMode(switch2,INPUT);
pinMode(switch3,INPUT);
pinMode(switch4,INPUT);

pinMode(power1, OUTPUT);
pinMode(power2, OUTPUT);
pinMode(power3, OUTPUT);
pinMode(power4, OUTPUT);
digitalWrite(power1,HIGH);
digitalWrite(power2,HIGH);
digitalWrite(power3,HIGH);
digitalWrite(power4,HIGH);

pinMode(ground1, OUTPUT);
pinMode(ground2, OUTPUT);
pinMode(ground3, OUTPUT);
pinMode(ground4, OUTPUT);
digitalWrite(ground1,LOW);
digitalWrite(ground2,LOW);
digitalWrite(ground3,LOW);
digitalWrite(ground4,LOW);
}
void loop() {
  switch1CurrentState = digitalRead(switch1);
if (switch1CurrentState == 1){
  if(switch1LastState == 0){ 
  controlChange(1, 1, 64);   // Channel , note, velocity
}
}
else if(switch1CurrentState == 0){
if(switch1LastState == 1){ 
 controlChange(1, 2, 64);  
}
}
switch1LastState = switch1CurrentState;

switch2CurrentState = digitalRead(switch2);
if (switch2CurrentState == 1){
  if(switch2LastState == 0){ 
  controlChange(2, 3, 64);   
}
}
else if(switch2CurrentState == 0){
  if(switch2LastState == 1){ 
 controlChange(2, 4, 64);  
}
}
switch2LastState = switch2CurrentState;

switch3CurrentState = digitalRead(switch3);
if (switch3CurrentState == 1){
  if(switch3LastState == 0){ 
  controlChange(3, 5, 64);   
}
}
else if(switch3CurrentState == 0){
  if(switch3LastState == 1){ 
 controlChange(3, 6, 64);  
}
}
switch3LastState = switch3CurrentState;

switch4CurrentState = digitalRead(switch4);
if (switch4CurrentState == 1){
  if(switch4LastState == 0){ 
  controlChange(4, 7, 64);   
}
}
else if(switch4CurrentState == 0){
  if(switch4LastState == 1){ 
 controlChange(4, 8, 64);  
}
}
switch4LastState = switch4CurrentState;
}


