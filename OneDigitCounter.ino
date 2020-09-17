
int Units = 9;          //This pin Enables the Display
int Counter = 0;
unsigned long Timer = 0;

int Zero[7] = {1,1,1,0,1,1,1};  //Combination for Zero
int One[7] = {0,0,1,0,0,0,1};   //Combination for One
int Two[7] = {1,1,0,1,0,1,1};   //Combination for Two
int Three[7] = {0,1,1,1,0,1,1}; //Combination for Three
int Four[7] = {0,0,1,1,1,0,1};  //Combination for Four
int Five[7] = {0,1,1,1,1,1,0};  //Combination for Five
int Six[7] = {1,1,1,1,1,1,0};   //Combination for Six
int Seven[7] = {0,0,1,0,0,1,1}; //Combination for Seven
int Eight[7] = {1,1,1,1,1,1,1}; //Combination for Eight
int Nine[7] = {0,1,1,1,1,1,1};  //Combination for Nine

void Units_DisplayNumber(int Number[7]){  //Function to Display
  for (int i = 0; i < 7; i++){
    if(Number[i] == 1){
      digitalWrite(i+2,HIGH);
    }
    else{
      digitalWrite(i+2,LOW);
    }
  }
}

void setup(){
  for(int i = 2; i < 9; i++){   //Setting pins from 2 to 8 as 
    pinMode(i,OUTPUT);          //OUTPUT
  }
  pinMode(Units, OUTPUT);
  digitalWrite(Units,LOW);   //Enabling the Display
}

void DisplayNumber(int Units_Value){  //Number to Display
    if(Units_Value == 0)   Units_DisplayNumber(Zero);
    else if(Units_Value == 1)  Units_DisplayNumber(One);
    else if(Units_Value == 2)  Units_DisplayNumber(Two);
    else if(Units_Value == 3)  Units_DisplayNumber(Three);
    else if(Units_Value == 4)  Units_DisplayNumber(Four);
    else if(Units_Value == 5)  Units_DisplayNumber(Five);
    else if(Units_Value == 6)  Units_DisplayNumber(Six);
    else if(Units_Value == 7)  Units_DisplayNumber(Seven);
    
    else if(Units_Value == 8)  Units_DisplayNumber(Eight);
    else if(Units_Value == 9)  Units_DisplayNumber(Nine);
}

void loop() {
  if(millis() > Timer+1000){    //Incrementing count every second
    Counter++;
    Timer = millis();
    }
  DisplayNumber(Counter);       //Displaying the number
  if(Counter > 9)  Counter = 0; //Zeroing the number if it 
                                //crosses 9
}

