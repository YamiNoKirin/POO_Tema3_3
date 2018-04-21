# POO_Tema3_3
A treia tema la laboratorul de POO, tema 3 din lista (Atelier Auto)

Atelier auto: Exista mai multe categorii de vehicule (motocicleta, bicicleta, automobil) care pot sosi la un garaj pentru a descoperi ce probleme tehnice au si a obtine un deviz de reparatii. Fiecare vehicul poate avea probleme din diferite categorii: frane, directie, noxe, motor, caroserie. Nu toate vehiculele pot avea toate tipurile de probleme. Fiecare tip de problema are o solutie tehnica ce presupune un anumit consum de materiale (de diferite tipuri) si un anumit efort uman (in ore-om). Fiecare material are un cost la fel ca si ora-om de efort uman. Pentru fiecare vehicul ce soseste in garaj trebuie calculat devizul estimativ.
Precizari:

Tipurile de probleme vor include cel putin:
    - Frane – placute uzate (fata/spate la un auto/moto)
    - Discuri uzate (oricare din 4 la un auto, oricare din 2 la moto)
    - Lant tocit (bicicleta)
    - Lant lipsa (bicicleta)
    - Defectiune capitala;
    - Motor:
        - Nivel ulei scazut (la moto si auto)
        - Carburator murdar (la auto)
        - Motor topit (la moto si auto)
    - Directie:
        – Ghidon stramb (bicicleta, moto)
        - Roata stramba (toate)
        - Defectiune capitala (toate)
    - Noxe:
        – Vehiculul arde ulei (moto si auto);
        - Vehiculul este anterior anului 2000 (moto si auto)
    - Caroserie (auto):
        – Caroserie corodata de rugina
        - Caroserie stramba (aripi stanga/dreapta, fata/spate, bara, capota):
            - foarte stramba sau asa-si-asa (pe fiecare componenta in parte)

Solutiile presupun un consum de materiale:
    - Materialele sunt toate la bucata
    - Placutele de frana de pe spate difera de cele de pe fata
    - Placutele de frana sunt aferente fiecarei roti
    - Nivel ulei scazut, motor topit si vehiculul arde ulei toate presupun schimb de ulei
    - Fiecare problema are o solutie (mai putin defectiunea capitala)
    - Pot exista tipuri de materiale comune mai multor solutii
    - Toate solutii consuma suruburi (minim 5).
    - Vehiculul suporta operatiuni de traumatizare (e.g. Uzeaza discul de frana de pe spate dreapta sau Incepe sa arzi ulei)
    - Vehiculul odata conectat la tester (in atelier) se va putea autodiagnostica verificand fiecare componenta a sa si
      returnand lista de probleme.

