# Beta

<h2> Funzionalità </h2>
<ul>
    <li> Accensione e spegnimento dei LED frontali
    <li> Guida mediante frecce direzionali
    <li> Guida mediante controllo vocale
    <li> Guida autonoma (da perfezionare)
</ul>

<h2> Controllo remoto </h2>
Mediante l'app <a href="https://github.com/IISMarconi/HalfAndroid">Half Android</a> (da cambiare) o mediante l'app <a href="https://play.google.com/store/apps/details?id=braulio.calle.bluetoothRCcontroller&gl=IT">RC Car Controller</a>. Il programma attualmente caricato sull'arduino permette il controllo solo con l'app Half Android. Per scegliere con quale applicazione comandarla basta cambiare la macro nel file sorgente .ino:<br>
<i>&nbsp;&nbsp;&nbsp;&nbsp;#define HALF_ANDROID</i><br>
<i>&nbsp;&nbsp;&nbsp;&nbsp;#define RC_APP</i><br>

<h2>Hardware Elettronico</h2>
<ul>
    <li> 1 Arduino Uno
    <li> 1 Motorshield Adafruit-like
    <li> 1 Modulo Bluetooth HC-05 (Indirizzo MAC: )
    <li> 1 Sensore ad ultrasuoni SR-HC04
    <li> 2 LED
    <il> 2 Gear Dc Motor 
</ul>
