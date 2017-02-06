const static uint8_t lookup_XPT[][2] = {
  {0,1},
  {0,2},
  {0,4},
  {0,8},
  {0,16},
  {0,32},
  {0,64},
  {0,128},
  {1,1},
  {1,2},
  {1,4},
  {1,8},
  {1,16},
  {1,32},
  {1,64},
  {1,128},
  {2,1},
  {2,2},
  {2,4},
  {2,8},
  {3,1},
  {3,2},
  {3,4},
  {3,8},
  {3,16},
  {3,32},
  {3,64},
  {3,128},
  {4,1},
  {4,2},
  {4,4},
  {4,8},
  {4,16},
  {4,32},
  {4,64},
  {4,128},
  {5,1},
  {5,2},
  {5,4},
  {5,8},
  {8,1},
  {8,2},
  {8,4},
  {8,8},
  {8,16},
  {8,32},
  {8,64},
  {8,128},
  {9,1},
  {9,2},
  {9,4},
  {9,8},
  {9,16},
  {9,32},
  {9,64},
  {9,128},
  {10,1},
  {10,2},
  {10,4},
  {10,8},
  {11,1},
  {11,2},
  {11,4},
  {11,8},
  {11,16},
  {11,32},
  {11,64},
  {11,128},
  {12,1},
  {12,2},
  {12,4},
  {12,8},
  {12,16},
  {12,32},
  {12,64},
  {12,128},
  {13,1},
  {13,2},
  {13,4},
  {13,8},
  {13,16},
  {16,1},
  {16,2},
  {16,4},
  {16,8},
  {16,16},
  {16,32},
  {16,64},
  {16,128},
  {17,1},
  {17,2},
  {17,4},
  {17,8},
  {17,16},
  {17,32},
  {17,64},
  {17,128},
  {18,1},
  {18,2},
  {18,4},
  {18,8},
  {18,16},
  {19,1},
  {19,2},
  {19,4},
  {19,8},
  {19,16},
  {19,32},
  {19,64},
  {19,128},
  {20,1},
  {20,2},
  {20,4},
  {20,8},
  {20,16},
  {20,32},
  {20,64},
  {20,128},
  {21,1},
  {21,2},
  {21,4},
  {21,8},
  {21,16}
};
const static uint8_t lookup_DSK[][2] = {
  {4,8},
  {4,4},
  {4,2},
  {4,1},
  {4,128},
  {4,64},
  {4,32},
  {4,16},
  {2,8},
  {2,4},
  {2,2},
  {2,1},
  {2,128},
  {2,64},
  {2,32},
  {2,16},
  {1,8},
  {1,4},
  {1,2},
  {1,1},
  {1,128},
  {1,64},
  {1,32},
  {1,16},
  {6,8},
  {8,16},
  {6,4},
  {6,2},
  {3,8},
  {3,4},
  {3,2},
  {15,4},
  {15,8},
  {15,2},
  {15,1},
  {3,1},
  {3,16},
  {3,64},
  {3,32},
  {6,1},
  {3,128},
  {8,2},
  {8,1},
  {6,128},
  {6,32},
  {6,64},
  {15,128},
  {15,64},
  {15,16},
  {15,32},
  {6,16},
  {7,8},
  {7,4},
  {7,2},
  {7,1},
  {7,16},
  {8,32},
  {8,64},
  {0,8},
  {0,4},
  {0,2},
  {0,1},
  {0,128},
  {0,64},
  {0,32},
  {0,16},
  {5,8},
  {5,4},
  {5,2},
  {5,1},
  {5,128},
  {5,64},
  {5,32},
  {5,16},
  {7,128},
  {8,128},
  {7,64},
  {7,32}
};
const static uint8_t lookup_DSK_SEC[][2] = {
  {5,128},
  {5,64},
  {5,32},
  {5,16},
  {5,8},
  {5,4},
  {5,2},
  {5,1},
  {3,128},
  {2,8},
  {2,16},
  {2,32},
  {2,64},
  {2,128},
  {2,4},
  {6,16},
  {6,8},
  {6,4},
  {6,128},
  {6,64},
  {6,32},
  {7,128},
  {7,64},
  {7,32},
  {7,4},
  {7,8},
  {2,2},
  {7,1},
  {7,16},
  {7,2},
  {6,2},
  {2,1},
  {1,128},
  {1,64},
  {0,16},
  {0,8},
  {1,2},
  {1,1},
  {3,64},
  {1,16},
  {4,64},
  {4,32},
  {4,16},
  {4,8},
  {4,4},
  {4,2},
  {4,1},
  {1,32},
  {0,128},
  {0,64},
  {0,32},
  {6,1},
  {0,4},
  {0,2},
  {0,1},
  {3,32},
  {3,16},
  {3,8},
  {3,4},
  {1,8},
  {1,4},
  {3,2},
  {3,1}
};
const static uint8_t lookup_DISP[][2] = {
  {0,32},
  {0,16},
  {0,8},
  {0,4},
  {0,2},
  {0,1}
};
const static uint8_t lookup_XPT_OPT[][2] ={
  {0,1},
  {0,2},
  {0,4},
  {0,8},
  {0,64},
  {0,32},
  {0,16},
  {0,128},
  {1,1},
  {1,2},
  {1,4},
  {1,8},
  {1,16},
  {1,32},
  {1,64},
  {1,128},
  {2,1},
  {2,2},
  {2,4},
  {2,8},
  {2,16},
  {2,32},
  {2,64},
  {2,128},
  {3,1},
  {3,2},
  {3,16},
  {3,32},
  {3,64},
  {3,128}
};
const static uint8_t lookup_EFF[][2] = {
  {1,8},
  {1,1},
  {0,1},
  {0,32},
  {2,2},
  {1,4},
  {0,8},
  {0,64},
  {2,4},
  {2,16},
  {2,64},
  {0,16},
  {2,8},
  {2,1},
  {0,4},
  {0,2},
  {0,128},
  {1,2},
  {1,16},
  {1,32},
  {2,128},
  {2,32},
  {4,16},
  {4,64},
  {4,8},
  {4,1},
  {4,128},
  {1,64},
  {1,128},
  {3,4},
  {3,2},
  {3,16},
  {3,32},
  {3,8},
  {3,1},
  {4,4},
  {4,2},
  {4,32}
};
const static uint8_t lookup_WIPE[][2] = {
  {2,4},
  {1,64},
  {1,16},
  {0,1},
  {0,16},
  {5,128},
  {5,8},
  {4,32},
  {4,1},
  {1,32},
  {1,8},
  {2,2},
  {0,8},
  {5,32},
  {5,64},
  {5,4},
  {4,16},
  {3,128},
  {0,128},
  {1,4},
  {1,1},
  {5,2},
  {0,4},
  {4,2},
  {0,32},
  {4,8},
  {3,64},
  {5,16},
  {1,2},
  {3,4},
  {6,4},
  {4,64},
  {6,2},
  {6,8},
  {4,4},
  {3,32},
  {3,16},
  {3,8},
  {3,2},
  {3,1},
  {6,1},
  {5,1},
  {6,16},
  {4,128},
  {7,4},
  {7,2},
  {7,1},
  {0,2},
  {6,64},
  {6,128},
  {6,32},
  {0,64},
  {2,1},
  {1,128},
  {2,64},
  {2,16},
  {2,32},
  {2,8},
  {2,128}
};

