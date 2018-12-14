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

using namespace Cosmos;
int main()
{
	std::function<void()>fff = []() {std::cout << "ok0" << std::endl; };
	auto fff1 = []() {std::cout << "ok1" << std::endl; };
	TaskGroup task_g;
	task_g.Run(fff);
	task_g.Run(fff, fff1, []() {std::cout << "ok2" << std::endl; });
	task_g.Wait();

	system("pause");
    return 0;
}

