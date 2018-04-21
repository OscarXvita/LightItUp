## Method 2


Based on Method 1, Method 2 needs a RS485-USB adapter and two 50cm long wires.

<span style="color:red">The Power OFF/ON Signal is a broadcast signal, so make sure you cut off the incoming signal and your packet is sent to your meter only!</span>


Note THAT you MUST NOT forget to restore the communication in 10-45 minutes, you might be in trouble if you forget to turn the switch back on. 

<span style="color:red">It is naive for one to use this method(ie. cut off the signal) to avoid electricity bills update, since the management center will receive alarms if meter's heartbeats has not been seen for some time. If meter lost connection for a long time, say 12 hours), the maintanence team will put your dorm into repair checklist and may get you in trouble. <b>NEVER THINK OF STEALING and PAY YOUR BILL!!!</b></span>

<span style="color:red">NEVER BROADCAST YOUR PAYLOAD!</span>

## Serial Port Configuration
* Baud rate: 2400 bps
* Stop Bit: 1
* Parity bit: Even
* Data Bit: 8

## Setup:

1. Open the power cabinet, find the meter and unscrew its case.
2. Find 2 signal cables. These two cables are usually soft, different with the power cable below and not in connection with the switches.
![Photo](https://preview.ibb.co/gHnh47/img.png)
3. Add a switch. Connect the original cables to one side of the switch and use two cables you prepared to connect with the electric meter.
![Photo](https://image.ibb.co/iioN47/Untitled_Diagram.png)
4. Open the switch normally.
5. Attach another two cable on the electricity meter side of the switch, this makes it easy for us to communicate only with our meter. 
6. Connect RS485 USB adapter to our newly attached cables.
7. Open the Serial Monitor on your computer to check whether the connection is OK.
8. Before sending payload, make sure the switch is off, that means the broadcast package is sent to your electricity meter only.
9. Send the Payload, and BINGO!
10. Disconnect Adapter and Turn on the Switch to restore connnection.

## <span style="color:red"> You should **restore** the connection after  sending the signal in order to keep the heartbeat working.</span>