const static uint8_t buttonLookup_XPT[][2] = {
  {0,0},
  {1,1},
  {2,2},
  {3,3},
  {4,4},
  {5,5},
  {6,6},
  {7,7},
  {8,8},
  {9,9},
  {10,10},
  {11,11},
  {12,12},
  {13,13},
  {14,14},
  {15,15},
  {16,16},
  {17,17},
  {18,18},
  {19,19},
  {24,20},
  {25,21},
  {26,22},
  {27,23},
  {28,24},
  {29,25},
  {30,26},
  {31,27},
  {32,28},
  {33,29},
  {34,30},
  {35,31},
  {36,32},
  {37,33},
  {38,34},
  {39,35},
  {40,36},
  {41,37},
  {42,38},
  {43,39},
  {64,40},
  {65,41},
  {66,42},
  {67,43},
  {68,44},
  {69,45},
  {70,46},
  {71,47},
  {72,48},
  {73,49},
  {74,50},
  {75,51},
  {76,52},
  {77,53},
  {78,54},
  {79,55},
  {80,56},
  {81,57},
  {82,58},
  {83,59},
  {88,60},
  {89,61},
  {90,62},
  {91,63},
  {92,64},
  {93,65},
  {94,66},
  {95,67},
  {96,68},
  {97,69},
  {98,70},
  {99,71},
  {100,72},
  {101,73},
  {102,74},
  {103,75},
  {104,76},
  {105,77},
  {106,78},
  {107,79},
  {108,80},
  {128,81},
  {129,82},
  {130,83},
  {131,84},
  {132,85},
  {133,86},
  {134,87},
  {135,88},
  {136,89},
  {137,90},
  {138,91},
  {139,92},
  {140,93},
  {141,94},
  {142,95},
  {143,96},
  {144,97},
  {145,98},
  {146,99},
  {147,100},
  {148,101},
  {152,102},
  {153,103},
  {154,104},
  {155,105},
  {156,106},
  {157,107},
  {158,108},
  {159,109},
  {160,110},
  {161,111},
  {162,112},
  {163,113},
  {164,114},
  {165,115},
  {166,116},
  {167,117},
  {168,118},
  {169,119},
  {170,120},
  {171,121},
  {172,122}
};

