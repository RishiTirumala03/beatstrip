# Beat-Based LED Strip Controller

This project aims to create an immersive audio-visual experience by synchronizing an addressable RGB LED strip with the beat of your music. Unlike other solutions that rely on volume, this controller focuses on tempo, ensuring the light display dynamically reflects the rhythm and pace of the music.

## Features

* **Tempo-Driven:** The system prioritizes detecting the music's tempo, enabling the light patterns to accurately mirror the rhythm and pace of the audio.
* **Plug-and-Play:** Designed for user-friendliness, the device requires no complicated software installations or configurations. Simply connect it, and it seamlessly integrates with your audio setup.
* **Versatile:** The system aims to support a wide range of musical genres, allowing users to enjoy dynamic lighting effects regardless of their preferred style of music.

## Hardware Implementation

The Beat Based LED Strip Controller utilizes a Raspberry Pi 5 for audio processing and analysis, while an Arduino Uno controls the LED strip using the NeoPixel library. 

* **Raspberry Pi 5:** Handles computationally intensive tasks like audio sampling, frequency analysis, and beat detection.
* **Arduino Uno:** Directly manages the LED strip, ensuring compatibility with the NeoPixel library.
* **Serial Communication:** Facilitates seamless coordination between the Pi 5 and Arduino Uno for real-time performance and control.

## Software Implementation

The project employs Python libraries:

* **PyAudio:** Captures real-time audio samples.
* **NumPy:** Performs efficient numerical processing, including FFT analysis for frequency component identification.
* **NeoPixel:** Controls the LED strip, mapping audio features to lighting attributes like brightness and color.

## Challenges and Solutions

* **Compatibility:** The NeoPixel library's incompatibility with the Raspberry Pi 5 was addressed by leveraging the strengths of both devices. The Pi 5 handles heavy computation, while the Arduino manages the LED strip.
* **Accuracy:** Translating musical nuances into light patterns can be challenging, especially with genres featuring dominant basslines. The project is actively exploring alternative beat detection methods and refining algorithms to enhance accuracy and responsiveness across different musical styles.

## Current Progress and Future Goals

The current system successfully demonstrates the core functionality of synchronizing the strip's brightness with the music's tempo. Future goals include:

* Adding support for middle and high frequencies for a more comprehensive audio-visual experience.
* Further refining beat detection algorithms to improve accuracy and responsiveness across various musical genres.
* Minimizing the need for calibration to ensure a seamless and captivating experience for users, regardless of the audio source or genre.

## Get Started

1. Clone this repository.
2. Install the required libraries: `pip install pyaudio numpy adafruit-circuitpython-neopixel`
3. Connect your hardware as shown in the system schematic.
4. Upload the Arduino sketch to your Arduino Uno.
5. Run the Python script on your Raspberry Pi 5.

**Note:** Detailed instructions and troubleshooting tips will be added in future updates.
## Details
* For further explanation of the project and how everything works, visit https://sites.google.com/view/rishi-tirumala/projects?authuser=0.
## Contributions

Contributions are welcome! Feel free to open issues or submit pull requests to help improve this project.
   

## Acknowledgments

* Inspiration drawn from the magic of live concert lighting.
* Gratitude to the open-source community for providing valuable tools and libraries.

Let's bring the concert experience to your home!
