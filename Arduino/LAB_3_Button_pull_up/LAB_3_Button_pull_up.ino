#define buttonPin 2
void setup() {
  Serial.begin(9600); // กำหนดความเร็ว (Baud Rate) ในการรับ-ส่งค่าออกไปยังขา Serial ซึ่งโดยทั่วไปหากต้องการส่งไปยังเครื่องคอมฯ จะใช้ความเร็วที่ 9600 หรือ 115200 หากเป็นอุปกรณ์สื่อสารอื่นต้องไปดู datasheet ของอุปกรณ์นั้นๆ
  pinMode(buttonPin,INPUT);
}

void loop() {
  int buttonValue = digitalRead(buttonPin); 
  /* 
  คำสั่ง digitalRead คือคำสั่งที่ใช้อ่านค่าสถานะจากขาที่กำหนด โดยทั่วไปจะเป็น 0 หรือ 1 ซึ่ง 
  0 คือไม่มีไฟฟ้าวิ่งผ่าน
  1 คือมีไฟฟ้าวิ่งผ่าน 
  */
  Serial.println(buttonValue);
  /*
  คำสั่ง println เป็นคำสั่งที่ใช้ในการส่งค่าออกยังเส้นทางที่กำหนด ในที่นี้ส่งออกไปทางช่องทาง Serial ไปยังอุปกรณ์ที่กำหนดไว้ ค่าที่ส่งไปคือค่าที่อยู่ในตัวแปร buttonValue
  */
}
