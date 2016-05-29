# Midi Pedalboard with Arduino

The scope of this project is to realized a MIDI pedalboard controlled by Arduino. I'm using it with Amplitube, but you can use it with any program that uses the MIDI protocol.

First of all, I suggest to use <b>Arduino Leonardo</b> because it supports MIDI protocol (with a little hack...). If you want, you can realized this project with any type of Arduino, but in that case you must use a software called <i>Hairless Midi</i> and <i>loopMidi</i>. This software helps you to create a virtual MIDI port and to convert Serial signal into MIDI signal.

By the way, first of all follow this tutorial to prepare the environment and the board: <a href="https://github.com/rkistner/arcore">https://github.com/rkistner/arcore</a>.

Now you should prepare four (or more if you want) switches and insert them in Arduino like the picture in <b>img/schematic.jpg</b>. After doing that, download the sketch and upload it on the board.

Finally open Amplitube, insert pedal that you want to control and click on the MIDI button. Now:

1)Go to control Change;
2)On the Preset tab click <b>Add</b>;
3)Add the pedal that you have inserted in the chain (add two time, bypass mode);
4)Select the first row and click "learn";
5)Press the button. Amplitube assign a MIDI channel to the effect;
6)Repeat the process for the second row;
7)On the second row set min to 100% and max to 0%;

If you want you can see the picture in <b>img/amplitube.jpg</b>. In my case i've inserted a delay.

Enjoy!
