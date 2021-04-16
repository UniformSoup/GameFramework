#pragma once
#include <chrono>

namespace Timing
{
	using namespace std::chrono;

	/* A clock class for getting the elapsed time */
	class Clock
	{
		high_resolution_clock::time_point start;
	public:
		Clock() { start = high_resolution_clock::now(); }
		/* Returns the elapsed time since it was last called */
		inline high_resolution_clock::duration operator()()
		{
			auto duration = (high_resolution_clock::now() - start);
			start = high_resolution_clock::now();
			return duration;
		}
	};

	/* A timer class */
	class Timer
	{
		high_resolution_clock::time_point start, stop;
		bool isRunning = false;
	public:
		Timer() { stop = start = high_resolution_clock::now(); };
		inline high_resolution_clock::duration operator()() const { return isRunning ? (high_resolution_clock::now() - start) : (stop - start); }
		inline void restart() { start = high_resolution_clock::now(); isRunning = true; };
		inline void start() { if (!isRunning) { start = high_resolution_clock::now(); isRunning = true; } };
		inline void stop() { if (isRunning) { stop = high_resolution_clock::now(); isRunning = false; } };
		inline bool running() const { return isRunning; };
	};
}