# Small-Smart-Home-AVR

In this project I used three analog sensors i.e. Temp, LPG Gas and LDR. These are given analog output. So as per interfacing required, I connected all the analog output of the sensors to in-build ADC to get digital values and keypad, DC Motor, LCD Display, buzzer, transistors and LED to i/o pins of the microcontroller. For connections, please refer schematic diagram as given below.

Now when power on, first Red LED indicates the power status of the system and if it is then all peripherals are initialized and their current value will be displayed on LCD after welcome message ‘WELCOME TO SMART HOME’. Now every sensor has their threshold value according to ADC conversion mentioned in C Source Code according to the requirements and all o/p device are controlled by microcontroller based on sensors output and act accordingly. We can change those threshold values according to our need by changing in C Source code any time.
