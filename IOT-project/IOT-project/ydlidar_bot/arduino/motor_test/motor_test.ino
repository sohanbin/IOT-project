// 모터 1을 제어하기 위한 핀 번호
const int ENA = 10;
const int IN1 = 7;
const int IN2 = 8;

// 모터 2를 제어하기 위한 핀 번호
const int ENB = 9;
const int IN3 = 5;
const int IN4 = 6;

void setup() {
  // 모터 제어용 핀을 출력 모드로 설정
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // 시리얼 통신 시작
  Serial.begin(9600);
}

void loop() {
  // 시리얼 입력을 읽음
  if (Serial.available() > 0) {
    char command = Serial.read();

    // 입력된 명령어에 따라 모터를 제어
    switch (command) {
      case 'F': // 앞으로 이동
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        analogWrite(ENA, 200);
        analogWrite(ENB, 200);
        break;

      case 'B': // 뒤로 이동
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        analogWrite(ENA, 200);
        analogWrite(ENB, 200);
        break;

      case 'L': // 좌회전
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        analogWrite(ENA, 200);
        analogWrite(ENB, 200);
        break;

      case 'R': // 우회전
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        analogWrite(ENA, 200);
        analogWrite(ENB, 200);
        break;

      case 'S': // 정지
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
        analogWrite(ENA, 0);
        analogWrite(ENB, 0);
        break;
    }
  }
}
