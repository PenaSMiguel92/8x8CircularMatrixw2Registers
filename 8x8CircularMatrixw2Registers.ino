const int SER_Pin = 2; //0 = ground, 1 = high
const int SRCLK_Pin = 3 ; //Pulse high after setting SER_Pin to insert value into shift register, causing a cascade.
const int RCLK_Pin = 4; //Pulse high to change output of pins
const int sentenceNum = 2; //total number of sentences to display.

//const byte grid_y[8] = {
//  B01111111, //a,b,c,d,e,f,g,h states. bottom up (1st register), and left to right (2nd register)
//  B10111111,
//  B11011111,
//  B11101111,
//  B11110111,
//  B11111011,
//  B11111101,
//  B11111110
//  };
//const byte grid_x[8] = {
//  B00000001, //a,b,c,d,e,f,g,h states. bottom up (1st register), and left to right (2nd register)
//  B00000010,
//  B00000100,
//  B00001000,
//  B00010000,
//  B00100000,
//  B01000000,
//  B10000000
//  };
const byte chars[39][8] = {
  {
    B00001000,//A
    B00010100,
    B00010100,
    B00010100,
    B00100010,
    B00111110,
    B01000001,
    B01000001,
  },
  {
    B01111100,//B
    B01010010,
    B01111110,
    B01000010,
    B01000010,
    B01000010,
    B01000010,
    B01111100,
  },
  {
    B00011100,//C
    B00100010,
    B01000000,
    B01000000,
    B01000000,
    B01000000,
    B00100010,
    B00011100,
  },
  {
    B01111000, //D
    B01000100,
    B01000010,
    B01000010,
    B01000010,
    B01000010,
    B01000100,
    B01111000
    },
   {
    B01111100, //E
    B01000000,
    B01000000,
    B01111100,
    B01000000,
    B01000000,
    B01000000,
    B01111100
    },
   {
    B01111100, //F
    B01000000,
    B01000000,
    B01111000,
    B01000000,
    B01000000,
    B01000000,
    B01000000
    },
   {
    B00011100, //G
    B00100010,
    B01000001,
    B01000000,
    B01000111,
    B01000001,
    B00100010,
    B00011100
    },
   {
    B01000010, //H
    B01000010,
    B01000010,
    B01111110,
    B01000010,
    B01000010,
    B01000010,
    B01000010
    },
   {
    B01000000, //I
    B01000000,
    B01000000,
    B01000000,
    B01000000,
    B01000000,
    B01000000,
    B01000000
    },
   {
    B00001000, //J
    B00001000,
    B00001000,
    B00001000,
    B00001000,
    B01001000,
    B01001000,
    B00110000
    },
    {
    B01000010, //K
    B01000100,
    B01001000,
    B01011000,
    B01101000,
    B01000100,
    B01000100,
    B01000010
    },
    {
    B01000000, //L
    B01000000,
    B01000000,
    B01000000,
    B01000000,
    B01000000,
    B01000000,
    B01111100
    },
    {
    B01000001, //M
    B01100011,
    B01100011,
    B01010101,
    B01010101,
    B01010101,
    B01001001,
    B01001001
    },
     {
    B01000010, //N
    B01100010,
    B01010010,
    B01010010,
    B01001010,
    B01001010,
    B01000110,
    B01000010
    },
     {
    B00011100, //O
    B00100010,
    B01000001,
    B01000001,
    B01000001,
    B01000001,
    B00100010,
    B00011100
    },
     {
    B01111000, //P
    B01000100,
    B01000100,
    B01000100,
    B01111000,
    B01000000,
    B01000000,
    B01000000
    },
     {
    B00011100, //Q
    B00100010,
    B01000001,
    B01000001,
    B01000001,
    B01001101,
    B00100010,
    B00011101
    },
     {
    B01111100, //R
    B01000010,
    B01000010,
    B01111100,
    B01001000,
    B01000100,
    B01000100,
    B01000010
    },
     {
    B00111100, //S
    B01000010,
    B01000000,
    B00110000,
    B00001100,
    B00000010,
    B01000010,
    B00111100
    },
     {
    B01111100, //T
    B00010000,
    B00010000,
    B00010000,
    B00010000,
    B00010000,
    B00010000,
    B00010000
    },
     {
    B01000010, //U
    B01000010,
    B01000010,
    B01000010,
    B01000010,
    B01000010,
    B01000010,
    B00111100
    },
     {
    B01000001, //V
    B01000001,
    B00100010,
    B00100010,
    B00010100,
    B00010100,
    B00001000,
    B00001000
    },
     {
    B10000010, //W
    B10000010,
    B01000100,
    B01000100,
    B01010100,
    B01010100,
    B00101000,
    B00101000
    },
     {
    B01000010, //X
    B00100100,
    B00100100,
    B00011000,
    B00011000,
    B00100100,
    B00100100,
    B01000010
    },
     {
    B01000001, //Y
    B00100010,
    B00100010,
    B00010100,
    B00001000,
    B00001000,
    B00001000,
    B00001000
    },
     {
    B00111110, //Z
    B00000100,
    B00001000,
    B00001000,
    B00010000,
    B00010000,
    B00100000,
    B01111110
    },
     {
    B00111000, //0
    B01000100,
    B01000100,
    B01000100,
    B01000100,
    B01000100,
    B01000100,
    B00111000
    },
     {
    B00010000, //1
    B00110000,
    B01010000,
    B00010000,
    B00010000,
    B00010000,
    B00010000,
    B00010000
    },
     {
    B00111000, //2
    B01000100,
    B00000100,
    B00000100,
    B00001000,
    B00010000,
    B00100000,
    B01111100
    },
     {
    B00111000, //3
    B01000100,
    B00000100,
    B00011000,
    B00000100,
    B00000100,
    B01000100,
    B00111000
    },
     {
    B00001000, //4
    B00011000,
    B00101000,
    B00101000,
    B01001000,
    B01111100,
    B00001000,
    B00001000
    },
     {
    B00111100, //5
    B00100000,
    B01000000,
    B01111000,
    B00000100,
    B00000100,
    B01000100,
    B00111000
    },
     {
    B00111000, //6
    B01000100,
    B01000000,
    B01111000,
    B01000100,
    B01000100,
    B01000100,
    B00111000
    },
     {
    B01111100, //7
    B00001000,
    B00001000,
    B00010000,
    B00010000,
    B00100000,
    B00100000,
    B00100000
    },
     {
    B00111000, //8
    B01000100,
    B01000100,
    B00111000,
    B01000100,
    B01000100,
    B01000100,
    B00111000
    },
     {
    B00111000, //9
    B01000100,
    B01000100,
    B01000100,
    B00111100,
    B00000100,
    B01000100,
    B00111000
    },
     {
    B00000000, //.
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00110000,
    B00110000
    },
     {
      B00000000, //Space
      B00000000,
      B00000000,
      B00000000,
      B00000000,
      B00000000,
      B00000000,
      B00000000
    },
    {
     B00110000, //!
     B00110000,
     B00110000,
     B00110000,
     B00110000,
     B00000000,
     B00110000,
     B00110000 
     }
  };
