# Air Quality Monitoring System

This project utilizes an ESP8266 microcontroller along with an MQ135 gas sensor to monitor air quality. The data is then sent to ThingSpeak for visualization and analysis.

## Getting Started

To get started with this project, you'll need the following components:

- ESP8266 microcontroller
- MQ135 gas sensor
- WiFi connection
- ThingSpeak account

### Installation

1. Connect the MQ135 sensor to the A0 pin of the ESP8266.
2. Update the `apiKey`, `ssid`, and `pass` variables in the code with your own ThingSpeak API key and WiFi credentials.
3. Upload the provided code to your ESP8266 microcontroller.

### Usage

Once the code is uploaded and the connections are set up:

1. Power on the ESP8266.
2. The device will connect to your WiFi network.
3. It will start monitoring air quality and send the data to ThingSpeak at regular intervals.

## Contributing

Contributions are welcome! If you'd like to contribute to this project, feel free to fork this repository and submit a pull request.

## License

This project is licensed under the [MIT License](LICENSE).

