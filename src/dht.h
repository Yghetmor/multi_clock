#ifndef _DHT_
#define _DHT_

struct dht11_data {
    char hum_integral;
    char hum_decimal;
    char temp_integral;
    char temp_decimal;
    char checksum;
};

union dht11 {
    struct dht11_data data;
    char bytes[5];
};

int read_temp_hum(union dht11 *output);

#endif // !_DHT_
