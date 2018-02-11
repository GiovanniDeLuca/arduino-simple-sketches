/* 
  MorseCodeName
  
  What's your Morse code name?

  Using the board's LED, this sketch shows the input name (a string) in Morse code. 
 
  created 11/02/2018
  by Giovanni De Luca
  
*/

#define TIME_UNIT 1000

String name;

void setup() {
  // opens serial port, sets data rate to 9600 bps
  Serial.begin(9600);
    
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  // Wait for Serial port to connect
  while (!Serial);

  Serial.println("Hi, what's your name?");
}

void loop() {
  if (Serial.available() > 0) {
    char c = char(Serial.read()); // read the next char received
    // look for the newline character, this is the last character in the string
    if (c == '\n') {
      //print text with the name received
      Serial.print("Hi ");
      Serial.print(name);
      Serial.println("! Nice to meet you!");
      Serial.println("Check the led to read your name in morse code!");
      delay(5000);
      convertNameToMorseCode(name);
      Serial.println();
      // Ask again for name and clear the old name
      Serial.println("Hi, what's your name?");
      name = "";  // clear the name string
    } else {     // if the buffer is empty Cosole.read() returns -1
      name += c; // append the read char from Console to the name string
    }
  } else {
    delay(100);
  }
}

void convertNameToMorseCode(String name){
  for(int i = 0; i < name.length(); i++){
    convertCharToMorseCode(name.charAt(i));
  }
}