const static uint8_t buttonLookup_DSK[][2] = {
  {3,123},
  {2,124},
  {1,125},
  {0,126},
  {7,127},
  {6,128},
  {5,129},
  {4,130},
  {11,131},
  {10,132},
  {9,133},
  {8,134},
  {15,135},
  {14,136},
  {13,137},
  {12,138},
  {27,139},
  {26,140},
  {25,141},
  {24,142},
  {31,143},
  {30,144},
  {29,145},
  {28,146},
  {35,147},
  {34,149},
  {33,150},
  {19,151},
  {18,152},
  {17,153},
  {16,158},
  {20,159},
  {21,160},
  {22,161},
  {32,162},
  {23,163},
  {36,166},
  {37,167},
  {38,168},
  {39,173},
  {59,174},
  {58,175},
  {57,176},
  {56,177},
  {60,178},
  {40,181},
  {41,182},
  {42,183},
  {43,184},
  {44,185},
  {45,186},
  {46,187},
  {47,188},
  {48,189},
  {49,190},
  {50,191},
  {51,192},
  {52,193},
  {53,194},
  {54,195},
  {55,196},
  {61,197},
  {62,199},
  {63,200}
};

const static uint16_t buttonLookup_DSK_SEC[][2] = {
  {6,210},
  {5,211},
  {4,212},
  {3,213},
  {2,214},
  {7,215},
  {1,227},
  {0,232},
  {8,233},
  {9,234},
  {27,235},
  {28,236},
  {14,237},
  {15,238},
  {32,239},
  {11,240},
  {16,241},
  {17,242},
  {18,243},
  {19,244},
  {20,245},
  {21,246},
  {22,247},
  {23,248},
  {24,249},
  {25,250},
  {26,251},
  {29,253},
  {30,254},
  {31,255},
  {33,256},
  {34,257},
  {35,258},
  {36,259},
  {12,260},
  {13,261},
  {38,262},
  {39,263}
};

const static uint16_t buttonLookup_DISP[][2] = {
  {0,264},
  {1,265},
  {2,266},
  {3,267},
  {4,268},
  {5,269}
};

const static uint16_t buttonLookup_XPT_OPT[][2] = {
  {0,270},
  {1,271},
  {2,272},
  {3,273},
  {4,274},
  {5,275},
  {6,276},
  {7,277},
  {8,278},
  {9,279},
  {10,280},
  {11,281},
  {12,282},
  {13,283},
  {14,284},
  {15,285},
  {16,286},
  {17,287},
  {18,288},
  {19,289},
  {20,290},
  {21,291},
  {22,292},
  {23,293},
  {24,294},
  {25,295},
  {26,296},
  {27,297},
  {28,298},
  {29,299}
};

const static uint16_t buttonLookup_EFF_MEM[][2] = {
  {1,300},
  {0,301},
  {7,302},
  {2,303},
  {34,304},
  {22,305},
  {16,306},
  {23,307},
  {18,308},
  {17,309},
  {13,310},
  {4,311},
  {12,312},
  {10,313},
  {3,314},
  {11,315},
  {15,316},
  {6,317},
  {14,318},
  {8,319},
  {5,320},
  {9,321},
  {39,322},
  {37,323},
  {36,324},
  {35,325},
  {38,326},
  {21,327},
  {20,328},
  {29,329},
  {28,330},
  {27,331},
  {30,332},
  {33,333},
  {25,334},
  {24,335},
  {31,336},
  {26,337}
};

const static uint16_t buttonLookup_WIPE_SEC[][2] = {
  {48,338},
  {49,339},
  {50,340},
  {51,341},
  {52,342},
  {53,343},
  {54,344},
  {55,345},
  {13,346},
  {40,347},
  {41,348},
  {42,349},
  {43,350},
  {44,351},
  {45,352},
  {46,353},
  {47,354},
  {14,355},
  {32,356},
  {33,357},
  {34,358},
  {35,359},
  {36,360},
  {37,361},
  {38,362},
  {39,363},
  {15,364},
  {24,365},
  {25,366},
  {26,367},
  {27,368},
  {28,369},
  {29,370},
  {30,371},
  {31,372},
  {23,373},
  {8,374},
  {9,375},
  {5,376},
  {6,377},
  {7,378},
  {4,379},
  {3,380},
  {16,381},
  {21,385},
  {10,389},
  {17,390},
  {18,391},
  {19,392},
  {20,393},
  {22,394},
  {12,395},
  {11,396},
};

// 7 segments LSB first: top,topright, bottomright, bottom, bottomleft, topleft, middle, dot
uint8_t segDisp[] = { 0b00111111, 0b00000110, 0b01011011, 0b1001111, 0b01100110, 0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01100111};
//                        0           1           2           3           4           5           6           7           8           9    

