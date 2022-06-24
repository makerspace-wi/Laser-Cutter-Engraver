# Laser-Cutter-Engraver
Docu-Links:
[Aktuelle Dokumentation](https://github.com/makerspacewi/Laser-Cutter-Engraver/tree/master/doc/Laserengraver.pdf)
Mid Size Laser Cutter &amp; Engraver with [20W Diode Laser](https://nejetool.com/module_20w.html)
<br><br>
Bei diesem Gerät handelt es sich um ein DIY-Gerät, begonnen von unserem Mitglied Paul K.<br>
Neben unserem 100W CO2-Laser für die gängigsten Aufgaben und unserem 150W DIY Laser Cutter mit großer Bearbeitungsfläche (noch im Aufbau) handelt es sich bei diesem Gerät um einen Experimental Gerät an dem interessierte Mitglieder forschen und Verbesserungen vornehmen.
<br><br>
Es wurde ein X/Y-Tisch mit 20W Dioden-Laser in ein Gehäuse eingebaut - angetrieben durch einen Arduino Uno mit CNC-Shield via [LASER-GBRL][48219cbc].

  [48219cbc]: http://lasergrbl.com/de/ "Laser-GBRL"
  <br>
  Projektdokumentationen sind im [Doku-Ordner](https://github.com/makerspacewi/Laser-Cutter-Engraver/tree/master/doc) gesammelt, bzw. im [Wiki](https://github.com/makerspace-wi/Laser-Cutter-Engraver/wiki) zu finden.
### Safety- und Marker Modul
Ziel ist ein einfaches Modul zu entwickeln, dass zum einen die Sicherheitsaspekte der Mitglieder sicher stellt und zum anderen einen Modus erlaubt, bei geöffnetem Arbeitsraum den Dioden-Laser mit sehr geringer Leistung (0,1 mW) zu aktivieren, um Werkstück und Laser auszurichten.
<br><br>
#### Funktionsbeschreibung:
Der Deckelschalter bestromt bei geschlossenem Deckel das Kleinsignalrelais und nur wenn das 12V Netzteil eingeschaltet, der Deckelschalter geschlossen und alle Kabel angeschlossen sind, kann das 'LASER ON' Signal vom Controller an die Lasereinheit weitergeleitet werden.<br>Wird der Deckel geöffnet, fällt das Relais ab und das 'LASER ON' Signal vom Controller an die Lasereinheit ist unterbrochen. Die Lasereinheit ist jetzt mit dem Controller auf dem Modul verbunden. Durch Betätigen des Tasters wird der Laser auf der kleinstmöglichen Leistungsstufe ein- und ausgeschaltet - er erzeugt ein Leuchtpunkt auf dem Werkstück, damit dieses entsprechend ausgerichtet werden kann.<br>
Eine kleine rote Leuchtdiode zeigt diese Funktion an.
#### Schaltbild:
<img src='doc/Safety & Marker Circuit/Screenshot 2019-03-03 13.00.21.png' width='100%'>

#### Beschaltung:
<img src='/images/2019/02/beschaltung-modul.jpg' width='100%'>
