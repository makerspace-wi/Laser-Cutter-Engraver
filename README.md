# Laser-Cutter-Engraver
<img witdh="400" src="https://github.com/makerspace-wi/Laser-Cutter-Engraver/blob/master/doc/pictures/IMG_1268%204.jpg"><br>

Mid Size Laser Cutter &amp; Engraver with [NEJE E30130 Diode Laser](https://nejetool.com/index.php/2022/12/21/neje-e30130-laser-module-description-details/) - die Arbeitsfläche ist 780mm x 780mm
<br><br>
Bei diesem Gerät handelt es sich um ein DIY-Gerät, dass ursprünglich nur als Testmaschine gedacht war.
<br><br>
Dieser Laser-Engraver wurde vom Makerspace Technik-Team 2022/2023 grundlegend modifiziert.
Die Maschine wurde teilweise neu verkabelt, erhielt neue Energieketten, einen Air-Assist Anschluss und kleinere mechanische Änderungen.  
Es handelt sich dabei um einen X/Y-Tisch mit 36W Dioden-Laser (optisch 5.5W, Dauer & 7.5W Puls) in ein Gehäuse eingebaut - gesteuert durch ein [Makerbase MKS32 v2.1 Board](https://github.com/makerbase-mks/MKS-DLC32) (32Bit) und ein brandneues 32Bit Betriebssystem [FluidNC](https://github.com/bdring/FluidNC). Der große Vorteil hierbei ist, dass sämtlich Parameter in einer quasi Text-File (config.yaml) eingetragen und bei Bedarf sehr einfach geändert werden können.<br>
So wird die X-Achse mit einem Motor und die Y-Achse mit 2 Motoren angetrieben und endlich kann die Maschine auch 'Homen'.
<br>
Bedient/gesteuert wird der Laser Engraver von einem Windows PC und dem Programm [lightBURN](https://lightburnsoftware.com/) - oder per WLAN und Browser direkt über die WebUI von jedem im Netzwerk eingebundenen Gerät (Laptop, Tablet oder Mobiltelefon).
<br><br>
Es gibt dazu weitere Module: Das Safety-, Marker und Blower Modul und ein 4 Kanal Opto-Koppler Modul

### Safety-, Marker und Blower Modul
Dieses Modul stellt zum einen die Sicherheitsaspekte der Mitglieder sicher - d.h. der Laser kann vom Controller nur dann angesteuert werden, wenn der Deckel geschlossen ist, zum anderen einen Modus, bei geöffnetem Arbeitsraum den Dioden-Laser mit sehr geringer Leistung (0,1 mW) zu aktivieren, um Werkstück/Laser auszurichten und es übernimmt auch das Einschalten der Lüfter wenn der Laserkopf in Betrieb ist.
<br><br>
### 4-Kanal Optokoppler Modul
Über diese Modul werden alle externen Signale (Endschalter und Low Power Laser ein) entkoppelt zu den Controller Eingängen geführt.

<br><br>
Projektdokumentationen sind im [Doku-Ordner](https://github.com/makerspacewi/Laser-Cutter-Engraver/tree/master/doc) gesammelt, bzw. im [Wiki](https://github.com/makerspace-wi/Laser-Cutter-Engraver/wiki) zu finden.
#### Schaltbild:


#### Beschaltung:

# [Zum Laser Engraver Wiki](https://github.com/makerspace-wi/Laser-Cutter-Engraver/wiki)
