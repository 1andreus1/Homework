#include <iostream>
#include <boost/asio.hpp>
#include <thread>


class Chat_Server
{
public:
	Chat_Server(const std::string& m_user_name) : user_name(m_user_name), exit_flag(false),
		endpoint(boost::asio::ip::address_v4::any(), port),
		io_service(),
		acceptor(io_service, endpoint.protocol()),
		socket(io_service)
	{
		acceptor.bind(endpoint);
		acceptor.listen(size);
		acceptor.accept(socket);
	}

public:
	void run()
	{
		auto reader = std::thread([this]() {read(socket); });
		write(socket, user_name);
		reader.join();
		std::cout << "Chat stopped" << std::endl;
	}

private:
	void write(boost::asio::ip::tcp::socket& socket, std::string user_name)
	{
		std::string message;
		while (true) {
			if (exit_flag)
			{
				exit_flag = true;
				break;
			}
			std::getline(std::cin, message);
			boost::asio::write(socket, boost::asio::buffer(user_name + " " + message + "!"));
			if (message == "#" || exit_flag)
			{
				exit_flag = true;
				break;
			}
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
			if (message.back() == '#' || exit_flag)
			{
				exit_flag = true;
				break;
			}
			else
			{
				std::cout << message << std::endl;
			}
		}
	}

private:
	int port = 3333;
	const std::size_t size = 30;
	std::string user_name;
	std::atomic < bool > exit_flag;
	boost::asio::ip::tcp::endpoint endpoint;
	boost::asio::io_service io_service;
	boost::asio::ip::tcp::acceptor acceptor;
	boost::asio::ip::tcp::socket socket;
};




int main(int argc, char** argv)
{
	system("chcp 1251");
	std::string user_name;
	std::cout << "Server" << std::endl;
	std::cout << "Enter your name: ";
	std::getline(std::cin, user_name);
	Chat_Server Chat(user_name);
	Chat.run();
	system("pause");
	return EXIT_SUCCESS;
}