uint8_t previousLamp[255] = {0};
uint8_t previousDim[9] = {0};

uint8_t storedLamp[255] = {0};

uint8_t previousButtons_XPT[22] = {0};
uint8_t previousButtons_DSK[8] = {0};
uint8_t previousButtons_DSK_SEC[5] = {0};
uint8_t previousButtons_DISP = 0;
uint8_t previousButtons_XPT_OPT[4] = {0};
uint8_t previousButtons_EFF_MEM[5] = {0};
uint8_t previousButtons_WIPE_SEC[7] = {0};

uint8_t analogValues[64] = {0};
#define NEW_NUM_WEIGHT 3
#define OLD_NUM_WEIGHT 10

long int lastFlip = 0;

uint8_t booting = 0;

#define TIME_PERIOD 10

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

#define EFF_MEM 0b00010000
#define XPT 0b01000000
#define DSK 0b10000000
#define DISP 0b11110000
#define DSK_SEC 0b00100000
#define XPT_OPT 0b01100000
#define WIPE_SEC 0b00000000

void write_DIN(uint8_t data) {
  for (int i=DIN_START;i<DIN_START+8;i++) {
    digitalWrite(i,bitRead(data,i-DIN_START));
  }
}

void write_ADDR(uint8_t address) {
  for (int i=ADDR_START;i<ADDR_START+8;i++) {
    digitalWrite(i,bitRead(address,i-ADDR_START));
  }
}

void sendData(uint8_t address, uint8_t data) {
  write_ADDR(address);
  write_DIN(data);
  digitalWrite(WRITE, HIGH);
  digitalWrite(WRITE, LOW);
}

uint8_t read_DOUT() {
  uint8_t data=0;
  for (int i=DOUT_START;i<DOUT_START+8;i++) {
    if(digitalRead(i)) bitSet(data,i-DOUT_START);
  }
  return data;
}

void write_analog_address(uint8_t address) {
  digitalWrite(A_START, bitRead(address,3));
  digitalWrite(A_START+1, bitRead(address,4));
  digitalWrite(A_START+2, bitRead(address,5));
  digitalWrite(A_START+3, bitRead(address,0));
  digitalWrite(A_START+4, bitRead(address,1));
  digitalWrite(A_START+5, bitRead(address,2));
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
    delayMicroseconds(50);
    //if(outString[i]=='\n') delayMicroseconds(1000);// Shifting the display up by a row needs ~1ms to complete!
  }
}

void writeLamp(uint16_t address, uint8_t state) {
  //Serial.print("id: ");Serial.print(address);
  uint8_t rawAddress = 0;
  uint8_t rawData = 0;
  if(address < 123) {
    // XPT
    
    rawAddress |= XPT;
    rawAddress |= lookup_XPT[address][0];
    rawData = ((state) ? lookup_XPT[address][1] : 0) | (previousLamp[rawAddress] & ~lookup_XPT[address][1]);
  } else if(address < 201) {
    // M/E keyers and transitions
    // (DSK board)
    address -= 123;
    
    rawAddress |= DSK;
    rawAddress |= lookup_DSK[address][0];
    rawData = ((state) ? lookup_DSK[address][1] : 0) | (previousLamp[rawAddress] & ~lookup_DSK[address][1]);
    rawAddress |= 0b10000000;
  } else if(address < 264) {
    // Mattes / Chroma Keyer / Masks / DSK
    // (DSK Secondary)
    address -= 201;
    
    rawAddress |= DSK_SEC;
    rawAddress |= lookup_DSK_SEC[address][0];
    rawData = ((state) ? lookup_DSK_SEC[address][1] : 0) | (previousLamp[rawAddress] & ~lookup_DSK_SEC[address][1]);
  } else if(address < 270) {
    // Display board
    address -= 264;
    
    rawAddress |= DISP;
    rawAddress |= lookup_DISP[address][0];
    rawData = ((state) ? lookup_DISP[address][1] : 0) | (previousLamp[rawAddress] & ~lookup_DISP[address][1]);
  } else if(address < 300) {
    // Aux buses
    // (XPT_OPT)
    address -= 270;
    
    rawAddress |= XPT_OPT;
    rawAddress |= lookup_XPT_OPT[address][0];
    rawData = ((state) ? lookup_XPT_OPT[address][1] : 0) | (previousLamp[rawAddress] & ~lookup_XPT_OPT[address][1]);
  } else if(address < 338) {
    // EFF_MEM
    address -= 300;
    
    rawAddress |= EFF_MEM;
    rawAddress |= lookup_EFF[address][0];
    rawData = ((state) ? lookup_EFF[address][1] : 0) | (previousLamp[rawAddress] & ~lookup_EFF[address][1]);
  } else if(address < 397) {
    // WIPE_SEC
    address -= 338;
    
    rawAddress |= WIPE_SEC;
    rawAddress |= lookup_WIPE[address][0];
    rawData = ((state) ? lookup_WIPE[address][1] : 0) | (previousLamp[rawAddress] & ~lookup_WIPE[address][1]);
  } else {
    // THIS SHOULD NEVER BE REACHED
    return;
  }
  //Serial.print(" Raw_a: ");Serial.print(rawAddress);Serial.print(" Raw_d: ");Serial.print(rawData);Serial.print(" prev_d: ");Serial.print(previousLamp[address]);Serial.print(" masked: ");Serial.println((previousLamp[rawAddress] & ~lookup_XPT[address][1]));
  previousLamp[rawAddress] = rawData;
  write_ADDR(rawAddress);
  write_DIN(rawData);
  digitalWrite(WRITE, HIGH);
  digitalWrite(WRITE, LOW);
}



