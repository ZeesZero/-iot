#define VR A0
#define ledPin 3

void setup() {
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
}

void loop() {
  int val = analogRead(VR);
  int PWM = map(val, 0, 1023, 0, 255);
  float v = (val / 1023.00) * 5.00;
  /* 
  map เป็น function ที่ใช้ในการแปลงค่าจากค่าช่วงค่าหนึ่งไปเป็นอีกช่วงค่าหนึ่ง 
  รูปแบบ map(ค่าที่ต้องการแปลง, ช่วงค่าเดิมต่ำสุด, ช่วงค่าเดิมสูงสุด, ช่วงค่าใหม่ต่ำสุด, ช่วงค่าใหม่สูงสุด)

  ตัวแปรประเภท float ใช้เก็บจำนวนจริง (ตัวเลขทศนิยม) ในช่วงค่า -3.4028235E+38 ถึง 3.4028235E+38 มีทศนิยมได้ 6 ถึง 7 ตำแหน่ง
  ข้อแนะนำในการคำนวณตัวแปรประเภท float ถ้านำจำนวนเต็มมาร่วมคำนวณ ต้องเอา .00 ไปเติมต่อท้ายจำนวนเต็ม 
  โดยที่จำนวนตัวเลข 0 จะเป้นตัวกำหนดจำนวนตำแหน่งทศนิยม เช่น 3.000 หลังจากคำนวณแล้วจะได้ทศนิยม 3 ตำแหน่ง เป็นต้น
  หากไม่ใส่ ผลลัพธ์ที่ได้มานั้นจะได้เป็นจำนวนเต็ม
  */
  Serial.print(val);
  Serial.print("\t");
  Serial.print(PWM);
  Serial.print("\t");
  Serial.print(v);
  Serial.println("v");
  /*
  ข้อสังเกต
  คำสั่ง println เป็นคำสั่งที่ส่งค่าออกไปแล้วให้ขึ้นบรรทัดใหม่
  คำสั่ง print เป็นคำสั่งที่ส่งค่าออกไปแล้วไม่ต้องขึ้นบรรทัดใหม่
  \t เป็นการส่งค่าระยะห่าง 1 Tab ออกไป
  */
  analogWrite(ledPin,PWM);
  /*
  เป็นคำสั่งที่ใช้ในการสั่งให้ส่งไฟฟ้าออกไปในช่วงระดับ 0-255 
  หากเป็นบอร์ด  Arduino จะเทียบค่า 0v-5v 
  เช่น analogWrite(3,127) บอร์ด Arduino จะส่งแรงดันไฟฟ้าออกไปที่ประมาณ 2.5v ที่ขา 3 เป็นต้น 
  เพราะฉนั้นจะต้องดูที่แรงดันไฟฟ้าที่บอร์ดแต่ละอันที่ใช้
  ส่วนขาใดใช้ได้บ้างต้องดูที่สัญลักษณ์ ~ ที่อยู่คู่กับเลขขาใน pinout ของบอร์ดนั้นๆ
  */
  delay(100);
}
