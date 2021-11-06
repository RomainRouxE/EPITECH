const int L1 = 2; // broche 2 du micro-contrôleur se nomme maintenant : L1
const int BP = 3; // broche 3 du micro-contrôleur se nomme maintenant : BP

void setup() //fonction d'initialisation de la carte
{
//contenu de l'initialisation
pinMode(L1, OUTPUT); //L1 est une broche de sortie
pinMode(BP, INPUT); // BP est une broche d'entree
}

void loop() //fonction principale, elle se répète (s’exécute) à l'infini
{
//contenu du programme
int test = digitalRead(BP); // Lecture de l'entree BP et sockage du résultats dans test

if(test==LOW) // Si test est à l'état bas
{
digitalWrite(L1, HIGH); // Allumer L1
}
else // Sinon
{
digitalWrite(L1, LOW); // Eteindre L1
}
}
