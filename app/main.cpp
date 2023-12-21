#include <iostream>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <cstdlib>
#include <cstring>

void display(int );
std::string secretMsg = "shot3";

int score = 0;
int main() {
	// Open the UART port
	/* int uart_fd = open("/dev/ttyACM0", O_RDWR | O_NOCTTY | O_NDELAY); */
	int uart_fd = open("/dev/ttyACM0", O_RDONLY | O_NOCTTY | O_NDELAY);

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
	int length = 255;
	char buffer[length];

	std::streambuf *coutBuffer = std::cout.rdbuf();

	 system("nohup mpg123 res/bgm.mp3 &") ;

	while (1) {
    // Restore the original cout stream buffer
    std::cout.rdbuf(coutBuffer);

	int bytesRead = read(uart_fd, buffer, sizeof(buffer));
		if (bytesRead == -1) {
			usleep(10000); }
		// Display the received data
		if (bytesRead > 0) {
			if ( score > 9 ){
				display(10);
				break; }
			++score;
			display(score);
			std::string msg = std::string(buffer, bytesRead) ;
			/* std::cout << "Received data: " << msg <<"by" << bytesRead << std::flush; */
		    std::cout.rdbuf(coutBuffer);
		/* system("nohup mpg123 res/shot.mp3 & >> /dev/null 2>&1"); */
		}

		// Optional: Add a delay to control the rate of reading
		usleep(100000);  // Sleep for 100,000 microseconds (0.1 seconds)
	}
	/* system("mpg123 res/bomb.mp3 >> /dev/null 2>&1"); */

	// Close the UART port (this part might not be reached in an infinite loop)
	close(uart_fd);

	return 0;
	}