void writeDim(uint8_t address, uint8_t isDim) {
  uint8_t rawAddress = 0;
  uint8_t rawData = 0;
  if(address<6) {
    // XPT
    rawAddress = 0b01000110;
    rawData = (previousDim[0] & ~(1 << address)) | (isDim << address);
    previousDim[0] = rawData;
  }
  else if(address<8) {
    // DSK
    rawAddress = 0b10010000;
    if(address==6) rawData = 2 | (previousDim[1] & 1);
    else rawData = 1 | (previousDim[1] & 2);
    previousDim[1] = rawData;
  }
  else if(address<9) {
    // DSK_SEC
    rawAddress = 0b00101111;
    rawData = isDim;
  }
  sendData(rawAddress, rawData);
}

uint8_t addrToButtonId_XPT(uint8_t address, uint8_t data_bit) {
  uint8_t combined = (address << 3) | data_bit;

  for(int i=0;i<123;i++) {
    if(combined == buttonLookup_XPT[i][0]) {
      return buttonLookup_XPT[i][1];
    }
  }
  return 0;
}

uint8_t addrToButtonId_DSK(uint8_t address, uint8_t data_bit) {
  uint8_t combined = (address << 3) | data_bit;

  for(int i=0;i<201-123;i++) {
    if(combined == buttonLookup_DSK[i][0]) {
      //Serial.print("Lookup, input: ");Serial.print(address);Serial.print(" ");Serial.print(data_bit);Serial.print(", combined ");Serial.print(combined);Serial.print(" found: ");Serial.print(buttonLookup_DSK[i][1]);Serial.print(" at iteration ");Serial.println(i);
      return buttonLookup_DSK[i][1];
    }
  }
  return 0;
}

uint16_t addrToButtonId_DSK_SEC(uint8_t address, uint8_t data_bit) {
  uint8_t combined = (address << 3) | data_bit;

  for(int i=0;i<264-201;i++) {
    if(combined == buttonLookup_DSK_SEC[i][0]) {
      return buttonLookup_DSK_SEC[i][1];
    }
  }
  return 0;
}

uint16_t addrToButtonId_DISP(uint8_t address, uint8_t data_bit) {
  uint8_t combined = (address << 3) | data_bit;

  for(int i=0;i<270-264;i++) {
    if(combined == buttonLookup_DISP[i][0]) {
      return buttonLookup_DISP[i][1];
    }
  }
  return 0;
}

uint16_t addrToButtonId_XPT_OPT(uint8_t address, uint8_t data_bit) {
  uint8_t combined = (address << 3) | data_bit;

  for(int i=0;i<300-270;i++) {
    if(combined == buttonLookup_XPT_OPT[i][0]) {
      return buttonLookup_XPT_OPT[i][1];
    }
  }
  return 0;
}

uint16_t addrToButtonId_EFF_MEM(uint8_t address, uint8_t data_bit) {
  uint8_t combined = (address << 3) | data_bit;

  for(int i=0;i<330-270;i++) {
    if(combined == buttonLookup_EFF_MEM[i][0]) {
      return buttonLookup_EFF_MEM[i][1];
    }
  }
  return 0;
}

uint16_t addrToButtonId_WIPE_SEC(uint8_t address, uint8_t data_bit) {
  uint8_t combined = (address << 3) | data_bit;

  for(int i=0;i<397-330;i++) {
    if(combined == buttonLookup_WIPE_SEC[i][0]) {
      return buttonLookup_WIPE_SEC[i][1];
    }
  }
  return 0;
}

