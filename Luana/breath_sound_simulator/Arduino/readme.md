# Breath Sound Simulator
It is a program developed in the language C that plays mp3 files that has different lung diseases in order that the medical/nursing student can listen the sound and diagnose the disease that the patient has. In this way the program simulates the breathing of a patient.

# Converting MP3 to WAV
**Download [Audacity](http://www.audacityteam.org/).**
Open the mp3 file on Audacity trim the piece of sound you want.
Export it as WAV 16bit.

**Download mplayer.**
```
	$ sudo apt-get install mplayer

	$ mplayer -ao pcm <name>.mp3
```

**Download SoX.**
```
	$ sudo apt-get install sox

	$ sox <name>.mp3 -c 1 -r 8000 -e unsigned-integer -b 8 <name>.wav
```

# Converting sounddata
**Download [wav2c](https://github.com/olleolleolle/wav2c).**
Open the downloaded folder on terminal.
```
	$ make
```
execute the command:
```
	$ ./wav2c <name>.wav sounddata.h sounddata
```

# Compressing sounddata
**Download compress.cc.** and save it in the same folder as wav2c.
```
	$ g++ compress.cc -o compress

	$ ./compress
```
This program will generate a new_sounddata.h that you will copy and paste it on the arduino PCMAudio folder.
After that just connect your arduino, load the PCMAudio code and enjoy it. 

# Reference
MP3 convertion: (https://github.com/olleolleolle/wav2c).

Arduino code: (http://playground.arduino.cc/Code/PCMAudio).
