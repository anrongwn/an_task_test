// an_task_test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "../include/TaskCpp.h"
#include <functional>
#include <future>
#include <memory>
#include <iostream>
#include <string>
#include <thread>
#include <iterator>
#include <vector>

using namespace Cosmos;
int main()
{
	std::function<void()>fff = []() {std::cout << "ok0" << std::endl; };
	auto fff1 = []() {std::cout << "ok1" << std::endl; };
	TaskGroup task_g;
	task_g.Run(fff);
	task_g.Run(fff, fff1, []() {std::cout << "ok2" << std::endl; });
	task_g.Wait();

	
	std::vector<std::string> vStr = { R"(d:\mytest\1.txt)", R"(d:\mytest\2.txt)" ,R"(d:\mytest\3.txt)" ,\
		R"(d:\mytest\4.txt)",R"(d:\mytest\5.txt)", R"(d:\mytest\6.txt)",\
		R"(d:\mytest\7.txt)", R"(d:\mytest\8.txt)", R"(d:\mytest\9.txt)", \
		R"(d:\mytest\10.txt)", R"(d:\mytest\11.txt)", R"(d:\mytest\12.txt)", \
		R"(d:\mytest\13.txt)", R"(d:\mytest\14.txt)", R"(d:\mytest\15.txt)", \
		R"(d:\mytest\16.txt)", R"(d:\mytest\17.txt)", R"(d:\mytest\18.txt)", \
		R"(d:\mytest\19.txt)", R"(d:\mytest\20.txt)", R"(d:\mytest\21.txt)", \
		R"(d:\mytest\22.txt)", R"(d:\mytest\23.txt)", R"(d:\mytest\24.txt)", \
		R"(d:\mytest\25.txt)", R"(d:\mytest\26.txt)", R"(d:\mytest\27.txt)", \
	};
	auto hops = std::distance(vStr.begin(), vStr.end());
	auto cpus = std::thread::hardware_concurrency();
	auto blockSize = hops / cpus;
	auto last = vStr.begin();
	auto begin = vStr.begin();
	if (blockSize) {
		std::advance(last, (cpus - 1)*blockSize);
	}
	else
	{
		last = vStr.end();
		blockSize = 1;
	}

	
	auto func = [](const std::string& s) {
		std::cout << s.c_str() << std::endl;
	};

	//cpus - 1 组
	for (; begin != last; std::advance(begin, blockSize)) {
		std::for_each(begin, begin + blockSize, func);
		std::cout << "---" << std::endl;
		
	}
	std::cout << "first group end." << endl;

	//最后一组
	std::for_each(begin, vStr.end(), func);
	std::cout << "last group end." << endl;


	system("pause");
    return 0;
}

