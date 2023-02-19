# Laser-Cutter-Engraver
Docu-Links:
[Aktuelle Dokumentation](https://github.com/makerspacewi/Laser-Cutter-Engraver/tree/master/doc/Laserengraver.pdf)<br>
Mid Size Laser Cutter &amp; Engraver with [20W Diode Laser](https://nejetool.com/module_20w.html)
<br><br>
Bei diesem Gerät handelt es sich um ein DIY-Gerät, begonnen von unserem Mitglied Paul K.
<br><br>
Dieser Laser-Engraver wurde vom Makerspace Technik-Team 2022/2023 grundlegend modifiziert.
Die Maschine wurde teilweise neu verkabelt, erhielt neue Energieketten, einen Air-Assist Anschluss und kleinere mechanische Änderungen.  
Es handelt sich dabei um einen X/Y-Tisch mit 36W Dioden-Laser (optisch 5,5W Dauer & 7,5W Puls) in ein Gehäuse eingebaut - gesteuert durch ein Makerbase MKS32 v2.1 Board (32Bit) und ein brandneues 32Bit Betriebssystem FluidNC. Der große Vorteil hierbei ist, dass sämtlich Parameter in einer quasi Text-File (config.yaml) eingetragen und bei Bedarf sehr einfach geändert werden können.<br>
So wird die X-Achse mit einem Motor und die Y-Achse mit 2 Motoren angetrieben und endlich kann die Maschine auch 'Homen'. 
<br><br>
Es gibt noch 2 weitere Module: Das Safety-, Marker und Blower Modul und ein 4 Kanal Opto-Koppler Modul

### Safety-, Marker und Blower Modul
Dieses Modul stellt zum einen die Sicherheitsaspekte der Mitglieder sicher - d.h. der Laser kann vom Controller nur dann angesteuert werden, wenn der Deckel geschlossen ist, zum anderen einen Modus, bei geöffnetem Arbeitsraum den Dioden-Laser mit sehr geringer Leistung (0,1 mW) zu aktivieren, um Werkstück/Laser auszurichten und übernimmt das Einschalten der Lüfter wenn der Laserkopf in Betrieb ist.
<br><br>
#### Funktionsbeschreibung:
Der Deckelschalter bestromt bei geschlossenem Deckel das Kleinsignalrelais und nur wenn das 12V Netzteil eingeschaltet, der Deckelschalter geschlossen und alle Kabel angeschlossen sind, kann das 'LASER ON' Signal vom Controller an die Lasereinheit weitergeleitet werden.<br>Wird der Deckel geöffnet, fällt das Relais ab und das 'LASER ON' Signal vom Controller an die Lasereinheit ist unterbrochen. Die Lasereinheit ist jetzt mit dem Controller auf dem Modul verbunden. Durch Betätigen des Tasters wird der Laser auf der kleinstmöglichen Leistungsstufe ein- und ausgeschaltet - er erzeugt ein Leuchtpunkt auf dem Werkstück, damit dieses entsprechend ausgerichtet werden kann.<br>
Eine kleine rote Leuchtdiode zeigt diese Funktion an.
<br><br>
Projektdokumentationen sind im [Doku-Ordner](https://github.com/makerspacewi/Laser-Cutter-Engraver/tree/master/doc) gesammelt, bzw. im [Wiki](https://github.com/makerspace-wi/Laser-Cutter-Engraver/wiki) zu finden.
#### Schaltbild:


#### Beschaltung:

