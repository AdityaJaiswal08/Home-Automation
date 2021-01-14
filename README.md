# Home-Automation
Making an actual box that can be incorporated anywhere by just giving it power and connecting wires. Works with an android application and hence can be controlled from anywhere in the world.

#Programming Node MCU
The programming part was quite easy as we just needed to use open source library for creating a local server on my router and creating cases for
every request it recieved and processing it.

#Andriod App
The .apk file in this repository is the app that I made for sending HTTPS request to the server created on Node MCU, and getting a reply from it 
using the GET method for verification. However as a security aspect, We have to first enter the last 2 digits of Local IP that the server is hosted on,
only then can we send these requests successfully, otherwise these requests will fail.

#3D Modelling
I modelled a 3D case for keeping all the hardware components in. This was done in Fusion 360 and was exportes as stl file for slicing in Ultimaker Cura and 3D printed the 
case using a 3D printer.
