#include<iostream>
#include<windows.h>
#include <chrono>
#include <thread>
#include <mutex>
#include <conio.h>
using namespace std::chrono_literals;

std::mutex m;

void ProgressBar(int i, int N) {
	std::scoped_lock lk(m);
	COORD p = { 0, i + 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
	std::cout << i << "\t" << std::this_thread::get_id() << std::endl;
	auto start = std::chrono::steady_clock::now();
	for (int j = 16; j < 35; j++) {
		COORD p = { j, i + 1};
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 255);
	    std::cout << "  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 255 + (16));
		m.unlock();
		if (i == 0) {
			std::this_thread::sleep_for(100ms);
		}
		if (i == 1) {
			std::this_thread::sleep_for(300ms);
		}
		if (i == 2) {
			std::this_thread::sleep_for(400ms);
		}
		if (i == 3) {
			std::this_thread::sleep_for(70ms);
		}
		if (i == 4) {
			std::this_thread::sleep_for(650ms);
		}
		m.lock();
	}
	auto end = std::chrono::steady_clock::now();
	auto diff = std::chrono::duration<double>(end - start);
	COORD p1 = { 40, i + 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p1);
	std::cout << diff << std::endl;
}


int main()
{

	int N = 5;
	std::thread *t = new std::thread[N];
	std::cout << "N" << "\t" << "id" << '\t' << "Progress Bar" << "\t\t" << "Time" << std::endl;
	for (size_t i = 0; i < N; i++) {
		t[i] = std::thread(ProgressBar, i, N);
	}
	for (size_t i = 0; i < N; i++) {
		t[i].join();
	}
	
}
