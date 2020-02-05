#define WIFI_SSID "[Your WiFi SSID]"
#define WIFI_PWD "[Your WiFi Password]"

#define NTP_SERVER "[Your region].pool.ntp.org"

#define DEVICE_LOCATION "[Your device location - eg Garage]"

#define DEEP_SLEEP_IN_SECONDS 0
#define PUBLISH_RATE_IN_SECONDS 60

#define IOTHUB_CONNECTION_STRING "[Your Azure IoT Hub or Azure IoT Central Connection String]"

/*
Define you sensor type.
#define FAKESENSOR
#define SHT30
#define BMP180
#define BME280
#define BMP280
#define DHTSENSOR
*/

#define BMP280

/* 
 http://hassansin.github.io/certificate-pinning-in-nodejs for information on generating fingerprint. From Ubuntu or Ubuntu subsystem on Windows 10
 
echo -n | openssl s_client -connect saas-iothub-8135cd3b-f33a-4002-a44a-7ca5961b00b6.azure-devices.net:443 | sed -ne '/-BEGIN CERTIFICATE-/,/-END CERTIFICATE-/p' | openssl x509 -noout -fingerprint
*/

#define IOTHUB_CERTIFICATE_FINGERPRINT "95:B4:61:DF:90:D9:D7:1D:15:22:D8:DB:2E:F1:7D:BC:F4:BB:41:D2"
// #define IOTHUB_CERTIFICATE_FINGERPRINT ""