void readAllButtons() {
  uint8_t readBuffer = 0;
  
  // XPT module first
  for(int i=0;i<22;i++) {
    write_ADDR(XPT | i);
    readBuffer = ~read_DOUT(); // Invert just to make our life easier

    // has anything changed since we last read?
    for(int j=0;j<8;j++) {
      if((readBuffer ^ previousButtons_XPT[i]) & (1 << j)) {
        if(booting) continue;
        //Serial.print("(XPT) Bit ");Serial.print(j);Serial.print(" of address ");Serial.print(i);Serial.println(" has changed!");
        Serial.print("b");Serial.print(addrToButtonId_XPT(i,j));Serial.print(",");Serial.println((readBuffer & (1<<j)) ? 1 : 0);
      }
    }
    previousButtons_XPT[i] = readBuffer;
  }

  // DSK
  for(int i=0;i<8;i++) {
    write_ADDR(DSK | i);
    readBuffer = ~read_DOUT(); // Invert just to make our life easier

    // has anything changed since we last read?
    for(int j=0;j<8;j++) {
      if((readBuffer ^ previousButtons_DSK[i]) & (1 << j)) {
        if(booting) continue;
        //Serial.print("(DSK) Bit ");Serial.print(j);Serial.print(" of address ");Serial.print(i);Serial.println(" has changed!");
        Serial.print("b");Serial.print(addrToButtonId_DSK(i,j));Serial.print(",");Serial.println((readBuffer & (1<<j)) ? 1 : 0);
      }
    }
    previousButtons_DSK[i] = readBuffer;
  }

  // DSK_SEC
  for(int i=0;i<5;i++) {
    write_ADDR(DSK_SEC | i);
    readBuffer = ~read_DOUT(); // Invert just to make our life easier

    // has anything changed since we last read?
    for(int j=0;j<8;j++) {
      if((readBuffer ^ previousButtons_DSK_SEC[i]) & (1 << j)) {
        if(booting) continue;
        //Serial.print("(DSK_SEC) Bit ");Serial.print(j);Serial.print(" of address ");Serial.print(i);Serial.println(" has changed!");
        Serial.print("b");Serial.print(addrToButtonId_DSK_SEC(i,j));Serial.print(",");Serial.println((readBuffer & (1<<j)) ? 1 : 0);
      }
    }
    previousButtons_DSK_SEC[i] = readBuffer;
  }

  // DISP
    write_ADDR(DISP);
    readBuffer = (~read_DOUT()) & 0b00011111; // Invert just to make our life easier

    // has anything changed since we last read?
    for(int j=0;j<8;j++) {
      if((readBuffer ^ previousButtons_DISP) & (1 << j)) {
        if(booting) continue;
        //Serial.print("(DISP) Bit ");Serial.print(j);Serial.println(" has changed!");
        Serial.print("b");Serial.print(addrToButtonId_DISP(0,j));Serial.print(",");Serial.println((readBuffer & (1<<j)) ? 1 : 0);
      }
    }
    previousButtons_DISP = readBuffer;

  // XPT_OPT
  for(int i=0;i<4;i++) {
    write_ADDR(XPT_OPT | i);
    readBuffer = ~read_DOUT(); // Invert just to make our life easier

    // has anything changed since we last read?
    for(int j=0;j<8;j++) {
      if((readBuffer ^ previousButtons_XPT_OPT[i]) & (1 << j)) {
        if(booting) continue;
        //Serial.print("(XPT_OPT) Bit ");Serial.print(j);Serial.print(" of address ");Serial.print(i);Serial.println(" has changed!");
        Serial.print("b");Serial.print(addrToButtonId_XPT_OPT(i,j));Serial.print(",");Serial.println((readBuffer & (1<<j)) ? 1 : 0);
      }
    }
    previousButtons_XPT_OPT[i] = readBuffer;
  }

  // EFF_MEM
  for(int i=0;i<5;i++) {
    write_ADDR(EFF_MEM | i);
    readBuffer = ~read_DOUT(); // Invert just to make our life easier

    // has anything changed since we last read?
    for(int j=0;j<8;j++) {
      if((readBuffer ^ previousButtons_EFF_MEM[i]) & (1 << j)) {
        if(booting) continue;
        //Serial.print("(EFF_MEM) Bit ");Serial.print(j);Serial.print(" of address ");Serial.print(i);Serial.println(" has changed!");
        Serial.print("b");Serial.print(addrToButtonId_EFF_MEM(i,j));Serial.print(",");Serial.println((readBuffer & (1<<j)) ? 1 : 0);
      }
    }
    previousButtons_EFF_MEM[i] = readBuffer;
  }

  // WIPE_SEC
  for(int i=0;i<7;i++) {
    write_ADDR(WIPE_SEC | i);
    readBuffer = ~read_DOUT(); // Invert just to make our life easier

    // has anything changed since we last read?
    for(int j=0;j<8;j++) {
      if((readBuffer ^ previousButtons_WIPE_SEC[i]) & (1 << j)) {
        if(booting) continue;
        //Serial.print("(WIPE_SEC) Bit ");Serial.print(j);Serial.print(" of address ");Serial.print(i);Serial.println(" has changed!");
        Serial.print("b");Serial.print(addrToButtonId_WIPE_SEC(i,j));Serial.print(",");Serial.println((readBuffer & (1<<j)) ? 1 : 0);
      }
    }
    previousButtons_WIPE_SEC[i] = readBuffer;
  }
}

