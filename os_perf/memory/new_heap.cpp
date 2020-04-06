/*****************************************
 *   Copyright (C) 2020 All rights reserved.
 *   File: new_heap.cpp
 *   Auth: LiuLang
 *   Mail: datuhao@foxmail.com
 *   Date: 2020-04-05 17:41
 *   Desc: 
 *****************************************/


#include <stdio.h>
#include <memory.h>
#include "../utils/time_utls.h"

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>


int arr_size[]= {550, 550, 576, 576, 550, 576, 550, 550, 550, 550}; 

int main(int argc, char *argv[])
{
	const std::string cpp_str = R"_LINE_("str Another string object, whose value is either copied or acquired.
		A value of string::npos indicates all characters until the end of str.
The function template argument InputIterator shall be an input iterator type that points to elements of a type convertible to char.
If InputIterator is an integral type, the arguments are casted to the proper types so that signature (5) is used instead.
il
An initializer_list object.
These objects are automatically constructed from initializer list declarators.

size_t is an unsigned integral type.")_LINE_";


	int mem_size = 64;
	bool use_mem = false;
	const char * buf_use = cpp_str.c_str();
	printf("cccccccccc:%u\n", cpp_str.size());
	bool del_mem = false;
	int new_times = 1000000;
	if(argc >= 2)
		mem_size = atoi(argv[1]);	
	if(argc > 2)
		use_mem = true;
	if(argc > 3)
		del_mem = true;


	std::vector<std::string> v_str(new_times);
	printf("|size\t|times\t\t|copy\t|delete\t|times use\t|\n"); 
	for(int j = 0; j<sizeof(arr_size)/sizeof(int); j++)
	{
		mem_size = arr_size[j];
		uint64_t ts = dsn_now_ms();

		for(int i = 0; i<new_times; i++)
		{
			if(0)
				v_str[i] = std::to_string(i) + cpp_str;
			else
			{
			char *buf = new char[mem_size];

			//if(use_mem)
			//	memcpy(buf, (cpp_str+std::to_string(i)).c_str(), 550);

			if(del_mem)
				delete [] buf;
			}
		}

		uint64_t ts1 = dsn_now_ms();

		//printf("| bufsize:%d\t | buf copy:%s | buf delete:%s | times use:%lu\t |\n", mem_size, 
		printf("|%d\t|%d\t|%s\t|%s\t|%lu\t|\n", mem_size, new_times,
				(use_mem ? "true" : "false"), (del_mem ? "true" : "false"), ts1 - ts);
	}

	sleep(10000);

	return 0;
}
