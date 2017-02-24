#define ADDR_START 22

#define INT_ADDR_0 ADDR_START
#define INT_ADDR_1 23
#define INT_ADDR_2 24
#define INT_ADDR_3 25
#define INT_ADDR_4 26

#define EXT_ADDR_0 27
#define EXT_ADDR_1 28
#define EXT_ADDR_2 29

#define WRITE 13
#define READ 12
#define ADAV 11
#define RESET 10
#define IRQ 9

#define DIN_START 30

#define DOUT_START 38

#define A_START 14 // analog address pins

#define ANALOG_IN A0



void setup() {
  Serial.begin(115200);
  
  pinMode(WRITE,OUTPUT);
  pinMode(READ, OUTPUT);
  pinMode(ADAV, INPUT);
  pinMode(RESET, OUTPUT);
  pinMode(IRQ, OUTPUT);

  
  TCCR2B = (TCCR2B & 0b11111000) | 0x07;
  analogWrite(IRQ, 1); // make an interrupt every ~490Hz
  
  digitalWrite(RESET,HIGH);
  
  for (int i=22; i<DOUT_START; i++) {
    pinMode(i, OUTPUT);
  }
  for (int i=DOUT_START; i<DOUT_START+8; i++) {
    pinMode(i, INPUT);
  }

  for (int i=A_START;i<A_START+6;i++) {
    pinMode(i, OUTPUT);
  }

  pinMode(A0, INPUT);
  
  delay(10);

  digitalWrite(RESET,LOW);
  delay(500);
}

void write_DIN(uint8_t data) {
  for (int i=DIN_START;i<DIN_START+8;i++) {
    digitalWrite(i,bitRead(data,i-DIN_START));
  }
}

uint8_t read_DOUT() {
  uint8_t data=0;
  for (int i=DOUT_START;i<DOUT_START+8;i++) {
    if(digitalRead(i)) bitSet(data,i-DOUT_START);
  }
  return data;
}

void printB(uint8_t data) {
  for (int i=0;i<8;i++) {
    Serial.print(bitRead(data,i));
  }
}

void writeDisplay(String outString) {
  digitalWrite(EXT_ADDR_0, HIGH);
  digitalWrite(EXT_ADDR_1, HIGH);
  digitalWrite(EXT_ADDR_2, HIGH);
  
  digitalWrite(INT_ADDR_3, LOW);
  digitalWrite(INT_ADDR_4, HIGH);
  digitalWrite(INT_ADDR_2, HIGH);
  digitalWrite(INT_ADDR_1, HIGH);
  digitalWrite(INT_ADDR_0, LOW); // this seems to do nothing
  for (int i=0;i<outString.length();i++) {
    write_DIN(outString[i]);
    digitalWrite(WRITE, HIGH);
    digitalWrite(WRITE, LOW);
    delayMicroseconds(30);
    //if(outString[i]=='\n') delayMicroseconds(1000);// Shifting the display up by a row needs ~1ms to complete!
  }
}

void loop() {
  writeDisplay("Sid is a penis :P");

  while(1);
}