#define DEADZONE 5
void readAllAnalogs() {
  uint16_t scaledValue;
  for(int i=0;i<64;i++) {
    write_analog_address(i);
    delayMicroseconds(50);
    scaledValue = analogRead(A0);
    if(i==0) scaledValue = map(scaledValue,110,235,255,0);
    else if(i==1) scaledValue = map(scaledValue,5,367,255,0);
    else if(i==2) scaledValue = map(scaledValue,96,1170,0,255);
    else if(i==3) scaledValue = map(scaledValue,40,140,255,0);
    else scaledValue = map(scaledValue,0,211,255,0);
    if(scaledValue>60000) scaledValue=0;
    if(scaledValue>255) scaledValue=255;
    scaledValue=(scaledValue*NEW_NUM_WEIGHT + (OLD_NUM_WEIGHT-NEW_NUM_WEIGHT)*analogValues[i])/OLD_NUM_WEIGHT;
    if((scaledValue>analogValues[i]+DEADZONE && analogValues[i]<255-DEADZONE) || (scaledValue<analogValues[i]-DEADZONE && analogValues[i]>DEADZONE)) {
      analogValues[i] = scaledValue;
      if(booting) continue;
      Serial.print("a");Serial.print(i);Serial.print(",");Serial.println(scaledValue);
    }
  }
}

uint16_t readAnalog(uint8_t address) {
  Serial.print("address ");Serial.println(address);
  return analogValues[address];
}

uint8_t charTo7Seg(uint8_t character) {
  if(character>47 && character<58) {
    character -= 48;
    return segDisp[character];
  }
  // 7 segments LSB first: top,topright, bottomright, bottom, bottomleft, topleft, middle, dot
  switch(character) {
    case 'a':
      return 0b01110111;
    case 'b':
      return 0b01111100;
    case 'c':
      return 0b00111001;
    case 'd':
      return 0b01011110;
    case 'e':
      return 0b01111001;
    case 'f':
      return 0b01110001;
    case '-':
      return 0b01000000;
    case '`': // degree symbol?
      return 0b01100011;
    default:
      return 0;
  }
}

int8_t findChar(char data[], char character, uint8_t length,uint8_t start) {
  for (uint8_t i=start;i<length;i++) {
    if(data[i]==character) return i;
  }
  return -1;
}

void write7SegDisplay(uint8_t address, char data[6]) {
  uint8_t digit0 = 0;
  uint8_t digit1 = 0;
  uint8_t digit2 = 0;
  uint8_t dot0 = 0;
  uint8_t dot1 = 0;
  uint8_t dot2 = 0;
  
  // let's check if there's any dots
  int8_t isdot = findChar(data, '.',6,0);
  if(isdot==1) digit0 |= 0b10000000;
  else if(isdot==2) digit1 |= 0b10000000;
  else if(isdot==3) digit2 |= 0b10000000;
  if(isdot>-1) {
    isdot = findChar(data, '.',6,isdot+1);
    if(isdot==3) digit1 |= 0b10000000;
    else if(isdot==4) digit2 |= 0b10000000;
    if(isdot>-1) {
      isdot = findChar(data, '.',6,isdot+1);
      if(isdot==5) digit2 |= 0b10000000;
    }
  }

  // let's store whether the digit has a dot (we change digits before using them in the next section hence why we do this)
  if(digit0) dot0=true;
  if(digit1) dot1=true;
  if(digit2) dot2=true;

  // Now we know where the dots are, let's read the chars
  // first character does not have a dot infront
  digit0 |= charTo7Seg(data[0]);
  digit1 |= charTo7Seg(data[1+dot0]);
  digit2 |= charTo7Seg(data[2+dot0+dot1]);

  // time to write them out
  uint8_t rawAddress = 0;
  switch(address) {
    case 1:
      rawAddress = EFF_MEM + 5; // THIS IS REVERSED ORDER
      break;
    case 2:
      rawAddress = DSK + 12;
      break;
    case 3:
      rawAddress = DSK + 9;
      break;
    case 4:
      rawAddress = WIPE_SEC + 9;
      break;
    case 5:
      rawAddress = WIPE_SEC + 8;
      break;
    case 6:
      rawAddress = DSK_SEC + 14;
      break;
    case 7:
      rawAddress = DSK_SEC + 8;
      break;
    case 8:
      rawAddress = DSK_SEC + 11;
      break;
    default:
      return;
  }
  //Serial.print("rawAddr: ");Serial.print(rawAddress);Serial.print(" digit0: ");Serial.print(digit0);Serial.print(" digit1: ");Serial.print(digit1);Serial.print(" digit2: ");Serial.println(digit2);
  if(address == 1) {
    // reversed order
    sendData(rawAddress, digit0);
    sendData(rawAddress+1, digit1);
    sendData(rawAddress+2, digit2);
  } else if(address<4 || address>6) {
    sendData(rawAddress, digit2);
    sendData(rawAddress+1, digit1);
    sendData(rawAddress+2, digit0);
  } else {
    // single digit
    sendData(rawAddress, digit0);
  }
}

