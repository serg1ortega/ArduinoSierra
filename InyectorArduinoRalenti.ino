int enaPin = 9;  // Pin para controlar la velocidad del inyector
int in1Pin = 10; // Pin de control 1
int in2Pin = 11; // Pin de control 2

void setup() {
  pinMode(enaPin, OUTPUT);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
}

void loop() {
  abrirInyector();  // Abre el inyector
  delay(10);        // Espera 10 ms
  cerrarInyector();  // Cierra el inyector
  delay(40);        // Espera 40 ms
}

void abrirInyector() {
  digitalWrite(in1Pin, HIGH);
  digitalWrite(in2Pin, LOW);
  analogWrite(enaPin, 255);  // Puedes ajustar este valor para controlar la velocidad del inyector
}

void cerrarInyector() {
  digitalWrite(in1Pin, LOW);
  digitalWrite(in2Pin, HIGH);
  analogWrite(enaPin, 0);  
}
