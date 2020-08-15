# Fabric_Piano
The idea is to use the same method as in Fabric piano to build a small prototype of another keyboard musical instrument. This would be the minimal form of the fabric piano with 3-6 keys.  Originally, I planned to build a demonstration of a string instrument like Ukulele but the chords and further brainstorming made me realize the complexity involved in it. It will require more keys for creating simple music. So, I opted for the keyboard musical instrument. The conductive property of the conductive threads(sensory input) is used to read a signal using the micro-controller. The speaker(output device) is used to produce the sound. The idea is to let the user touch one of the keys on the instrument and create music. I recreated the piano notes(a sequence of 3-6, which can be reproduced using the speaker) keys like in a regular piano. Inside the buzzer is a coil of wire and a small magnet, through which when current flows produces a tiny "click". When done thousands of times per second, the clicks create tones. In other words, the frequency of the clicks is used to produce different sounds. Technically, the user would be touching a conductive thread patch which leads to music generation.

## Estimated duration : 2 weeks(Complete dedication)

## Pre-requisite:
- Software :
    - Arduino
- Hardware :
    - Lilypad Arduino(Or any controller) 
    - Conductive thread
    - Lilypad buzzer(Speaker)
 
## Prototype building phase I:
- Analyzed the behaviour of Aluminium foil and copper conductive thread in capacitance sensing
- Tried different methods of capacitance sensing(hardware + code changes)

## Prototype building phase II :
-  The placement of all the components on the frame was designed
-  The conductive patches were tested

## Prototype building phase III :
-  The Piano keys were stitched
-  The speaker was interfaced and the Piano key notes were mapped to the frequency of the speaker
-  The final sewing of all components has to be done

## Prototype building phase IV :
-  The sewing was done
-  Final code uploaded

## Directories explained:
-  tests/code : 
    - Capacitance_read.ino
    - Read_Keys.ino
    - Speaker_test1.ino
    - Fabric_piano_v3.ino
-  Images : Contains the upgrades/progress
-  audio_files : Contains the audio data tested

## Progress update:

The week 4 update:
- The final code was written and tested

The week 3 update:
- 5 Piano keys stitched
- The speaker placement done
- The speaker sound check done
- The piano key notes, frequency encoding done
- The final code written(to be tested)

The week 2 update:
- The Piano key was stitched with the conductive patch.
- The crosses indicate the placement of the conductive patch. The wooden pieces were set in order to provide a stiff support underneath the keys for better capacitance sensing. 
- The code was further altered to read the conductive patch and recognize different keys. The sensing was calibrated to read the keys. The output was displayed in the serial monitor as the following video.
- The placement of the controller was planned.

## Fabric Piano explained
-  https://drive.google.com/file/d/13t_XeVNtMl5TdA2EuHlnGKRsvfMPMWyE/view?usp=sharing

## Acknowledgement:
- sewelectric.org/diy-projects/5-fabric-piano/
- https://www.arduino.cc/en/Tutorial/toneMelody
