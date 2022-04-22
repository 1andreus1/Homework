#include <iostream>
#include <boost/asio.hpp>
#include <thread>

void write(boost::asio::ip::tcp::socket& socket, std::string user_name)
{
	std::string message;
	while (true) {
		std::getline(std::cin, message);
		boost::asio::write(socket, boost::asio::buffer(user_name + " " + message + "!"));
	}
}

void read(boost::asio::ip::tcp::socket& socket)
{
	while (true)
	{
		boost::asio::streambuf buffer;
		boost::asio::read_until(socket, buffer, '!');
		std::string message;
		std::istream input_stream(&buffer);
		std::getline(input_stream, message, '!');
		std::cout << message << std::endl;
	}
}

void run(const std::string& user_name)
{
	const std::size_t size = 30;
	auto port = 3333;
	boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::address_v4::any(), port);
	//std::string raw_ip_address = "127.0.0.1";
	//boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::address::from_string(raw_ip_address), port);
	boost::asio::io_service io_service;
	boost::asio::ip::tcp::acceptor acceptor(io_service, endpoint.protocol());
	acceptor.bind(endpoint);
	acceptor.listen(size);
	boost::asio::ip::tcp::socket socket(io_service);
	acceptor.accept(socket);

	auto reader = std::thread([&socket]() {read(socket);});
	write(socket,user_name);

	reader.join();
}


int main(int argc, char** argv)
{
	system("chcp 1251");
	std::string user_name;
	std::cout << "Enter your name: ";
	std::getline(std::cin, user_name);
	run(user_name);

	system("pause");
	return EXIT_SUCCESS;
}