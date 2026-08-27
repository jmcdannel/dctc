> [!IMPORTANT]
> **This project has moved.** Active development of DEJA.js and the Track & Trestle model
> railroad platform now happens in private repositories under
> [**Track and Trestle Technology, LLC**](https://github.com/trackandtrestle).
> This repository stays public as a historical snapshot and is no longer maintained.
>
> **Current product, docs, and downloads → [dejajs.com](https://dejajs.com)**

# 🎛️ DCTC — DC Train Controller

**Arduino firmware for running a DC model railroad without a computer.**

<p align="center">
  <img src="https://img.shields.io/badge/Arduino-00878F?style=for-the-badge&logo=arduino&logoColor=white" />
  <img src="https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white" />
</p>

An object-oriented Arduino sketch that drives a two-cab DC layout entirely from physical
hardware — potentiometer throttles, toggle switches, servo-actuated turnouts, and lighting
effects — with no PC, phone, or DCC decoder in the loop.

## 🧱 Design

Rather than one long `loop()`, the sketch is split into small C++ classes, each owning its
own pins and state:

| Class | Responsibility |
|-------|----------------|
| `Cab` | One operator position — pairs a throttle with a track and its controls |
| `Throttle` | Reads the potentiometer, applies braking and momentum, writes PWM |
| `Track` | Power, polarity/direction, and block assignment |
| `Turnout` | Servo positions for straight vs. divergent, driven over I²C |
| `ToggleSwitch` | Debounced physical input with edge detection |
| `Effect` | Lighting and accessory outputs |

## 🔌 Hardware

- Arduino Mega (uses pins well past the Uno's range)
- [Adafruit 16-channel PWM servo driver](https://www.adafruit.com/product/815) over I²C for turnout servos
- Motor driver per track block, PWM speed control at 50 Hz
- Panel-mounted potentiometers, direction and power toggles, brake buttons

Pin assignments and servo throw angles are configured with `#define` blocks at the top of
[`dctraincontrol.ino`](dctraincontrol.ino).

## 🧑‍💻 Building

Open `dctraincontrol.ino` in the Arduino IDE, install the **Adafruit PWM Servo Driver**
library, select an Arduino Mega, and upload.

## 📌 Status

Complete and still the fallback controller for DC-only sections of the layout. The
`Cab` / `Throttle` / `Turnout` abstractions here were carried forward almost unchanged
into the later DCC-EX work.

## 🧭 Where this fits

This repo is one step in a long-running line of model railroad control software:

| Era | Project | What changed |
|-----|---------|--------------|
| 2020 | [`train-control`](https://github.com/jmcdannel/train-control) | First React throttle, JMRI + Arduino over HTTP |
| 2021 | [`dctc`](https://github.com/jmcdannel/dctc) | Standalone Arduino DC controller (no computer required) |
| 2022–23 | [`layout-conductor-*`](https://github.com/jmcdannel?tab=repositories&q=layout-conductor) | Split into app + API; Python, Node, and Deno backends explored |
| 2024 | [`Track-and-Trestle-Technology-Suite`](https://github.com/jmcdannel/Track-and-Trestle-Technology-Suite) | MQTT-based monorepo: dispatcher, throttle, dashboard, action API |
| 2024–25 | [`DEJA.js`](https://github.com/jmcdannel/DEJA.js) | TypeScript/Turborepo rewrite, Firebase realtime backbone |
| 2025– | **[dejajs.com](https://dejajs.com)** (private) | Commercial cloud platform for DCC-EX |

---

<sub>Built by [Josh McDannel](https://github.com/jmcdannel) · [dejajs.com](https://dejajs.com) · [LinkedIn](https://www.linkedin.com/in/jmcdannel)</sub>
