void setup() {
  Serial.begin(9600);
  Serial.println("welcome to height predictor\n");
  int i = 0;
  float sumX=0, sumX2=0, sumY=0, sumXY=0, c, m;
  while(!0) {
      i++;
      Serial.print("please enter age of person ");
      Serial.print(i);
      Serial.print(": ");
      while(Serial.available()==0) {}
      float a = Serial.parseFloat();
      Serial.println(a);
      Serial.print("please enter height of person ");
      Serial.print(i);
      Serial.print(" in centimeter: ");
      while(Serial.available()==0) {}
      float h = Serial.parseFloat();
      Serial.println(h);
      Serial.print("Age of person ");
      Serial.print(i);
      Serial.print(" is ");
      Serial.println(a);
      Serial.print("Height of person ");
      Serial.print(i);
      Serial.print(" is ");
      Serial.println(h);
      Serial.println("do you want to input more info? [y/n]");
      while(Serial.available()==0) {}
      char p = Serial.read();
      Serial.println(p);

      sumX += a;
      sumX2 += (a*a);
      sumY += h;
      sumXY += a*h;
      
      if(p=='n') { break; }
  }

m = (i*sumXY-sumX*sumY)/(i*sumX2-sumX*sumX);
c = (sumY - m*sumX)/i;

Serial.println("\nnow it's time to predict the height of a person from his/her age");
Serial.print("please enter age of person: ");
while(Serial.available()==0) {}
float a = Serial.parseFloat();
Serial.println(a);
float predictedAge = m*a + c;
Serial.print("we predict using linear regression that the person aged ");
Serial.print(a);
Serial.print(" years old is ");
Serial.print(predictedAge);
Serial.println(" centimeters tall.");
}

void loop() {
  // put your main code here, to run repeatedly:

}