void storeandclearLamps() {
  memcpy(storedLamp,previousLamp,256);
  for(int i=0;i<397;i++) writeLamp(i,0);
}

void restoreLamps() {
  // 0 all lamps
  for(int i=0;i<397;i++) writeLamp(i,0);
  // now write out to addresses that have data in (then we don't accidentally set displays/dimmers
  for(int i=0;i<256;i++) {
    if(storedLamp[i]) {
      sendData(i,storedLamp[i]);
    }
  }
}

void setup() {
  Serial.begin(115200);
  
  pinMode(WRITE,OUTPUT);
  pinMode(READ, OUTPUT);
  pinMode(ADAV, INPUT);
  pinMode(RESET, OUTPUT);
  pinMode(IRQ, OUTPUT);

  booting = true;
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
  delay(200);
  readAllButtons();

  for(uint8_t i=0;i<9;i++) {
    writeDim(i,1);
    write7SegDisplay(i,"   ");
  }

  if(previousButtons_DSK_SEC[4] & 0b10000000) {
    // Black cut held
    writeDisplay("  SKIPPING BOOT");
    for(int i=0;i<20;i++) {
      readAllAnalogs();
    }
  } else {
    writeDisplay("     Booting...\nVersion 0.50 by Laurie Kirkcaldy");
 
  
    long int startTime = millis();
    long int difference = 0;
    int lasti=0;
    int randomVar=0;
    #define BOOT_TIME 4000
    while(difference<BOOT_TIME) {
      difference = millis()-startTime;
      
      for(int i=0;i<(float)difference/(float)BOOT_TIME*26;i++) {
        readAllAnalogs(); // run this a lot
      
        writeLamp(270+i,1);
  
        // Now do some randomlamps!
        if(lasti!=i) {
          lasti=i;
          randomVar=random(0,396);
          if(randomVar>296 || randomVar<270) {
            writeLamp(randomVar,1);
          }
        }
      }
    }
  
    for(int i=0;i<50;i++) {
      readAllAnalogs(); // run this a bit more :P (and produce a little delay)
    }
  
    for(int i=0;i<400;i++) writeLamp(i,0);
  }

  booting = 0;
  writeDisplay("\x15\x0E");
}

void waitSerial() {
  while(!Serial.available());
  while(Serial.available()) Serial.read();
}

void(* resetFunc) (void) = 0;

#define BUFFER_SIZE 100
char buffer[BUFFER_SIZE];
char* arg1;
char* arg2;

void loop() {
  if(Serial.available()) {
    Serial.readBytesUntil(0,buffer,100);
    //Serial.print("Read in ");Serial.println(buffer);
    if(findChar(buffer,',',100,0)>-1) {
      arg1 = strtok(buffer+1,",");
      //Serial.print("First: ");Serial.println(arg1);
      arg2 = strtok(NULL, ",");
      //Serial.print("Second: ");Serial.println(arg2);
      switch(buffer[0]) {
        case 'd':
          // Write to a display
          if(atoi(arg1)==0) {
            writeDisplay(arg2);
          } else {
            write7SegDisplay(atoi(arg1),arg2);
          }
          break;
        case 'l':
          writeLamp(atoi(arg1),atoi(arg2));
          break;
        case '%':
          writeDim(atoi(arg1),atoi(arg2));
          break;
        default:
          break;
      }
    } else {
      // things that don't require two values
      switch(buffer[0]) {
        case 'a':
          Serial.print("a");Serial.print(atoi(buffer+1));Serial.print(",");Serial.println(readAnalog(atoi(buffer+1)));
          break;
        case '!':
          resetFunc();
        case '~':
          Serial.println("Analog Calibrate mode");
          storeandclearLamps();
          Serial.println("Waiting...");
          waitSerial();
          restoreLamps();
          break;
      }
    }
    memset(buffer, 0, BUFFER_SIZE);
  }

  readAllButtons();
  readAllAnalogs();

  if(lastFlip+TIME_PERIOD<millis()) {
    digitalWrite(IRQ, !digitalRead(IRQ));
    lastFlip=millis();
  }
}
