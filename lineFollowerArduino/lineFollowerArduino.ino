int leftInput=A3;
int rightInput=A4;
int leftMotor=13;
int rightMotor=12;
int leftValue = 0;
int rightValue = 0;
void setup()
{
  pinMode (leftMotor, OUTPUT);
  pinMode (rightMotor, OUTPUT);
}
void loop()
{
  leftValue = analogRead (leftInput);
  rightValue= analogRead (rightInput);

 if
   ( leftValue < 945 && rightValue < 945)
   {
     digitalWrite (leftMotor, HIGH);
     digitalWrite (rightMotor, HIGH);
   }
   else
   {

     if
     ( leftValue > 945 && rightValue < 945)
    {
      digitalWrite (leftMotor, LOW);
      digitalWrite (rightMotor, HIGH);
    }
 else {
   if (leftValue < 945 && rightValue > 945)
   {
   digitalWrite (rightMotor, LOW);
   digitalWrite (leftMotor, HIGH);
   }
   else
   {
     if (leftValue > 945 && rightValue > 945)
     {digitalWrite (rightMotor, LOW);
       digitalWrite (leftMotor, LOW);
     }}           
      }
    }}
