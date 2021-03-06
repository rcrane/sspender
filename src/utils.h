/*
 * Copyright (C) 2016 Mountassir El Hafi, (mountassirbillah1@gmail.com)
 *
 * utils.h: Part of sspender
 *
 * sspender is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * sspender is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with sspender.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef UTILS_H_
#define UTILS_H_

#include <vector>
#include <sstream>
#include <cstdlib>
#include <stdio.h>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <cstring>
#include <ctime>
#include <chrono>
#include <cmath>

using namespace std;

typedef std::chrono::high_resolution_clock Clock;
typedef std::chrono::time_point<std::chrono::system_clock> TimePoint;

struct CpuCfg
{
	string cpuName;
	int cpu_idle_load_threshold;
	int cpu_idle_time_threshold;
};

struct DiskCfg
{
	string diskName;
	string diskUUID;
	int disk_idle_load_threshold;
	int disk_idle_time_threshold;
	bool spinDown;
};

struct DeviceUsage
{
	double load;

	void reset()
	{
		load = 0;
	}
};

struct DiskStats
{
	// double num_r_io_processed;  //number of read I/Os processed
	// double num_r_io_merged;     //number of read I/Os merged
	double num_r_sectors;       //number of sectors read
	// double time_r_ticks;        //total wait time for read requests
	// double num_w_io_processed;  //number of write I/Os processed
	// double num_w_io_merged;     //number of write I/Os merged
	double num_w_sectors;       //number of sectors written
	// double time_w_ticks;        //total wait time for write requests
	// double num_in_flight;       //number of I/Os currently in flight
	double time_io_ticks;       //total time this block device has been active
	// double time_in_queue;       //total wait for all requests
};

bool convertTimeToMinutes(string time, double *totalMinutes);
void getCurremtTimeInMinutes(double *totalMinutes);
bool uuidToDiskName(const string &uuid, string *diskName);
void printHeaderMessage(const string &message, bool logTime);
void splitByEmptySpace(const string &input, vector<string> *output);
bool runSystemCommand(const string &command, vector<string> *output = NULL);
double roundValue(double value);
double getMinutesDuration(const TimePoint& startTime);
string trimString(string input);
string charTostring(const char *input);
void splitStringByDelimiter(vector<string> *output,
		                    const string &input,
		                    const string &delimiter);
void parseFile(const string & fileName, vector<string>* fileOutput);
void parseFile(ifstream &file, vector<string>* fileOutput);
bool parentDiskOfBlockDevice(const string &blockDevice, string *diskName);
string getCurrentDateTime();

#endif
