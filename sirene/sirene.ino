/*
   Son des sirènes des véhicules prioritaires:

   u = cycles/min
   +---------+--------+ +---------+-------------+
   |  Type   | POLICE | |  Type   | GENDARMERIE |
   |  Ton 1  | 435 hz | |  Ton 1  |   435 hz    |
   |  Ton 2  | 580 hz | |  Ton 2  |   732 hz    |
   |  Ton 3  |  none  | |  Ton 3  |    none     |
   |  Ton 4  |  none  | |  Ton 4  |    none     |
   | Cadence | 50-60u | | Cadence |   50-60u    |
   +---------+--------+ +---------+-------------+

   +---------+---------+ +---------+----------+
   |  Type   | POMPIER | |  Type   | UMH/SAMU |
   |  Ton 1  | 435 hz  | |  Ton 1  |  435 hz  |
   |  Ton 2  | 488 hz  | |  Ton 2  |  651 hz  |
   |  Ton 3  |  none   | |  Ton 3  |   none   |
   |  Ton 4  |  none   | |  Ton 4  |   none   |
   | Cadence | 25-30u  | | Cadence |  50-60u  |
   +---------+---------+ +---------+----------+

   +---------+-------------+
   |  Type   |  AMBULANCE  |
   |  Ton 1  |   420 hz    |
   |  Ton 2  |   516 hz    |
   |  Ton 3  |   420 hz    |
   |  Ton 4  | noTone 1.5s |
   | Cadence |   50-60u    |
   +---------+-------------+
*/


const byte pin = 3; // Buzzer pin
byte current = 0; // Current sound
unsigned int freq[4] = {580, 732, 488, 651};

void setup() {
  Serial.begin(115200);
  while (!Serial);
  Serial.println("Choose or stop a sound:");
  Serial.println("  1- Police");
  Serial.println("  2- Gendarmerie");
  Serial.println("  3- Pompier");
  Serial.println("  4- UMH/SAMU");
  Serial.println("  5- Ambulance");
  Serial.println("  other key- Stop");

  pinMode(pin, OUTPUT);
}

void loop() {
  if (Serial.available()) { // Get sound
    current = Serial.read() - 0x30;
    if(current > 5) current = 0;
  }

  if(current == 0) noTone(pin); // Turn off
  else if(current < 5) {
    tone(pin, 435);
    delay(500); // 60 cycles / min
    tone(pin, freq[current-1]);
    delay(500);
  } else {
    tone(pin, 420);
    delay(333);
    tone(pin, 516);
    delay(333);
    tone(pin, 420);
    delay(333);
    noTone(pin);
    delay(1500);
  }
}