byte cur_map[8] = {
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    };
unsigned int char_display[2] = {37,37}; //store two characters, replace left most with middle and so forth as scrolling occurs.
//unsigned int char_data[2] = {0,8}; //x position, if second becomes 0, then second becomes first and new char is added.

const unsigned int sentences[sentenceNum][100] = {
  {8, 5, 12, 12, 15, 38, 23, 15, 18, 12, 4, 37, 38}, //0 is default value, for loop should scroll from left to right until it hits a zero, subtract one to get actual value needed. 37 is space, so add space in between sentences.
  {20,8,1,14,11,38,25,15,21,38,13,1,18,20,8,1,39, 38}
  };
unsigned long st_time = micros();
unsigned int pos; //this should keep track of position on x axis of right char
unsigned int ch; //current character
unsigned int sent; //current sentence
//unsigned long cur_time = micros();
//int test = 0;  
void setup() {
  pinMode(SER_Pin, OUTPUT);
  pinMode(SRCLK_Pin, OUTPUT);
  pinMode(RCLK_Pin, OUTPUT);

  Serial.begin(9600);
  //send_data(get_register_byte(true,0),get_register_byte(false,0));
//  while(test<100){
//  for (int x = 0; x<8; x++)
//  {
//    for (int y = 0; y<8; y++)
//    {
//      send_data(get_register_byte(true,y),get_register_byte(false,7-x));//get_register_byte(false,y));
//      delay(100);
//    };
//   delay(100);
//  };
//  test++;
//  };
}
int v = 0;
void loop() {
  // put your main code here, to run repeatedly:
  
  //send_data(get_register_byte(false,7),get_register_byte(true,0));
//  
////  for (int x = 0; x<8; x++)
////  {
//    for (int y = 7; y>=0; y--)
//    {
//      //if (v>37) { v = 0;);
//      //if (bitRead(chars[v][y],x) == 1) {
//        send_data(get_register_byte(true,y),~chars[v][y]);//get_register_byte(true,7-x),~chars[v][y]);
//      //};
////      else {
////        byte a = B00000000;
////        send_data( a, a);
////      };
//        //delay(100);
//    };
//    //delay(100);
// // };
//  //Serial.println(micros() - st_time);
//  //Serial.print(v);
//  if ((micros() - st_time)>1000000) {
//    //Serial.println(v);
//    v++;
//    if (v>37){v=0;};
//    st_time = micros();
//  }
  scrolling_text();
}
//
void scrolling_text(){
  if (micros() - st_time > 100000){ //shift characters left
    st_time = micros();
    for (int i = 0; i<8; i++){
      cur_map[i] = cur_map[i] << 1;
      bitWrite(cur_map[i],0,bitRead(chars[char_display[1]][i],7-(pos-1))); //read from char data and add into cur_map bytes
          
    };
    pos++;
    if (pos>9){
      pos = 1;
      ch++;
      if (ch>100){
        ch = 0;
        sent++;
        if (sent>=sentenceNum){
          sent = 0;
        }
      } else
      {
        if (sentences[sent][ch] == 0) {
          ch = 0;
          sent++;
          if (sent>=sentenceNum){
            sent = 0;
          };
        };
      };
      char_display[0] = char_display[1];
      char_display[1] = sentences[sent][ch] - 1;
      for (int i = 0; i<8; i++){
        cur_map[i] = cur_map[i] << 1;
        bitWrite(cur_map[i],0,0); //read from char data and add into cur_map bytes    
      };
    }
  } else //display characters
  {
    for (int i = 7; i>=0; i--){
      send_data(get_register_byte(true,i),~cur_map[i]);
    };
  };
  
}

