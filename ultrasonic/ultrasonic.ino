// 设定SR04连接的Arduino引脚
const int TrigPin = 2; 
const int EchoPin = 3; 
const int fmpin=13;  //设置蜂鸣器数字接口13
float distance; 
int d = 0;
void setup() {   // 初始化串口通信及连接SR04的引脚
	Serial.begin(9600); 
	pinMode(TrigPin, OUTPUT); 
	pinMode(fmpin,OUTPUT);
	// 要检测引脚上输入的脉冲宽度，需要先设置为输入状态
	pinMode(EchoPin, INPUT); 
	Serial.println("Ultrasonic sensor:");
} 
void loop(){ 
	// 产生一个10us的高脉冲去触发TrigPin 
	digitalWrite(TrigPin, LOW); 
	delayMicroseconds(2); 
	digitalWrite(TrigPin, HIGH); 
	delayMicroseconds(10);
	digitalWrite(TrigPin, LOW); 
	// 检测脉冲宽度，并计算出距离
	distance = pulseIn(EchoPin, HIGH)/ 58;
	
	Serial.print(distance); 
	Serial.print("cm"); 
	Serial.println(); 
	
	digitalWrite(fmpin,HIGH);
	delayMicroseconds(500);
        digitalWrite(fmpin,LOW);
        d = distance * 100;
	delay(d); 
}
