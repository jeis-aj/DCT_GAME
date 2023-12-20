#include <iostream>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <cstdlib>
#include <cstring>
std::string secretMsg = "shot3";

int main() {
    // Open the UART port
    int uart_fd = open("/dev/ttyACM0", O_RDWR | O_NOCTTY | O_NDELAY);
    
    if (uart_fd == -1) {
        std::cerr << "Error opening UART." << std::endl;
        return -1;
    }

    // Configure the UART settings
    struct termios uart_config;
    tcgetattr(uart_fd, &uart_config);

    // Set baud rate
    cfsetispeed(&uart_config, B115200);
    cfsetospeed(&uart_config, B115200);

    // 8N1 (8 data bits, no parity, 1 stop bit)
    uart_config.c_cflag &= ~PARENB;
    uart_config.c_cflag &= ~CSTOPB;
    uart_config.c_cflag &= ~CSIZE;
    uart_config.c_cflag |= CS8;

    // Apply settings
    tcsetattr(uart_fd, TCSANOW, &uart_config);

    // Continuous read loop
    while ( system("mpg123 bgm.mp3 >> /dev/null 2>&1") ) {
	    int length = 255;
        char buffer[length];
        int bytesRead = read(uart_fd, buffer, sizeof(buffer));

        if (bytesRead == -1) {
		  usleep(10000);
            /* std::cerr << "Error reading from UART." << std::endl; */
            /* close(uart_fd); */
            /* return -1; */
        }

        // Display the received data
        if (bytesRead > 0) {
		  std::string msg = std::string(buffer, bytesRead) ;
            std::cout << "Received data: " << msg <<"by" << bytesRead;
		bool equal = strcmp(buffer,"shot");
		if ( !equal )
		std::cout<< ".......equalsss ..."<< std::endl;
		system("mpg123 shot.mp3 & >> /dev/null 2>&1");
        }

        // Optional: Add a delay to control the rate of reading
        usleep(100000);  // Sleep for 100,000 microseconds (0.1 seconds)
    }

    // Close the UART port (this part might not be reached in an infinite loop)
    close(uart_fd);

    return 0;
}

