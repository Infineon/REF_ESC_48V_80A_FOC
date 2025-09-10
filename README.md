# REF_ESC_48V_80A_FOC code example for Drones
<a href="https://www.infineon.com">
<img src="./images/Logo.svg" align="right" alt="Infineon logo">
</a>
<br>
<br>

## Overview

This code example demonstrates sensorless field-oriented control (FOC) for drone motors using the Infineon's PSOC™ Control C3 MCU and XENSIV™ TLx5572 TMR current sensor on the REF_ESC_48V_80A_FOC Electronic Speed Controller (ESC) reference design. This code example includes the following solutions based on Rotor Field Oriented (RFO) control: 
- Sensorless PMSM FOC with 3-phase active sensing

Additionally this code demonstrates flightcontroller communication for: 
- transmitting throttle commands from the flightcontroller to the ESC 

## Features

- 3.3 V 32-bit microcontroller Arm® Cortex®-M33 180 MHz PSOC™ Control C3 with 256 kB Flash and 64 kB RAM
- PWM and DShot interface for communication to drone flightcontroller
- High power density power stages using newest OptiMOS™ 8 technology, providing up to 2 kW power
- true 3-phase, non-invasive current sensing using XENSIV™ TMR-based current sensors
- Full motor control firmware framework for fast evaluation and adaption

### Featured Infineon Products 
<p>Following products are featured by the reference hardware:
<br>
<br>
<table style="width:100%">
  <tr>
    <th>Product</th>
    <th>Description</th>
  </tr>
  <tr>
    <td><a href="https://www.infineon.com/part/PSC3M5FDS2LGQ1">PSC3M5FDS2LGQ1</a></td>
    <td>PSOC™ Control C3 - high performance microcontroller tailored for motor control</td>
  </tr>
  <tr>
    <td><a href="no link">TLI5572</a></td>
    <td>XENSIV™ TLI5572 TMR-based current sensor with integrated op-amp</td>
  </tr>
  <tr>
    <td><a href=https://www.infineon.com/part/1EDN7550B">1EDN7550B</a></td>
    <td>EiceDRIVER™ 1EDN7550B TDI gate driver</td>
  </tr>
  <tr>
    <td><a href="no link">ISC019N10NM8</a></td>
    <td>OptiMOS™ 8 power MOSFET 100 V, 1.9 mΩ in a SuperSO8 (5x6) package</td>
  </tr>
  <tr>
    <td><a href="https://www.infineon.com/part/TLS202B1MBV33">TLS202B1MBV33</a></td>
    <td>Monolithic integrated post voltage regulator for load currents up to 150 mA</td>
  </tr>
</table>
</p>
<br>

## Hardware requirements and setup

- ESC reference design board: [REF_ESC_48V_80A_FOC](no link).
- Associated motor, with known motor parameters. This example code is tuned for the following motor: [T-MOTOR MN501 KV240](https://shop.tmotor.com/products/mn501-s-multirotor-motors?srsltid=AfmBOorVqzCgUWqT5IR4bjkh6lcpRiYYxB-5boWXSW14rMeAczjffISg)
- Programmer and Debugger for the board e.g. [XMC™ Link](https://www.infineon.com/evaluation-board/KIT-XMC-LINK-SEGGER-V1).

See the respective kit quick start guide for the hardware setup information. For details, see the [User Manual](no link)  of the above reference design board. 