void convertCharToMorseCode(char c){
    switch (c) {
    case 'a':
    case 'A':
      digitalWrite(LED_BUILTIN, HIGH);
      delay(TIME_UNIT); //DOT 
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(3*TIME_UNIT); //DASH
      digitalWrite(LED_BUILTIN, LOW);
      delay(3*TIME_UNIT); //SPACE BETWEEN LETTERS OF A WORD
      break;
    case 'b':
    case 'B':
      digitalWrite(LED_BUILTIN, HIGH);
      delay(3*TIME_UNIT); //DASH
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(TIME_UNIT); //DOT 
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(TIME_UNIT); //DOT 
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(TIME_UNIT); //DOT 
      digitalWrite(LED_BUILTIN, LOW);
      delay(3*TIME_UNIT); //SPACE BETWEEN LETTERS OF A WORD
      break;
    case 'c':
    case 'C':  
      digitalWrite(LED_BUILTIN, HIGH);
      delay(3*TIME_UNIT); //DASH
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(TIME_UNIT); //DOT
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(3*TIME_UNIT); //DASH
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(TIME_UNIT); //DOT
      digitalWrite(LED_BUILTIN, LOW);
      delay(3*TIME_UNIT); //SPACE BETWEEN LETTERS OF A WORD
      break;
    case 'd':
    case 'D':    
      digitalWrite(LED_BUILTIN, HIGH);
      delay(3*TIME_UNIT); //DASH
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(TIME_UNIT); //DOT 
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(TIME_UNIT); //DOT 
      digitalWrite(LED_BUILTIN, LOW);
      delay(3*TIME_UNIT); //SPACE BETWEEN LETTERS OF A WORD
      break;
    case 'e':
    case 'E':    
      digitalWrite(LED_BUILTIN, HIGH);
      delay(TIME_UNIT); //DOT 
      digitalWrite(LED_BUILTIN, LOW);
      delay(3*TIME_UNIT); //SPACE BETWEEN LETTERS OF A WORD
      break;
    case 'f':
    case 'F':    
      digitalWrite(LED_BUILTIN, HIGH);
      delay(TIME_UNIT); //DOT
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(TIME_UNIT); //DOT
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(3*TIME_UNIT); //DASH
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(TIME_UNIT); //DOT
      digitalWrite(LED_BUILTIN, LOW);
      delay(3*TIME_UNIT); //SPACE BETWEEN LETTERS OF A WORD
      break;
    case 'g':
    case 'G':
      digitalWrite(LED_BUILTIN, HIGH);
      delay(3*TIME_UNIT); //DASH  
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(3*TIME_UNIT); //DASH 
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(TIME_UNIT); //DOT 
      digitalWrite(LED_BUILTIN, LOW);
      delay(3*TIME_UNIT); //SPACE BETWEEN LETTERS OF A WORD
      break;
    case 'h':    
    case 'H':
      digitalWrite(LED_BUILTIN, HIGH);
      delay(TIME_UNIT); //DOT
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(TIME_UNIT); //DOT
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(TIME_UNIT); //DOT
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(TIME_UNIT); //DOT
      digitalWrite(LED_BUILTIN, LOW);
      delay(3*TIME_UNIT); //SPACE BETWEEN LETTERS OF A WORD
      break;
    case 'i': 
    case 'I':  
      digitalWrite(LED_BUILTIN, HIGH);
      delay(TIME_UNIT); //DOT
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(TIME_UNIT); //DOT 
      digitalWrite(LED_BUILTIN, LOW);
      delay(3*TIME_UNIT); //SPACE BETWEEN LETTERS OF A WORD
      break;
    case 'j':   
    case 'J': 
      digitalWrite(LED_BUILTIN, HIGH);
      delay(TIME_UNIT); //DOT
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(3*TIME_UNIT); //DASH
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(3*TIME_UNIT); //DASH
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(3*TIME_UNIT); //DASH
      digitalWrite(LED_BUILTIN, LOW);
      delay(3*TIME_UNIT); //SPACE BETWEEN LETTERS OF A WORD
      break;
    case 'k':    
    case 'K':
      digitalWrite(LED_BUILTIN, HIGH);
      delay(3*TIME_UNIT); //DASH
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(TIME_UNIT); //DOT
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(3*TIME_UNIT); //DASH
      digitalWrite(LED_BUILTIN, LOW);
      delay(3*TIME_UNIT); //SPACE BETWEEN LETTERS OF A WORD
      break;
    case 'l':    
    case 'L': 
      digitalWrite(LED_BUILTIN, HIGH);
      delay(TIME_UNIT); //DOT
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(3*TIME_UNIT); //DASH 
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(TIME_UNIT); //DOT
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(TIME_UNIT); //DOT  
      digitalWrite(LED_BUILTIN, LOW);
      delay(3*TIME_UNIT); //SPACE BETWEEN LETTERS OF A WORD
      break;
    case 'm':  
    case 'M':  
      digitalWrite(LED_BUILTIN, HIGH);
      delay(3*TIME_UNIT); //DASH
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(3*TIME_UNIT); //DASH
      digitalWrite(LED_BUILTIN, LOW);
      delay(3*TIME_UNIT); //SPACE BETWEEN LETTERS OF A WORD
      break;
    case 'n':    
    case 'N':
      digitalWrite(LED_BUILTIN, HIGH);
      delay(3*TIME_UNIT); //DASH
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(TIME_UNIT); //DOT
      digitalWrite(LED_BUILTIN, LOW);
      delay(3*TIME_UNIT); //SPACE BETWEEN LETTERS OF A WORD
      break;
    case 'o':    
    case 'O':
      digitalWrite(LED_BUILTIN, HIGH);
      delay(3*TIME_UNIT); //DASH
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(3*TIME_UNIT); //DASH
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(3*TIME_UNIT); //DASH
      digitalWrite(LED_BUILTIN, LOW);
      delay(3*TIME_UNIT); //SPACE BETWEEN LETTERS OF A WORD
      break;
    case 'p':  
    case 'P':  
      digitalWrite(LED_BUILTIN, HIGH);
      delay(TIME_UNIT); //DOT
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(3*TIME_UNIT); //DASH
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(3*TIME_UNIT); //DASH
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(TIME_UNIT); //DOT
      digitalWrite(LED_BUILTIN, LOW);
      delay(3*TIME_UNIT); //SPACE BETWEEN LETTERS OF A WORD
      break;
    case 'q':  
    case 'Q':  
      digitalWrite(LED_BUILTIN, HIGH);
      delay(3*TIME_UNIT); //DASH
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(3*TIME_UNIT); //DASH
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(TIME_UNIT); //DOT
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(3*TIME_UNIT); //DASH
      digitalWrite(LED_BUILTIN, LOW);
      delay(3*TIME_UNIT); //SPACE BETWEEN LETTERS OF A WORD
      break;
    case 'r':   
    case 'R': 
      digitalWrite(LED_BUILTIN, HIGH);
      delay(TIME_UNIT); //DOT
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(3*TIME_UNIT); //DASH
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(TIME_UNIT); //DOT
      digitalWrite(LED_BUILTIN, LOW);
      delay(3*TIME_UNIT); //SPACE BETWEEN LETTERS OF A WORD
      break;
    case 's':
    case 'S':  
      digitalWrite(LED_BUILTIN, HIGH);
      delay(TIME_UNIT); //DOT
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(TIME_UNIT); //DOT
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(TIME_UNIT); //DOT  
      digitalWrite(LED_BUILTIN, LOW);
      delay(3*TIME_UNIT); //SPACE BETWEEN LETTERS OF A WORD
      break;
    case 't':  
    case 'T': 
      digitalWrite(LED_BUILTIN, HIGH);
      delay(3*TIME_UNIT); //DASH 
      digitalWrite(LED_BUILTIN, LOW);
      delay(3*TIME_UNIT); //SPACE BETWEEN LETTERS OF A WORD
      break;
    case 'u': 
    case 'U':   
      digitalWrite(LED_BUILTIN, HIGH);
      delay(TIME_UNIT); //DOT
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(TIME_UNIT); //DOT
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(3*TIME_UNIT); //DASH
      digitalWrite(LED_BUILTIN, LOW);
      delay(3*TIME_UNIT); //SPACE BETWEEN LETTERS OF A WORD
      break;
    case 'v': 
    case 'V': 
      digitalWrite(LED_BUILTIN, HIGH);
      delay(TIME_UNIT); //DOT
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(TIME_UNIT); //DOT
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(TIME_UNIT); //DOT
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(3*TIME_UNIT); //DASH  
      digitalWrite(LED_BUILTIN, LOW);
      delay(3*TIME_UNIT); //SPACE BETWEEN LETTERS OF A WORD
      break;
    case 'w':  
    case 'W':  
      digitalWrite(LED_BUILTIN, HIGH);
      delay(TIME_UNIT); //DOT
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(3*TIME_UNIT); //DASH
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(3*TIME_UNIT); //DASH
      digitalWrite(LED_BUILTIN, LOW);
      delay(3*TIME_UNIT); //SPACE BETWEEN LETTERS OF A WORD
      break;
    case 'x': 
    case 'X':  
      digitalWrite(LED_BUILTIN, HIGH);
      delay(3*TIME_UNIT); //DASH
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(TIME_UNIT); //DOT
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(TIME_UNIT); //DOT
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(3*TIME_UNIT); //DASH 
      digitalWrite(LED_BUILTIN, LOW);
      delay(3*TIME_UNIT); //SPACE BETWEEN LETTERS OF A WORD
      break;
    case 'y':  
    case 'Y':  
      digitalWrite(LED_BUILTIN, HIGH);
      delay(3*TIME_UNIT); //DASH
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(TIME_UNIT); //DOT
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(3*TIME_UNIT); //DASH
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(3*TIME_UNIT); //DASH
      digitalWrite(LED_BUILTIN, LOW);
      delay(3*TIME_UNIT); //SPACE BETWEEN LETTERS OF A WORD
      break;
    case 'z': 
    case 'Z':  
      digitalWrite(LED_BUILTIN, HIGH);
      delay(3*TIME_UNIT); //DASH
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(3*TIME_UNIT); //DASH 
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(TIME_UNIT); //DOT
      digitalWrite(LED_BUILTIN, LOW);
      delay(TIME_UNIT); //DOT DURATION SILENCE
      digitalWrite(LED_BUILTIN, HIGH);
      delay(TIME_UNIT); //DOT
      digitalWrite(LED_BUILTIN, LOW);
      delay(3*TIME_UNIT); //SPACE BETWEEN LETTERS OF A WORD
      break;
    case ' ':    
      digitalWrite(LED_BUILTIN, LOW);
      delay(4*TIME_UNIT); //WHITESPACE = 7 TIME_UNIT [4 + (3 OF THE PREVIOUS SPACE BETWEEN LETTERS OF A WORD)]
      break;
  }
}

