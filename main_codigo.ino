// Sentencia de los puertos Ultrasonicos
const int trigPin_R = 9;
const int echoPin_R = 8;
const int trigPin_F = 11;
const int echoPin_F = 10;
const int trigPin_L = 13;
const int echoPin_L = 12;

// Variables de calculo de distancia
long duracion;
int distancia;

// Funcion de distancia
int distancias(long d){
  return (d * 0.034) / 2;
}

// Funcion de sensores
long duraciones (const int echo, const int trig){
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  return pulseIn(echo, HIGH);
}

// Sentencias iniciales del microcontrolador
void setup() {

  pinMode(trigPin_R, OUTPUT);
  pinMode(echoPin_R, INPUT);
  pinMode(trigPin_L, OUTPUT);
  pinMode(echoPin_L, INPUT);
  pinMode(trigPin_F, OUTPUT);
  pinMode(echoPin_F, INPUT);

  // Serial
  Serial.begin(9600);
}

void loop() {

  // Sentencias de trigers a bajo
  digitalWrite(trigPin_L, LOW);
  digitalWrite(trigPin_R, LOW);
  digitalWrite(trigPin_F, LOW);
  delayMicroseconds(2);
  
        // Sensor Izquierda //
  duracion = duraciones(echoPin_L, trigPin_L);
  distancia = distancias(duracion);

// ### Parametros de sensor 1 enviados ### // // Primer sensor en mandar (Izquierda)
  Serial.print(distancia);
  delay(1);

        // Sensor Frente //
  duracion = duraciones(echoPin_F, trigPin_F);
  distancia = distancias(duracion);

// ### Parametros de sensor 2 enviados ### // // Primer sensor en mandar (Frente)
  Serial.print("A");
  delay(1);
  Serial.print(distancia);
  delay(1);

        // Sensor Derecha //
  duracion = duraciones(echoPin_R, trigPin_R);
  distancia = distancias(duracion);

// ### Parametros de sensor 3 enviados ### // // Primer sensor en mandar (Derecha)
  Serial.print("A");
  delay(1);
  Serial.print(distancia);
  delay(1);
  Serial.print("F");
  
  delay(200);
}