//void scrolling_text() {
//  bool break_ = false;
//  
//  for (int i = 0; i<sentenceNum; i++){
//    for (int i_2 = 0; !(break_ || i_2 >= 100); i_2++){ //This should go through all characters until a zero is reached.
//       if (sentences[i][i_2] == 0){
//        break_ = true; 
//       } 
//       else {
//        //st_time = micros();
//        while (char_data[1]>0){
//          //delay(10);
//          if (micros()-st_time < 500000){
//            for (int y = 0; y<8; y++) {
//              for (int x = 0; x<8; x++) {
//                 if (x<(8-abs(char_data[0]))){ //logically this is sound, if x is less than right edge of character matrix.
//                    
//  
//                    if (chars[char_display[0]][y][x + (8-abs(char_data[0]))] == 1) {
//                      byte a = grid_y[y];
//                      byte b = grid_x[x]; //default state is on, turn off with ~
//                      //a = ~a; b = ~b;
//                      send_data(a,b);
//                    }
//                    else
//                      {
//                        byte a = B00000000;
//                        byte b = B00000000;
//
//                        send_data(a,b);
//                         //if char matrix says off, then invert a and b bytes.
//                      };
//  
//                     //turn on or off LED.
//                 };
//                 if ((x>(8-abs(char_data[0]))) && (x<8)){
//                   
//  
//                    if (chars[char_display[1]][y][x - (8-abs(char_data[1]))] == 1) {
//                      byte a = grid_y[y];
//                      byte b = grid_x[x];
//                      //a = ~a; b = ~b;
//                      send_data(a,b);
//                      
//                      }
//                      else {
//                        byte a = B00000000;
//                        byte b = B00000000;
//
//                        send_data(a,b);
//                        
//                      };                  
//                 };
//              };
//            };  
//          }
//         else {
//            char_data[0]--;
//            char_data[1]--;
//            st_time = micros();
//            Serial.println("shift");
//            delay(100);
//            //delay(100);
//          };
//        };
//        if (char_data[1] == 0){
//            char_display[0] = char_display[1];
//            char_display[1] = sentences[i][i_2];
//            char_data[0] = 0;
//            char_data[1] = 8;
//          };
//       };
//    };
//    break_ = false;
//    //while (!break_ && 
//  };
//  }
//void scrolling_text() { //Logic is messed up, try a different strategy whilst scrolling through chars.
//  bool break_ = false;
//  for (int i = 0; i<1; i++) { //scroll through sentences
//    for (int i_2 = 0; !(break_ || i_2 >= 100); i_2++){ //scroll through sentences' characters
//      if (sentences[i][i_2] == 0){
//          break_ = true;
//        }
//      else {
//        if (char_data[1] == 0) {
//          char_display[0] = char_display[1];
//          char_display[1] = sentences[i][i_2];
//          char_data[0] = 0;
//          char_data[1] = 8;
//        };
//        for (int y = 0; y<8; y++) {
//          for (int x = 7; x>=0; x--) {
//            bool count = false;
//            int state = 0;
//            if (x<(8-abs(char_data[0]))){
//              count = false;
//            } else {
//              count = true;
//            };
//            byte a = grid_y[y];
//            byte b = grid_x[x];
//            if (count && (chars[char_display[0]][y][x-(8-abs(char_data[0])))]==0{
//              a = ~a;
//              b = ~b;
//            }
//            if (!count && (chars[char_display[1]][y][x-char_data[1]]))]==0{
//              a = ~a;
//              b = ~b;
//            }
//          };
//        };
////            for (int count = 0; count < 2; count++){
////              switch(count)
////              {
////                case 0:
////                //for (y_2 = 0; y_2 < 8; y_2++){
////                  //for (x_2 = abs(char_data[0]); x_2 < 8; x_2++){
////                    byte a = grid_y[y];
////                    byte b = grid_x[x];
////                    if ((x+abs(char_data[0]))<8){
////                      if (chars[char_display[0]][y][x+abs(char_data[0])] != 0){
////                        a = ~a;
////                        b = ~b;
////                        send_data(a,b);
////                      } else {
////                        send_data(a,b);
////                      };
////                    };
////                  //};
////                //};
////                break;
////                case 1:
////                    byte a = grid_y[y];
////                    byte b = grid_x[x];
////                    if (8-char_data[1]>0){
////                      if (chars[char_display[0]][y][8-char_data[1]] != 0){
////                        a = ~a;
////                        b = ~b;
////                        send_data(a,b);
////                      } else {
////                        send_data(a,b);
////                      };
////                    };
////                break;
////              }
////              
////            };
//            
////          }
////        }
//
//
//        
//        char_data[0]--;
//        char_data[1]--;
//      };
//    };
//  
//  
//  };
//}
void send_data(byte a, byte b) {
  digitalWrite(SRCLK_Pin, LOW);
  shiftOut(SER_Pin, SRCLK_Pin, MSBFIRST, b);
  digitalWrite(SRCLK_Pin, LOW);
  shiftOut(SER_Pin, SRCLK_Pin, LSBFIRST, a);
  digitalWrite(SRCLK_Pin, LOW);
  digitalWrite(RCLK_Pin, HIGH);
  digitalWrite(RCLK_Pin, LOW);
}
byte get_register_byte(bool mode, int shift){
  byte a = B00000001;
  if (mode) { //if setting high
    a = a << shift;
    //Serial.println(bit(a));
  }
  else {
    a = B10000000;
    a = a >> shift;
    a = ~a;
  }
  return a;
}
